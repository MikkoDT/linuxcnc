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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_jog_y_plus;
    QPushButton *pushButton_free;
    QPushButton *pushButton_jog_y_min;
    QPushButton *pushButton_auto;
    QLabel *label_3;
    QPushButton *pushButton_home_z;
    QPushButton *pushButton_spindle_on_cw;
    QPushButton *pushButton_spindle_off;
    QPushButton *pushButton_resume;
    QLabel *label_active_scodes;
    QPushButton *pushButton_reverse;
    QPushButton *pushButton_jog_x_plus;
    QPushButton *pushButton_estop;
    QPushButton *pushButton_machine_on;
    QPushButton *pushButton_jog_z_min;
    QLabel *label_2;
    QLabel *label_active_gcodes;
    QLabel *label;
    QPushButton *pushButton_jog_x_min;
    QPushButton *pushButton_load;
    QPushButton *pushButton_coord;
    QPushButton *pushButton_run;
    QPushButton *pushButton_home_y;
    QLabel *label_active_mcodes;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_home_x;
    QPushButton *pushButton_manual;
    QLabel *label_4;
    QPushButton *pushButton_spindle_on_ccw;
    QPushButton *pushButton_mdi;
    QPushButton *pushButton_teleop;
    QPushButton *pushButton_pause;
    QLabel *label_active_fcodes;
    QPushButton *pushButton_jog_z_plus;
    QPushButton *pushButton_stop;
    QLabel *label_5;
    QScrollBar *horizontalScrollBar_jog_speed;
    QLabel *label_jog_speed;
    QLabel *label_mode;
    QPushButton *pushButton_home_all;
    QPushButton *pushButton_unhome_all;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(752, 490);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 601, 458));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_jog_y_plus = new QPushButton(layoutWidget);
        pushButton_jog_y_plus->setObjectName(QString::fromUtf8("pushButton_jog_y_plus"));

        gridLayout->addWidget(pushButton_jog_y_plus, 9, 1, 1, 1);

        pushButton_free = new QPushButton(layoutWidget);
        pushButton_free->setObjectName(QString::fromUtf8("pushButton_free"));

        gridLayout->addWidget(pushButton_free, 2, 2, 1, 1);

        pushButton_jog_y_min = new QPushButton(layoutWidget);
        pushButton_jog_y_min->setObjectName(QString::fromUtf8("pushButton_jog_y_min"));

        gridLayout->addWidget(pushButton_jog_y_min, 9, 0, 1, 1);

        pushButton_auto = new QPushButton(layoutWidget);
        pushButton_auto->setObjectName(QString::fromUtf8("pushButton_auto"));

        gridLayout->addWidget(pushButton_auto, 4, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 15, 0, 1, 1);

        pushButton_home_z = new QPushButton(layoutWidget);
        pushButton_home_z->setObjectName(QString::fromUtf8("pushButton_home_z"));

        gridLayout->addWidget(pushButton_home_z, 3, 2, 1, 1);

        pushButton_spindle_on_cw = new QPushButton(layoutWidget);
        pushButton_spindle_on_cw->setObjectName(QString::fromUtf8("pushButton_spindle_on_cw"));

        gridLayout->addWidget(pushButton_spindle_on_cw, 5, 0, 1, 1);

        pushButton_spindle_off = new QPushButton(layoutWidget);
        pushButton_spindle_off->setObjectName(QString::fromUtf8("pushButton_spindle_off"));

        gridLayout->addWidget(pushButton_spindle_off, 5, 2, 1, 1);

        pushButton_resume = new QPushButton(layoutWidget);
        pushButton_resume->setObjectName(QString::fromUtf8("pushButton_resume"));

        gridLayout->addWidget(pushButton_resume, 6, 2, 1, 1);

        label_active_scodes = new QLabel(layoutWidget);
        label_active_scodes->setObjectName(QString::fromUtf8("label_active_scodes"));

        gridLayout->addWidget(label_active_scodes, 15, 1, 1, 2);

        pushButton_reverse = new QPushButton(layoutWidget);
        pushButton_reverse->setObjectName(QString::fromUtf8("pushButton_reverse"));

        gridLayout->addWidget(pushButton_reverse, 6, 3, 1, 1);

        pushButton_jog_x_plus = new QPushButton(layoutWidget);
        pushButton_jog_x_plus->setObjectName(QString::fromUtf8("pushButton_jog_x_plus"));

        gridLayout->addWidget(pushButton_jog_x_plus, 8, 1, 1, 1);

        pushButton_estop = new QPushButton(layoutWidget);
        pushButton_estop->setObjectName(QString::fromUtf8("pushButton_estop"));
        pushButton_estop->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        pushButton_estop->setCheckable(true);

        gridLayout->addWidget(pushButton_estop, 0, 0, 1, 1);

        pushButton_machine_on = new QPushButton(layoutWidget);
        pushButton_machine_on->setObjectName(QString::fromUtf8("pushButton_machine_on"));
        pushButton_machine_on->setCheckable(true);

        gridLayout->addWidget(pushButton_machine_on, 1, 0, 1, 1);

        pushButton_jog_z_min = new QPushButton(layoutWidget);
        pushButton_jog_z_min->setObjectName(QString::fromUtf8("pushButton_jog_z_min"));

        gridLayout->addWidget(pushButton_jog_z_min, 10, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 13, 0, 1, 1);

        label_active_gcodes = new QLabel(layoutWidget);
        label_active_gcodes->setObjectName(QString::fromUtf8("label_active_gcodes"));

        gridLayout->addWidget(label_active_gcodes, 12, 1, 1, 4);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 12, 0, 1, 1);

        pushButton_jog_x_min = new QPushButton(layoutWidget);
        pushButton_jog_x_min->setObjectName(QString::fromUtf8("pushButton_jog_x_min"));

        gridLayout->addWidget(pushButton_jog_x_min, 8, 0, 1, 1);

        pushButton_load = new QPushButton(layoutWidget);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout->addWidget(pushButton_load, 7, 0, 1, 1);

        pushButton_coord = new QPushButton(layoutWidget);
        pushButton_coord->setObjectName(QString::fromUtf8("pushButton_coord"));

        gridLayout->addWidget(pushButton_coord, 2, 1, 1, 1);

        pushButton_run = new QPushButton(layoutWidget);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));

        gridLayout->addWidget(pushButton_run, 6, 0, 1, 1);

        pushButton_home_y = new QPushButton(layoutWidget);
        pushButton_home_y->setObjectName(QString::fromUtf8("pushButton_home_y"));

        gridLayout->addWidget(pushButton_home_y, 3, 1, 1, 1);

        label_active_mcodes = new QLabel(layoutWidget);
        label_active_mcodes->setObjectName(QString::fromUtf8("label_active_mcodes"));

        gridLayout->addWidget(label_active_mcodes, 13, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 16, 0, 1, 1);

        pushButton_home_x = new QPushButton(layoutWidget);
        pushButton_home_x->setObjectName(QString::fromUtf8("pushButton_home_x"));

        gridLayout->addWidget(pushButton_home_x, 3, 0, 1, 1);

        pushButton_manual = new QPushButton(layoutWidget);
        pushButton_manual->setObjectName(QString::fromUtf8("pushButton_manual"));

        gridLayout->addWidget(pushButton_manual, 4, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 14, 0, 1, 1);

        pushButton_spindle_on_ccw = new QPushButton(layoutWidget);
        pushButton_spindle_on_ccw->setObjectName(QString::fromUtf8("pushButton_spindle_on_ccw"));

        gridLayout->addWidget(pushButton_spindle_on_ccw, 5, 1, 1, 1);

        pushButton_mdi = new QPushButton(layoutWidget);
        pushButton_mdi->setObjectName(QString::fromUtf8("pushButton_mdi"));

        gridLayout->addWidget(pushButton_mdi, 4, 1, 1, 1);

        pushButton_teleop = new QPushButton(layoutWidget);
        pushButton_teleop->setObjectName(QString::fromUtf8("pushButton_teleop"));

        gridLayout->addWidget(pushButton_teleop, 2, 0, 1, 1);

        pushButton_pause = new QPushButton(layoutWidget);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));

        gridLayout->addWidget(pushButton_pause, 6, 1, 1, 1);

        label_active_fcodes = new QLabel(layoutWidget);
        label_active_fcodes->setObjectName(QString::fromUtf8("label_active_fcodes"));

        gridLayout->addWidget(label_active_fcodes, 14, 1, 1, 2);

        pushButton_jog_z_plus = new QPushButton(layoutWidget);
        pushButton_jog_z_plus->setObjectName(QString::fromUtf8("pushButton_jog_z_plus"));

        gridLayout->addWidget(pushButton_jog_z_plus, 10, 1, 1, 1);

        pushButton_stop = new QPushButton(layoutWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout->addWidget(pushButton_stop, 6, 4, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 11, 0, 1, 1);

        horizontalScrollBar_jog_speed = new QScrollBar(layoutWidget);
        horizontalScrollBar_jog_speed->setObjectName(QString::fromUtf8("horizontalScrollBar_jog_speed"));
        horizontalScrollBar_jog_speed->setMaximum(2000);
        horizontalScrollBar_jog_speed->setValue(100);
        horizontalScrollBar_jog_speed->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalScrollBar_jog_speed, 11, 2, 1, 2);

        label_jog_speed = new QLabel(layoutWidget);
        label_jog_speed->setObjectName(QString::fromUtf8("label_jog_speed"));

        gridLayout->addWidget(label_jog_speed, 11, 1, 1, 1);

        label_mode = new QLabel(layoutWidget);
        label_mode->setObjectName(QString::fromUtf8("label_mode"));

        gridLayout->addWidget(label_mode, 5, 3, 1, 1);

        pushButton_home_all = new QPushButton(layoutWidget);
        pushButton_home_all->setObjectName(QString::fromUtf8("pushButton_home_all"));

        gridLayout->addWidget(pushButton_home_all, 3, 3, 1, 1);

        pushButton_unhome_all = new QPushButton(layoutWidget);
        pushButton_unhome_all->setObjectName(QString::fromUtf8("pushButton_unhome_all"));

        gridLayout->addWidget(pushButton_unhome_all, 3, 4, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 752, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "nml c++ example", nullptr));
        pushButton_jog_y_plus->setText(QCoreApplication::translate("MainWindow", "y+", nullptr));
        pushButton_free->setText(QCoreApplication::translate("MainWindow", "free", nullptr));
        pushButton_jog_y_min->setText(QCoreApplication::translate("MainWindow", "y-", nullptr));
        pushButton_auto->setText(QCoreApplication::translate("MainWindow", "auto", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "S code :", nullptr));
        pushButton_home_z->setText(QCoreApplication::translate("MainWindow", "home z", nullptr));
        pushButton_spindle_on_cw->setText(QCoreApplication::translate("MainWindow", "spinde on cw", nullptr));
        pushButton_spindle_off->setText(QCoreApplication::translate("MainWindow", "spindle off", nullptr));
        pushButton_resume->setText(QCoreApplication::translate("MainWindow", "resume", nullptr));
        label_active_scodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_reverse->setText(QCoreApplication::translate("MainWindow", "reverse", nullptr));
        pushButton_jog_x_plus->setText(QCoreApplication::translate("MainWindow", " x+", nullptr));
        pushButton_estop->setText(QCoreApplication::translate("MainWindow", "e-stop", nullptr));
        pushButton_machine_on->setText(QCoreApplication::translate("MainWindow", "machine on", nullptr));
        pushButton_jog_z_min->setText(QCoreApplication::translate("MainWindow", "z-", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "M code :", nullptr));
        label_active_gcodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "G code :", nullptr));
        pushButton_jog_x_min->setText(QCoreApplication::translate("MainWindow", "x-", nullptr));
        pushButton_load->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
        pushButton_coord->setText(QCoreApplication::translate("MainWindow", "coord", nullptr));
        pushButton_run->setText(QCoreApplication::translate("MainWindow", "run", nullptr));
        pushButton_home_y->setText(QCoreApplication::translate("MainWindow", "home y", nullptr));
        label_active_mcodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_home_x->setText(QCoreApplication::translate("MainWindow", "home x", nullptr));
        pushButton_manual->setText(QCoreApplication::translate("MainWindow", "manual", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "F code :", nullptr));
        pushButton_spindle_on_ccw->setText(QCoreApplication::translate("MainWindow", "spindle on ccw", nullptr));
        pushButton_mdi->setText(QCoreApplication::translate("MainWindow", "mdi", nullptr));
        pushButton_teleop->setText(QCoreApplication::translate("MainWindow", "teleop", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("MainWindow", "pause", nullptr));
        label_active_fcodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_jog_z_plus->setText(QCoreApplication::translate("MainWindow", "z+", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "jog speed", nullptr));
        label_jog_speed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_mode->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_home_all->setText(QCoreApplication::translate("MainWindow", "home all", nullptr));
        pushButton_unhome_all->setText(QCoreApplication::translate("MainWindow", "unhome all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
