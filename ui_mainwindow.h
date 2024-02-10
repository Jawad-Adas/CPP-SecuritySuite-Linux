/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QPushButton *UserInfoBtn;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *VersionCheckBtn;
    QPushButton *NetTrafficBtn;
    QPushButton *FireWallManger;
    QLabel *label_5;
    QPushButton *rxgraph;
    QLabel *label_6;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 617);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 0, 461, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Yrsa"));
        font.setPointSize(36);
        font.setItalic(true);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 140, 501, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Yrsa"));
        font1.setPointSize(18);
        font1.setItalic(true);
        label_2->setFont(font1);
        UserInfoBtn = new QPushButton(centralwidget);
        UserInfoBtn->setObjectName(QString::fromUtf8("UserInfoBtn"));
        UserInfoBtn->setGeometry(QRect(620, 140, 141, 61));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 420, 501, 61));
        label_3->setFont(font1);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 330, 521, 61));
        label_4->setFont(font1);
        VersionCheckBtn = new QPushButton(centralwidget);
        VersionCheckBtn->setObjectName(QString::fromUtf8("VersionCheckBtn"));
        VersionCheckBtn->setGeometry(QRect(620, 410, 141, 61));
        NetTrafficBtn = new QPushButton(centralwidget);
        NetTrafficBtn->setObjectName(QString::fromUtf8("NetTrafficBtn"));
        NetTrafficBtn->setGeometry(QRect(620, 320, 141, 61));
        FireWallManger = new QPushButton(centralwidget);
        FireWallManger->setObjectName(QString::fromUtf8("FireWallManger"));
        FireWallManger->setGeometry(QRect(620, 230, 141, 61));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 240, 441, 61));
        label_5->setFont(font1);
        rxgraph = new QPushButton(centralwidget);
        rxgraph->setObjectName(QString::fromUtf8("rxgraph"));
        rxgraph->setGeometry(QRect(620, 500, 141, 61));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 500, 501, 61));
        label_6->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "System Security Monitor", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Show Successful and Unsuccessful Login Attempts", nullptr));
        UserInfoBtn->setText(QCoreApplication::translate("MainWindow", "User Login Info", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Show if Veresion is the Latest Version", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Shows Recived and Transmited Packets For all interfaces", nullptr));
        VersionCheckBtn->setText(QCoreApplication::translate("MainWindow", "Version Check", nullptr));
        NetTrafficBtn->setText(QCoreApplication::translate("MainWindow", "Network Traffic", nullptr));
        FireWallManger->setText(QCoreApplication::translate("MainWindow", "Firewall Manager", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Open Firewall manager to Allow/Block specific IPs", nullptr));
        rxgraph->setText(QCoreApplication::translate("MainWindow", "Show Graph", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Display Graph for Real-Time Network Traffic", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
