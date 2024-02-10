#include "rxgraph.h"
#include <iostream>
#include <QProcess>
#include <QMessageBox>
#include <iostream>
#include<QTimer>
#include <QProcess>
#include <QStringList>
#include <QRegularExpression>
#include <QVector>
#include <QWidget>
#include <QVector>
#include <QPointF>
#include <QPainter>

using namespace std;


QVector<int> rxPacketsArray1;
QVector<int> txPacketsArray1;
int prevRx = 0;
int prevTx = 0;
int counter;

QVector<QPointF> DataPoints;
QVector<QPointF> DataPointsTx;

rxgraph::rxgraph(QWidget *parent)
    : QDialog(parent), ui(new Ui::rxgraph)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateNetworkData()));
    timer->start(2000);

}



void rxgraph::updateNetworkData() {
    QProcess process;
    process.start("bash", QStringList() << "-c" << "ip -s link show");
    process.waitForFinished();

    QString output = process.readAllStandardOutput();
    QStringList lines = output.split("\n");

    QString statistics = "";
    for (int i = 0; i < lines.count(); i++) {
        if (lines[i].contains("RX:") && i + 1 < lines.count()) {
            QStringList rxWords = lines[i+1].trimmed().split(QRegularExpression("\\s+"));
            QStringList txWords = lines[i+3].trimmed().split(QRegularExpression("\\s+"));

            if (rxWords.size() >= 2 && txWords.size() >= 2) {
                QString rxBytes = rxWords[0];
                QString txBytes = txWords[0];
                QString rxPackets = rxWords[1];
                QString txPackets = txWords[1];
                rxPacketsArray1.append(rxWords[1].toInt());
                txPacketsArray1.append(txWords[1].toInt());
                QString interface = lines[i-2].split(":")[1].trimmed();

            }
        }
    }


    int n = rxPacketsArray1.size();

    if(prevRx==0){
        prevRx = rxPacketsArray1[n-1];
        prevTx = txPacketsArray1[n-1];
        DataPoints.append(QPointF(counter,prevRx));
        DataPointsTx.append(QPointF(counter,prevTx));
        return;
    }

    int y = txPacketsArray1[n-1]-prevTx;
    int x = rxPacketsArray1[n-1]-prevRx;


    DataPoints.append(QPointF(counter,x));
    DataPointsTx.append(QPointF(counter,y));

    prevRx = rxPacketsArray1[n-1];
    prevTx = txPacketsArray1[n-1];
    counter++;


    if (counter == 100){
        DataPoints.clear();
        DataPointsTx.clear();
        counter=0;
    }

    repaint();
    QString rx = QString::number(x);
    QString tx = QString::number(y);
    ui->RxPacket->setText(rx);
    ui->TxPacket->setText(tx);
}

void rxgraph::paintEvent(QPaintEvent *event) {

    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);


    qreal maxX = 100;

    qreal maxY = 400;

    qreal scaleFactorX = width() / maxX;
    qreal scaleFactorY = height() / maxY;

    // scale painter
    painter.translate(0, height());
    painter.scale(scaleFactorX, -scaleFactorY); // Scale and flip the y-axis

    // drawing points for tx
    painter.setPen(QPen(Qt::red, 0.3));
    for (int i = 1; i<DataPoints.size(); ++i){
        painter.drawLine(DataPoints[i-1],DataPoints[i]);
    }

    // drawing points for rx
    painter.setPen(QPen(Qt::blue, 0.3));
    for (int i = 1; i<DataPointsTx.size(); ++i){
            painter.drawLine(DataPointsTx[i-1],DataPointsTx[i]);
        }

}

rxgraph::~rxgraph()
{
    delete ui;
}


void rxgraph::showWindow()
{
    this->show();
}


