/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox_vo;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_ve;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_vm;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_a;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_jm;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_s;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(267, 275);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        doubleSpinBox_vo = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_vo->setObjectName(QString::fromUtf8("doubleSpinBox_vo"));
        doubleSpinBox_vo->setMinimum(-10000.000000000000000);
        doubleSpinBox_vo->setMaximum(10000.000000000000000);

        gridLayout->addWidget(doubleSpinBox_vo, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        doubleSpinBox_ve = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_ve->setObjectName(QString::fromUtf8("doubleSpinBox_ve"));
        doubleSpinBox_ve->setMinimum(-10000.000000000000000);
        doubleSpinBox_ve->setMaximum(10000.000000000000000);
        doubleSpinBox_ve->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_ve, 1, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        doubleSpinBox_vm = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_vm->setObjectName(QString::fromUtf8("doubleSpinBox_vm"));
        doubleSpinBox_vm->setMinimum(-10000.000000000000000);
        doubleSpinBox_vm->setMaximum(10000.000000000000000);
        doubleSpinBox_vm->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_vm, 2, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        doubleSpinBox_a = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_a->setObjectName(QString::fromUtf8("doubleSpinBox_a"));
        doubleSpinBox_a->setMinimum(-10000.000000000000000);
        doubleSpinBox_a->setMaximum(10000.000000000000000);
        doubleSpinBox_a->setValue(2.000000000000000);

        gridLayout->addWidget(doubleSpinBox_a, 3, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        doubleSpinBox_jm = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_jm->setObjectName(QString::fromUtf8("doubleSpinBox_jm"));
        doubleSpinBox_jm->setMinimum(-10000.000000000000000);
        doubleSpinBox_jm->setMaximum(10000.000000000000000);
        doubleSpinBox_jm->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_jm, 4, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        doubleSpinBox_s = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_s->setObjectName(QString::fromUtf8("doubleSpinBox_s"));
        doubleSpinBox_s->setMinimum(-10000.000000000000000);
        doubleSpinBox_s->setMaximum(10000.000000000000000);
        doubleSpinBox_s->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_s, 5, 1, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 6, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 267, 22));
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
        label->setText(QCoreApplication::translate("MainWindow", "vo", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ve", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "vm", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "jm", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "calculate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
