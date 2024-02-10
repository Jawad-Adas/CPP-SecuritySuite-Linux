#ifndef FIREWALLMANAGER_H
#define FIREWALLMANAGER_H

#include <QDialog>
#include "ui_firewallmanager.h"

class firewallmanager : public QDialog
{
    Q_OBJECT

public:
    firewallmanager(QWidget *parent = nullptr);
    ~firewallmanager();
    void showWindow();

private slots:
    void on_Allow_clicked();

    void on_Block_clicked();

    void on_ShowBlockedIP_clicked();

private:
    Ui::firewallmanager *ui;
};

#endif // FIREWALLMANAGER_H
