#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QProcess>
#include <iostream>
#include <QRegularExpression>
#include <QtWidgets>
#include <QTimer>
#include <QPainter>
#include <QPaintEvent>
using namespace std;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    fwManager = new firewallmanager(this);
    rxManager = new rxgraph(this);


}

MainWindow::~MainWindow()
{

    delete ui;
}



void MainWindow::on_NetTrafficBtn_clicked()
{

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
                QString txPackets = txWords [1];
                QString interface = lines[i-2].split(":")[1].trimmed();
                statistics += interface + "\n" + "RX packets: " + rxPackets + "\n" + "TX packets: "+ txPackets + "\n" + "RX Bytes: " + rxBytes + "\n" + "TX Bytes: " + txBytes + "\n\n";
            }
        }
    }


    QMessageBox::information(this, "Network Traffic", statistics.isEmpty() ? "No data available." : statistics);
}





void MainWindow::countLoginAttempts(int &successful, int &unsuccessful) {
    QFile file("/var/log/auth.log");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "Failed to open auth.log.");
        return;
    }

    successful = 0;
    unsuccessful = 0;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (line.contains("pam_sm_open_session")) {
            successful++;
        } else if ((line.contains("authentication failure"))) {
            unsuccessful++;
        }
    }

    file.close();
}


void MainWindow::on_UserInfoBtn_clicked()
{
    int successful, unsuccessful;
        countLoginAttempts(successful, unsuccessful);

        QString message = QString("Successful logins: %1\nUnsuccessful logins: %2")
                          .arg(successful)
                          .arg(unsuccessful);
        QMessageBox::information(this, "Login Attempts", message);
}




void MainWindow::on_VersionCheckBtn_clicked()
{
    QProcess process;
    process.start("lsb_release -d");
    process.waitForFinished();
    QString versionOutput = process.readAllStandardOutput();


    QString versionInfo = versionOutput.split(":").last().trimmed();
    QString latestVersion = "Ubuntu 23.10";

    if(versionInfo == latestVersion) {
        QMessageBox::information(this, "Version Check", "You are running the latest version: " + versionInfo);
    } else {
        QMessageBox::warning(this, "Version Check", "You are running " + versionInfo + ". The latest version is: " + latestVersion);
    }
}


void MainWindow::on_FireWallManger_clicked()
{
        fwManager->showWindow();
}




void MainWindow::on_rxgraph_clicked()
{

    rxManager->showWindow();
}

