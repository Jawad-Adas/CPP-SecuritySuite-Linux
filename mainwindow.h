#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QTimer>
#include <QElapsedTimer>
#include "firewallmanager.h"
#include "rxgraph.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_NetTrafficBtn_clicked();

    void countLoginAttempts(int &successful, int &unsuccessful);

    void on_UserInfoBtn_clicked();

    void on_VersionCheckBtn_clicked();

    void on_FireWallManger_clicked();

    void on_rxgraph_clicked();

private:
    firewallmanager *fwManager = nullptr;

    rxgraph *rxManager = nullptr;

    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
