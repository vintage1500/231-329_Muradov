/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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
    QPushButton *get_1;
    QPushButton *get_all;
    QPushButton *update;
    QPushButton *create;
    QPushButton *delete_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        get_1 = new QPushButton(centralwidget);
        get_1->setObjectName("get_1");
        get_1->setGeometry(QRect(190, 70, 341, 51));
        get_all = new QPushButton(centralwidget);
        get_all->setObjectName("get_all");
        get_all->setGeometry(QRect(190, 140, 341, 51));
        update = new QPushButton(centralwidget);
        update->setObjectName("update");
        update->setGeometry(QRect(190, 280, 341, 51));
        create = new QPushButton(centralwidget);
        create->setObjectName("create");
        create->setGeometry(QRect(190, 210, 341, 51));
        delete_2 = new QPushButton(centralwidget);
        delete_2->setObjectName("delete_2");
        delete_2->setGeometry(QRect(190, 360, 341, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        get_1->setText(QCoreApplication::translate("MainWindow", "get 1", nullptr));
        get_all->setText(QCoreApplication::translate("MainWindow", "get all", nullptr));
        update->setText(QCoreApplication::translate("MainWindow", "update", nullptr));
        create->setText(QCoreApplication::translate("MainWindow", "create", nullptr));
        delete_2->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
