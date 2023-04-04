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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "opengl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QPushButton *pushButton_run_while;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *doubleSpinBox_ve;
    QDoubleSpinBox *doubleSpinBox_vo;
    QLabel *label_5;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label;
    QPushButton *pushButton_thread_1;
    QDoubleSpinBox *doubleSpinBox_ace;
    opengl *openGLWidget;
    QDoubleSpinBox *doubleSpinBox_a;
    QDoubleSpinBox *doubleSpinBox_s;
    QLabel *label_3;
    QPushButton *pushButton_thread_2;
    QPushButton *pushButton_run;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_acs;
    QDoubleSpinBox *doubleSpinBox_vm;
    QDoubleSpinBox *doubleSpinBox_jm;
    QPushButton *pushButton_short_segment;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(777, 556);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        pushButton_run_while = new QPushButton(centralwidget);
        pushButton_run_while->setObjectName(QString::fromUtf8("pushButton_run_while"));

        gridLayout->addWidget(pushButton_run_while, 10, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 181, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 14, 3, 1, 1);

        doubleSpinBox_ve = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_ve->setObjectName(QString::fromUtf8("doubleSpinBox_ve"));
        doubleSpinBox_ve->setMinimum(-100.000000000000000);

        gridLayout->addWidget(doubleSpinBox_ve, 2, 3, 1, 1);

        doubleSpinBox_vo = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_vo->setObjectName(QString::fromUtf8("doubleSpinBox_vo"));
        doubleSpinBox_vo->setMinimum(-100.000000000000000);

        gridLayout->addWidget(doubleSpinBox_vo, 1, 3, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 2, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 2, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 8, 2, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 2, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 2, 1, 1);

        pushButton_thread_1 = new QPushButton(centralwidget);
        pushButton_thread_1->setObjectName(QString::fromUtf8("pushButton_thread_1"));

        gridLayout->addWidget(pushButton_thread_1, 11, 3, 1, 1);

        doubleSpinBox_ace = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_ace->setObjectName(QString::fromUtf8("doubleSpinBox_ace"));
        doubleSpinBox_ace->setSingleStep(1.000000000000000);
        doubleSpinBox_ace->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_ace, 8, 3, 1, 1);

        openGLWidget = new opengl(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(openGLWidget, 0, 0, 15, 1);

        doubleSpinBox_a = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_a->setObjectName(QString::fromUtf8("doubleSpinBox_a"));
        doubleSpinBox_a->setSingleStep(0.100000000000000);
        doubleSpinBox_a->setValue(1.000000000000000);

        gridLayout->addWidget(doubleSpinBox_a, 3, 3, 1, 1);

        doubleSpinBox_s = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_s->setObjectName(QString::fromUtf8("doubleSpinBox_s"));
        doubleSpinBox_s->setMinimum(-10000.000000000000000);
        doubleSpinBox_s->setMaximum(10000.000000000000000);
        doubleSpinBox_s->setSingleStep(0.100000000000000);
        doubleSpinBox_s->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_s, 0, 3, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 2, 1, 1);

        pushButton_thread_2 = new QPushButton(centralwidget);
        pushButton_thread_2->setObjectName(QString::fromUtf8("pushButton_thread_2"));

        gridLayout->addWidget(pushButton_thread_2, 12, 3, 1, 1);

        pushButton_run = new QPushButton(centralwidget);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));

        gridLayout->addWidget(pushButton_run, 9, 3, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 7, 2, 1, 1);

        doubleSpinBox_acs = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_acs->setObjectName(QString::fromUtf8("doubleSpinBox_acs"));
        doubleSpinBox_acs->setSingleStep(1.000000000000000);
        doubleSpinBox_acs->setValue(0.000000000000000);

        gridLayout->addWidget(doubleSpinBox_acs, 7, 3, 1, 1);

        doubleSpinBox_vm = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_vm->setObjectName(QString::fromUtf8("doubleSpinBox_vm"));
        doubleSpinBox_vm->setSingleStep(1.000000000000000);
        doubleSpinBox_vm->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_vm, 5, 3, 1, 1);

        doubleSpinBox_jm = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_jm->setObjectName(QString::fromUtf8("doubleSpinBox_jm"));
        doubleSpinBox_jm->setMinimum(0.100000000000000);
        doubleSpinBox_jm->setSingleStep(0.100000000000000);
        doubleSpinBox_jm->setValue(0.500000000000000);

        gridLayout->addWidget(doubleSpinBox_jm, 4, 3, 1, 1);

        pushButton_short_segment = new QPushButton(centralwidget);
        pushButton_short_segment->setObjectName(QString::fromUtf8("pushButton_short_segment"));

        gridLayout->addWidget(pushButton_short_segment, 13, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 777, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ruckig gui", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "vo", nullptr));
        pushButton_run_while->setText(QCoreApplication::translate("MainWindow", "run_while", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "jm", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "vm", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "ace", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "ve", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "s", nullptr));
        pushButton_thread_1->setText(QCoreApplication::translate("MainWindow", "thread 1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
        pushButton_thread_2->setText(QCoreApplication::translate("MainWindow", "thread 2", nullptr));
        pushButton_run->setText(QCoreApplication::translate("MainWindow", "run", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "acs", nullptr));
        pushButton_short_segment->setText(QCoreApplication::translate("MainWindow", "short segment", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
