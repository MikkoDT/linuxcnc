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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "opengl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout;
    QDoubleSpinBox *doubleSpinBox_vm;
    QDoubleSpinBox *doubleSpinBox_tarpos;
    QLabel *label_8;
    QPushButton *pushButton_run;
    QLabel *label_curacc;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_a;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_curpos;
    QLabel *label_4;
    QPushButton *pushButton_stop;
    QLabel *label_2;
    QLabel *label_curvel;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_dv;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_ve;
    opengl *openGLWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(797, 596);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(textBrowser, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        doubleSpinBox_vm = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_vm->setObjectName(QString::fromUtf8("doubleSpinBox_vm"));
        doubleSpinBox_vm->setSingleStep(1.000000000000000);
        doubleSpinBox_vm->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_vm, 5, 1, 1, 1);

        doubleSpinBox_tarpos = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_tarpos->setObjectName(QString::fromUtf8("doubleSpinBox_tarpos"));
        doubleSpinBox_tarpos->setMinimum(-10000.000000000000000);
        doubleSpinBox_tarpos->setMaximum(10000.000000000000000);
        doubleSpinBox_tarpos->setSingleStep(0.100000000000000);
        doubleSpinBox_tarpos->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_tarpos, 1, 1, 1, 1);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        pushButton_run = new QPushButton(centralwidget);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));

        gridLayout->addWidget(pushButton_run, 6, 0, 1, 1);

        label_curacc = new QLabel(centralwidget);
        label_curacc->setObjectName(QString::fromUtf8("label_curacc"));

        gridLayout->addWidget(label_curacc, 9, 1, 1, 1);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        doubleSpinBox_a = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_a->setObjectName(QString::fromUtf8("doubleSpinBox_a"));
        doubleSpinBox_a->setSingleStep(0.100000000000000);
        doubleSpinBox_a->setValue(2.000000000000000);

        gridLayout->addWidget(doubleSpinBox_a, 3, 1, 1, 1);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_curpos = new QLabel(centralwidget);
        label_curpos->setObjectName(QString::fromUtf8("label_curpos"));

        gridLayout->addWidget(label_curpos, 7, 1, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 0, 1, 1);

        pushButton_stop = new QPushButton(centralwidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout->addWidget(pushButton_stop, 6, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 7, 0, 1, 1);

        label_curvel = new QLabel(centralwidget);
        label_curvel->setObjectName(QString::fromUtf8("label_curvel"));

        gridLayout->addWidget(label_curvel, 8, 1, 1, 1);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        doubleSpinBox_dv = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_dv->setObjectName(QString::fromUtf8("doubleSpinBox_dv"));
        doubleSpinBox_dv->setValue(10.000000000000000);

        gridLayout->addWidget(doubleSpinBox_dv, 4, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 0, 1, 1);

        doubleSpinBox_ve = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_ve->setObjectName(QString::fromUtf8("doubleSpinBox_ve"));
        doubleSpinBox_ve->setMinimum(-100.000000000000000);

        gridLayout->addWidget(doubleSpinBox_ve, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 3, 1, 1, 1);

        openGLWidget = new opengl(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(openGLWidget->sizePolicy().hasHeightForWidth());
        openGLWidget->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(openGLWidget, 0, 0, 4, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 797, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "sc pid", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans Mono'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This example shows </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">a live pid controller.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "tarvel", nullptr));
        pushButton_run->setText(QCoreApplication::translate("MainWindow", "run", nullptr));
        label_curacc->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "curvel", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "dv", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "tarpos", nullptr));
        label_curpos->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "vm", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "curpos", nullptr));
        label_curvel->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "curacc", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
