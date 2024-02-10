/********************************************************************************
** Form generated from reading UI file 'firewallmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIREWALLMANAGER_H
#define UI_FIREWALLMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_firewallmanager
{
public:
    QLabel *Title;
    QPushButton *Block;
    QPushButton *Allow;
    QLineEdit *IPaddressIn;
    QPushButton *ShowBlockedIP;
    QLabel *Instruction;
    QLabel *DispBlockIP;

    void setupUi(QDialog *firewallmanager)
    {
        if (firewallmanager->objectName().isEmpty())
            firewallmanager->setObjectName(QString::fromUtf8("firewallmanager"));
        firewallmanager->resize(540, 413);
        Title = new QLabel(firewallmanager);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(100, 10, 331, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Yrsa"));
        font.setPointSize(36);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        Title->setFont(font);
        Block = new QPushButton(firewallmanager);
        Block->setObjectName(QString::fromUtf8("Block"));
        Block->setGeometry(QRect(240, 200, 80, 26));
        Allow = new QPushButton(firewallmanager);
        Allow->setObjectName(QString::fromUtf8("Allow"));
        Allow->setGeometry(QRect(100, 200, 80, 26));
        IPaddressIn = new QLineEdit(firewallmanager);
        IPaddressIn->setObjectName(QString::fromUtf8("IPaddressIn"));
        IPaddressIn->setGeometry(QRect(140, 130, 141, 41));
        ShowBlockedIP = new QPushButton(firewallmanager);
        ShowBlockedIP->setObjectName(QString::fromUtf8("ShowBlockedIP"));
        ShowBlockedIP->setGeometry(QRect(360, 290, 141, 41));
        Instruction = new QLabel(firewallmanager);
        Instruction->setObjectName(QString::fromUtf8("Instruction"));
        Instruction->setGeometry(QRect(10, 70, 511, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yrsa Medium"));
        font1.setPointSize(16);
        font1.setItalic(true);
        Instruction->setFont(font1);
        DispBlockIP = new QLabel(firewallmanager);
        DispBlockIP->setObjectName(QString::fromUtf8("DispBlockIP"));
        DispBlockIP->setGeometry(QRect(50, 280, 251, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Yrsa Medium"));
        font2.setPointSize(18);
        font2.setItalic(true);
        DispBlockIP->setFont(font2);

        retranslateUi(firewallmanager);

        QMetaObject::connectSlotsByName(firewallmanager);
    } // setupUi

    void retranslateUi(QDialog *firewallmanager)
    {
        firewallmanager->setWindowTitle(QCoreApplication::translate("firewallmanager", "Dialog", nullptr));
        Title->setText(QCoreApplication::translate("firewallmanager", "Firewall Manager", nullptr));
        Block->setText(QCoreApplication::translate("firewallmanager", "Block", nullptr));
        Allow->setText(QCoreApplication::translate("firewallmanager", "Allow", nullptr));
        ShowBlockedIP->setText(QCoreApplication::translate("firewallmanager", "Display Blocked IPs", nullptr));
        Instruction->setText(QCoreApplication::translate("firewallmanager", "Enter the IP you wish to Allow/Block, then press Allow/Block:", nullptr));
        DispBlockIP->setText(QCoreApplication::translate("firewallmanager", "To display all blocked IPs:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class firewallmanager: public Ui_firewallmanager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIREWALLMANAGER_H
