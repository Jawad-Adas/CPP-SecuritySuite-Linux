#include "firewallmanager.h"
#include <iostream>
#include <QProcess>
#include <QMessageBox>

using namespace std;

firewallmanager::firewallmanager(QWidget *parent)
    : QDialog(parent), ui(new Ui::firewallmanager)
{
    ui->setupUi(this);
}

firewallmanager::~firewallmanager()
{
    delete ui;
}

void firewallmanager::showWindow()
{
    this->show();
}

void firewallmanager::on_Allow_clicked()
{

    QString ipAddress = ui->IPaddressIn->text();

    //validate ip format
    if (!ipAddress.isEmpty()) {
        QString command = "iptables -D INPUT -s " + ipAddress + " -j DROP";

        // Use pkexec to run the command with elevated privileges
        QString fullCommand = "pkexec bash -c \"" + command + "\"";


        QProcess process;
        process.start(fullCommand);
        process.waitForFinished();

        if (process.exitCode() == 0) {
            QMessageBox::information(this, "Success", "IP Address allowed successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Failed to allow IP Address. Ensure you have the necessary permissions and the IP is currently blocked.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid IP Address.");
    }
}



void firewallmanager::on_Block_clicked()
{

    QString ipAddress = ui->IPaddressIn->text();

    if (!ipAddress.isEmpty()) {
        // Comman to block IP
        QString command = "iptables -A INPUT -s " + ipAddress + " -j DROP";

        // pkexec to give privileges
        QString fullCommand = "pkexec bash -c \"" + command + "\"";

        QProcess process;
        process.start(fullCommand);
        process.waitForFinished();

        if (process.exitCode() == 0) {
            QMessageBox::information(this, "Success", "IP Address blocked successfully.");
        } else {
            QMessageBox::warning(this, "Error", "Failed to block IP Address. Ensure you have the necessary permissions.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Please enter a valid IP Address.");
    }
}


void firewallmanager::on_ShowBlockedIP_clicked()
{
        QProcess process;
        //pkexec to give permission
        process.start("pkexec iptables -L INPUT -v -n");
        process.waitForFinished();

        // error checking
        if (process.error() != QProcess::UnknownError) {
            QMessageBox::critical(this, "Error", "Failed to execute iptables command.");
            return;
        }

        QString output = process.readAllStandardOutput();
        if (output.isEmpty()) {
            QMessageBox::critical(this, "Error", "No output from iptables command. Ensure you have the necessary permissions.");
            return;
        }

        QStringList lines = output.split("\n");
        QString blockedIPs = "Blocked IPs:\n";

        for (const QString &line : lines) {
            if (line.contains("DROP")) {
                QStringList fields = line.split(QRegExp("\\s+"), Qt::SkipEmptyParts);
                // Extracting the source IP address
                if (fields.size() > 7) {
                    QString sourceIP = fields[7];
                    blockedIPs += sourceIP + "\n";
                }
            }
        }

        if (blockedIPs == "Blocked IPs:\n") {
            blockedIPs += "None";
        }

        QMessageBox::information(this, "Blocked IP Addresses", blockedIPs);
}


