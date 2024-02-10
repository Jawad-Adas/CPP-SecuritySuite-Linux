#ifndef RXGRAPH_H
#define RXGRAPH_H
#include <QDialog>
#include "ui_rxgraph.h"
#include <QPaintEvent>

class rxgraph: public QDialog
{
    Q_OBJECT

public:
    rxgraph(QWidget *parent = nullptr);
    ~rxgraph();
    void showWindow();

private slots:

    void updateNetworkData();

    void paintEvent(QPaintEvent *event);

private:
    Ui::rxgraph *ui;
};

#endif // RXGRAPH_H
