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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_16;
    QFrame *frame_3;
    QGridLayout *gridLayout_17;
    QFrame *frame_16;
    QGridLayout *gridLayout_31;
    QGridLayout *gridLayout;
    QLabel *label_inifile;
    QLabel *label_21;
    QLabel *label_active_scodes;
    QLabel *label_file;
    QLabel *label;
    QLabel *label_active_mcodes;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_22;
    QLabel *label_active_gcodes;
    QLabel *label_2;
    QLabel *label_command;
    QLabel *label_23;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_current_line;
    QLabel *label_active_fcodes;
    QLabel *label_motion_line;
    QLabel *label_32;
    QTextBrowser *textBrowser;
    QFrame *frame;
    QGridLayout *gridLayout_18;
    QFrame *frame_5;
    QGridLayout *gridLayout_21;
    QGridLayout *gridLayout_12;
    QLabel *label_jog_speed;
    QLabel *label_5;
    QLabel *label_37;
    QScrollBar *horizontalScrollBar_jog_speed;
    QFrame *frame_11;
    QGridLayout *gridLayout_26;
    QGridLayout *gridLayout_9;
    QLabel *label_19;
    QPushButton *pushButton_mdi_exec;
    QLineEdit *lineEdit_mdi_input;
    QFrame *frame_4;
    QGridLayout *gridLayout_14;
    QGridLayout *gridLayout_11;
    QLabel *label_rapid_override;
    QLabel *label_14;
    QLabel *label_36;
    QScrollBar *horizontalScrollBar_rapid_override;
    QFrame *frame_8;
    QGridLayout *gridLayout_24;
    QGridLayout *gridLayout_15;
    QLabel *label_7;
    QLabel *label_adaptive_feed;
    QLabel *label_20;
    QLabel *label_adaptive_feed_status;
    QScrollBar *horizontalScrollBar_adaptive_feec;
    QFrame *frame_6;
    QGridLayout *gridLayout_22;
    QGridLayout *gridLayout_10;
    QLabel *label_10;
    QLabel *label_feed_override_status;
    QLabel *label_feed_overide;
    QScrollBar *horizontalScrollBar_feed_override;
    QLabel *label_9;
    QFrame *frame_7;
    QGridLayout *gridLayout_23;
    QGridLayout *gridLayout_13;
    QLabel *label_max_velocity_status;
    QLabel *label_11;
    QLabel *label_13;
    QLabel *label_max_velocity;
    QScrollBar *horizontalScrollBar_max_velocity;
    QLabel *label_34;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QFrame *frame_15;
    QGridLayout *gridLayout_30;
    QGridLayout *gridLayout_4;
    QLabel *label_6;
    QPushButton *pushButton_manual;
    QPushButton *pushButton_mdi;
    QPushButton *pushButton_auto;
    QLabel *label_35;
    QLabel *label_mode;
    QFrame *frame_13;
    QGridLayout *gridLayout_28;
    QGridLayout *gridLayout_2;
    QLabel *label_homed_x;
    QPushButton *pushButton_unhome_y;
    QPushButton *pushButton_jog_z_min;
    QLabel *label_z_coordinate;
    QPushButton *pushButton_jog_x_plus;
    QPushButton *pushButton_home_x;
    QPushButton *pushButton_unhome_all;
    QPushButton *pushButton_jog_y_min;
    QPushButton *pushButton_jog_z_plus;
    QLabel *label_homed_all;
    QPushButton *pushButton_jog_y_plus;
    QPushButton *pushButton_home_z;
    QLabel *label_homed_z;
    QPushButton *pushButton_unhome_z;
    QPushButton *pushButton_home_y;
    QLabel *label_homed_y;
    QLabel *label_y_coordinate;
    QPushButton *pushButton_jog_x_min;
    QPushButton *pushButton_home_all;
    QPushButton *pushButton_unhome_x;
    QLabel *label_x_coordinate;
    QLabel *label_29;
    QLabel *label_17;
    QLabel *label_current_velocity;
    QFrame *frame_10;
    QGridLayout *gridLayout_25;
    QGridLayout *gridLayout_6;
    QPushButton *pushButton_free;
    QPushButton *pushButton_teleop;
    QPushButton *pushButton;
    QLabel *label_28;
    QPushButton *pushButton_coord;
    QPushButton *pushButton_2;
    QLabel *label_30;
    QSpacerItem *verticalSpacer;
    QFrame *frame_14;
    QGridLayout *gridLayout_29;
    QGridLayout *gridLayout_7;
    QLabel *label_estop_status;
    QLabel *label_26;
    QLabel *label_27;
    QPushButton *pushButton_estop;
    QPushButton *pushButton_machine_on;
    QLabel *label_31;
    QLabel *label_machine_on_off_status;
    QFrame *frame_9;
    QGridLayout *gridLayout_20;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_spindle_off;
    QLabel *label_16;
    QLabel *label_18;
    QPushButton *pushButton_spindle_on_cw;
    QScrollBar *horizontalScrollBar_spindle_rpm;
    QLabel *label_spindle_override_status;
    QLabel *label_spindle_override;
    QScrollBar *horizontalScrollBar_spindle_override;
    QLabel *label_15;
    QLabel *label_8;
    QLabel *label_33;
    QLabel *label_rpm_status;
    QPushButton *pushButton_spindle_on_ccw;
    QLabel *label_spindle_rpm;
    QFrame *frame_12;
    QGridLayout *gridLayout_27;
    QGridLayout *gridLayout_5;
    QPushButton *pushButton_stop;
    QPushButton *pushButton_goto_zero;
    QLabel *label_38;
    QPushButton *pushButton_resume;
    QPushButton *pushButton_load;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_run;
    QLabel *label_12;
    QLineEdit *lineEdit_run_from_line;
    QPushButton *pushButton_reverse;
    QPushButton *pushButton_run_step;
    QPushButton *pushButton_forward;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(952, 927);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(51, 57, 59);\n"
"color: rgb(255, 255, 255);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_16 = new QGridLayout(centralwidget);
        gridLayout_16->setObjectName(QString::fromUtf8("gridLayout_16"));
        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(frame_3);
        gridLayout_17->setObjectName(QString::fromUtf8("gridLayout_17"));
        frame_16 = new QFrame(frame_3);
        frame_16->setObjectName(QString::fromUtf8("frame_16"));
        frame_16->setMinimumSize(QSize(0, 0));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        gridLayout_31 = new QGridLayout(frame_16);
        gridLayout_31->setObjectName(QString::fromUtf8("gridLayout_31"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_inifile = new QLabel(frame_16);
        label_inifile->setObjectName(QString::fromUtf8("label_inifile"));

        gridLayout->addWidget(label_inifile, 5, 1, 1, 1);

        label_21 = new QLabel(frame_16);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 8, 0, 1, 1);

        label_active_scodes = new QLabel(frame_16);
        label_active_scodes->setObjectName(QString::fromUtf8("label_active_scodes"));

        gridLayout->addWidget(label_active_scodes, 4, 1, 1, 1);

        label_file = new QLabel(frame_16);
        label_file->setObjectName(QString::fromUtf8("label_file"));

        gridLayout->addWidget(label_file, 6, 1, 1, 1);

        label = new QLabel(frame_16);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_active_mcodes = new QLabel(frame_16);
        label_active_mcodes->setObjectName(QString::fromUtf8("label_active_mcodes"));

        gridLayout->addWidget(label_active_mcodes, 2, 1, 1, 1);

        label_24 = new QLabel(frame_16);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout->addWidget(label_24, 6, 0, 1, 1);

        label_25 = new QLabel(frame_16);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout->addWidget(label_25, 7, 0, 1, 1);

        label_22 = new QLabel(frame_16);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout->addWidget(label_22, 9, 0, 1, 1);

        label_active_gcodes = new QLabel(frame_16);
        label_active_gcodes->setObjectName(QString::fromUtf8("label_active_gcodes"));

        gridLayout->addWidget(label_active_gcodes, 1, 1, 1, 1);

        label_2 = new QLabel(frame_16);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_command = new QLabel(frame_16);
        label_command->setObjectName(QString::fromUtf8("label_command"));

        gridLayout->addWidget(label_command, 7, 1, 1, 1);

        label_23 = new QLabel(frame_16);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout->addWidget(label_23, 5, 0, 1, 1);

        label_3 = new QLabel(frame_16);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        label_4 = new QLabel(frame_16);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_current_line = new QLabel(frame_16);
        label_current_line->setObjectName(QString::fromUtf8("label_current_line"));

        gridLayout->addWidget(label_current_line, 8, 1, 1, 1);

        label_active_fcodes = new QLabel(frame_16);
        label_active_fcodes->setObjectName(QString::fromUtf8("label_active_fcodes"));

        gridLayout->addWidget(label_active_fcodes, 3, 1, 1, 1);

        label_motion_line = new QLabel(frame_16);
        label_motion_line->setObjectName(QString::fromUtf8("label_motion_line"));

        gridLayout->addWidget(label_motion_line, 9, 1, 1, 1);

        label_32 = new QLabel(frame_16);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_32->setFont(font);

        gridLayout->addWidget(label_32, 0, 0, 1, 1);


        gridLayout_31->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_17->addWidget(frame_16, 1, 0, 1, 1);

        textBrowser = new QTextBrowser(frame_3);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_17->addWidget(textBrowser, 0, 0, 1, 1);


        gridLayout_16->addWidget(frame_3, 0, 1, 1, 1);

        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame);
        gridLayout_18->setObjectName(QString::fromUtf8("gridLayout_18"));
        frame_5 = new QFrame(frame);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_21 = new QGridLayout(frame_5);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        label_jog_speed = new QLabel(frame_5);
        label_jog_speed->setObjectName(QString::fromUtf8("label_jog_speed"));

        gridLayout_12->addWidget(label_jog_speed, 0, 1, 1, 1);

        label_5 = new QLabel(frame_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_12->addWidget(label_5, 0, 0, 1, 1);

        label_37 = new QLabel(frame_5);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_12->addWidget(label_37, 2, 0, 1, 1);

        horizontalScrollBar_jog_speed = new QScrollBar(frame_5);
        horizontalScrollBar_jog_speed->setObjectName(QString::fromUtf8("horizontalScrollBar_jog_speed"));
        horizontalScrollBar_jog_speed->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
""));
        horizontalScrollBar_jog_speed->setMaximum(2000);
        horizontalScrollBar_jog_speed->setValue(500);
        horizontalScrollBar_jog_speed->setOrientation(Qt::Horizontal);

        gridLayout_12->addWidget(horizontalScrollBar_jog_speed, 1, 0, 1, 2);


        gridLayout_21->addLayout(gridLayout_12, 0, 0, 1, 1);


        gridLayout_18->addWidget(frame_5, 3, 0, 1, 1);

        frame_11 = new QFrame(frame);
        frame_11->setObjectName(QString::fromUtf8("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        gridLayout_26 = new QGridLayout(frame_11);
        gridLayout_26->setObjectName(QString::fromUtf8("gridLayout_26"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_19 = new QLabel(frame_11);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        sizePolicy.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy);
        label_19->setFont(font);

        gridLayout_9->addWidget(label_19, 0, 1, 1, 1);

        pushButton_mdi_exec = new QPushButton(frame_11);
        pushButton_mdi_exec->setObjectName(QString::fromUtf8("pushButton_mdi_exec"));

        gridLayout_9->addWidget(pushButton_mdi_exec, 0, 2, 1, 1);

        lineEdit_mdi_input = new QLineEdit(frame_11);
        lineEdit_mdi_input->setObjectName(QString::fromUtf8("lineEdit_mdi_input"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_mdi_input->sizePolicy().hasHeightForWidth());
        lineEdit_mdi_input->setSizePolicy(sizePolicy1);

        gridLayout_9->addWidget(lineEdit_mdi_input, 1, 1, 1, 2);


        gridLayout_26->addLayout(gridLayout_9, 0, 0, 1, 1);


        gridLayout_18->addWidget(frame_11, 1, 1, 1, 1);

        frame_4 = new QFrame(frame);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_4);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        label_rapid_override = new QLabel(frame_4);
        label_rapid_override->setObjectName(QString::fromUtf8("label_rapid_override"));

        gridLayout_11->addWidget(label_rapid_override, 0, 1, 1, 1);

        label_14 = new QLabel(frame_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_11->addWidget(label_14, 0, 0, 1, 1);

        label_36 = new QLabel(frame_4);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_11->addWidget(label_36, 2, 0, 1, 1);

        horizontalScrollBar_rapid_override = new QScrollBar(frame_4);
        horizontalScrollBar_rapid_override->setObjectName(QString::fromUtf8("horizontalScrollBar_rapid_override"));
        horizontalScrollBar_rapid_override->setAutoFillBackground(false);
        horizontalScrollBar_rapid_override->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
""));
        horizontalScrollBar_rapid_override->setMaximum(120);
        horizontalScrollBar_rapid_override->setValue(100);
        horizontalScrollBar_rapid_override->setOrientation(Qt::Horizontal);

        gridLayout_11->addWidget(horizontalScrollBar_rapid_override, 1, 0, 1, 2);


        gridLayout_14->addLayout(gridLayout_11, 0, 0, 1, 1);


        gridLayout_18->addWidget(frame_4, 5, 1, 1, 1);

        frame_8 = new QFrame(frame);
        frame_8->setObjectName(QString::fromUtf8("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_24 = new QGridLayout(frame_8);
        gridLayout_24->setObjectName(QString::fromUtf8("gridLayout_24"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        label_7 = new QLabel(frame_8);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_15->addWidget(label_7, 0, 0, 1, 1);

        label_adaptive_feed = new QLabel(frame_8);
        label_adaptive_feed->setObjectName(QString::fromUtf8("label_adaptive_feed"));

        gridLayout_15->addWidget(label_adaptive_feed, 0, 1, 1, 1);

        label_20 = new QLabel(frame_8);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_15->addWidget(label_20, 2, 0, 1, 1);

        label_adaptive_feed_status = new QLabel(frame_8);
        label_adaptive_feed_status->setObjectName(QString::fromUtf8("label_adaptive_feed_status"));

        gridLayout_15->addWidget(label_adaptive_feed_status, 2, 1, 1, 1);

        horizontalScrollBar_adaptive_feec = new QScrollBar(frame_8);
        horizontalScrollBar_adaptive_feec->setObjectName(QString::fromUtf8("horizontalScrollBar_adaptive_feec"));
        horizontalScrollBar_adaptive_feec->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
""));
        horizontalScrollBar_adaptive_feec->setMinimum(-100);
        horizontalScrollBar_adaptive_feec->setMaximum(100);
        horizontalScrollBar_adaptive_feec->setPageStep(1);
        horizontalScrollBar_adaptive_feec->setValue(0);
        horizontalScrollBar_adaptive_feec->setOrientation(Qt::Horizontal);

        gridLayout_15->addWidget(horizontalScrollBar_adaptive_feec, 1, 0, 1, 2);


        gridLayout_24->addLayout(gridLayout_15, 0, 0, 1, 1);


        gridLayout_18->addWidget(frame_8, 1, 0, 1, 1);

        frame_6 = new QFrame(frame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_22 = new QGridLayout(frame_6);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        label_10 = new QLabel(frame_6);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_10->addWidget(label_10, 0, 0, 1, 2);

        label_feed_override_status = new QLabel(frame_6);
        label_feed_override_status->setObjectName(QString::fromUtf8("label_feed_override_status"));

        gridLayout_10->addWidget(label_feed_override_status, 2, 2, 1, 1);

        label_feed_overide = new QLabel(frame_6);
        label_feed_overide->setObjectName(QString::fromUtf8("label_feed_overide"));

        gridLayout_10->addWidget(label_feed_overide, 0, 2, 1, 1);

        horizontalScrollBar_feed_override = new QScrollBar(frame_6);
        horizontalScrollBar_feed_override->setObjectName(QString::fromUtf8("horizontalScrollBar_feed_override"));
        horizontalScrollBar_feed_override->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
""));
        horizontalScrollBar_feed_override->setMaximum(120);
        horizontalScrollBar_feed_override->setValue(100);
        horizontalScrollBar_feed_override->setOrientation(Qt::Horizontal);

        gridLayout_10->addWidget(horizontalScrollBar_feed_override, 1, 0, 1, 3);

        label_9 = new QLabel(frame_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_10->addWidget(label_9, 2, 0, 1, 2);


        gridLayout_22->addLayout(gridLayout_10, 0, 0, 1, 1);


        gridLayout_18->addWidget(frame_6, 5, 0, 1, 1);

        frame_7 = new QFrame(frame);
        frame_7->setObjectName(QString::fromUtf8("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(frame_7);
        gridLayout_23->setObjectName(QString::fromUtf8("gridLayout_23"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        label_max_velocity_status = new QLabel(frame_7);
        label_max_velocity_status->setObjectName(QString::fromUtf8("label_max_velocity_status"));

        gridLayout_13->addWidget(label_max_velocity_status, 2, 1, 1, 1);

        label_11 = new QLabel(frame_7);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_13->addWidget(label_11, 0, 0, 1, 1);

        label_13 = new QLabel(frame_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_13->addWidget(label_13, 2, 0, 1, 1);

        label_max_velocity = new QLabel(frame_7);
        label_max_velocity->setObjectName(QString::fromUtf8("label_max_velocity"));

        gridLayout_13->addWidget(label_max_velocity, 0, 1, 1, 1);

        horizontalScrollBar_max_velocity = new QScrollBar(frame_7);
        horizontalScrollBar_max_velocity->setObjectName(QString::fromUtf8("horizontalScrollBar_max_velocity"));
        horizontalScrollBar_max_velocity->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
""));
        horizontalScrollBar_max_velocity->setMaximum(5000);
        horizontalScrollBar_max_velocity->setValue(2000);
        horizontalScrollBar_max_velocity->setOrientation(Qt::Horizontal);

        gridLayout_13->addWidget(horizontalScrollBar_max_velocity, 1, 0, 1, 2);


        gridLayout_23->addLayout(gridLayout_13, 0, 0, 1, 1);


        gridLayout_18->addWidget(frame_7, 3, 1, 1, 1);

        label_34 = new QLabel(frame);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font);

        gridLayout_18->addWidget(label_34, 0, 0, 1, 1);


        gridLayout_16->addWidget(frame, 2, 1, 1, 1);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        frame_15 = new QFrame(frame_2);
        frame_15->setObjectName(QString::fromUtf8("frame_15"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        gridLayout_30 = new QGridLayout(frame_15);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_6 = new QLabel(frame_15);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        pushButton_manual = new QPushButton(frame_15);
        pushButton_manual->setObjectName(QString::fromUtf8("pushButton_manual"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_manual->sizePolicy().hasHeightForWidth());
        pushButton_manual->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_manual, 1, 0, 1, 2);

        pushButton_mdi = new QPushButton(frame_15);
        pushButton_mdi->setObjectName(QString::fromUtf8("pushButton_mdi"));
        sizePolicy2.setHeightForWidth(pushButton_mdi->sizePolicy().hasHeightForWidth());
        pushButton_mdi->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_mdi, 3, 0, 1, 2);

        pushButton_auto = new QPushButton(frame_15);
        pushButton_auto->setObjectName(QString::fromUtf8("pushButton_auto"));
        sizePolicy2.setHeightForWidth(pushButton_auto->sizePolicy().hasHeightForWidth());
        pushButton_auto->setSizePolicy(sizePolicy2);

        gridLayout_4->addWidget(pushButton_auto, 4, 0, 1, 2);

        label_35 = new QLabel(frame_15);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_4->addWidget(label_35, 5, 0, 1, 1);

        label_mode = new QLabel(frame_15);
        label_mode->setObjectName(QString::fromUtf8("label_mode"));

        gridLayout_4->addWidget(label_mode, 5, 1, 1, 1);


        gridLayout_30->addLayout(gridLayout_4, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_15, 0, 1, 1, 1);

        frame_13 = new QFrame(frame_2);
        frame_13->setObjectName(QString::fromUtf8("frame_13"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        gridLayout_28 = new QGridLayout(frame_13);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_homed_x = new QLabel(frame_13);
        label_homed_x->setObjectName(QString::fromUtf8("label_homed_x"));
        label_homed_x->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(label_homed_x, 1, 2, 1, 1);

        pushButton_unhome_y = new QPushButton(frame_13);
        pushButton_unhome_y->setObjectName(QString::fromUtf8("pushButton_unhome_y"));
        pushButton_unhome_y->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_unhome_y, 2, 1, 1, 1);

        pushButton_jog_z_min = new QPushButton(frame_13);
        pushButton_jog_z_min->setObjectName(QString::fromUtf8("pushButton_jog_z_min"));

        gridLayout_2->addWidget(pushButton_jog_z_min, 3, 3, 1, 1);

        label_z_coordinate = new QLabel(frame_13);
        label_z_coordinate->setObjectName(QString::fromUtf8("label_z_coordinate"));
        label_z_coordinate->setFont(font);

        gridLayout_2->addWidget(label_z_coordinate, 3, 5, 1, 1);

        pushButton_jog_x_plus = new QPushButton(frame_13);
        pushButton_jog_x_plus->setObjectName(QString::fromUtf8("pushButton_jog_x_plus"));

        gridLayout_2->addWidget(pushButton_jog_x_plus, 1, 4, 1, 1);

        pushButton_home_x = new QPushButton(frame_13);
        pushButton_home_x->setObjectName(QString::fromUtf8("pushButton_home_x"));
        pushButton_home_x->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_home_x, 1, 0, 1, 1);

        pushButton_unhome_all = new QPushButton(frame_13);
        pushButton_unhome_all->setObjectName(QString::fromUtf8("pushButton_unhome_all"));
        pushButton_unhome_all->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_unhome_all, 4, 1, 1, 1);

        pushButton_jog_y_min = new QPushButton(frame_13);
        pushButton_jog_y_min->setObjectName(QString::fromUtf8("pushButton_jog_y_min"));

        gridLayout_2->addWidget(pushButton_jog_y_min, 2, 3, 1, 1);

        pushButton_jog_z_plus = new QPushButton(frame_13);
        pushButton_jog_z_plus->setObjectName(QString::fromUtf8("pushButton_jog_z_plus"));

        gridLayout_2->addWidget(pushButton_jog_z_plus, 3, 4, 1, 1);

        label_homed_all = new QLabel(frame_13);
        label_homed_all->setObjectName(QString::fromUtf8("label_homed_all"));
        label_homed_all->setMaximumSize(QSize(252, 16777215));

        gridLayout_2->addWidget(label_homed_all, 4, 2, 1, 1);

        pushButton_jog_y_plus = new QPushButton(frame_13);
        pushButton_jog_y_plus->setObjectName(QString::fromUtf8("pushButton_jog_y_plus"));

        gridLayout_2->addWidget(pushButton_jog_y_plus, 2, 4, 1, 1);

        pushButton_home_z = new QPushButton(frame_13);
        pushButton_home_z->setObjectName(QString::fromUtf8("pushButton_home_z"));
        pushButton_home_z->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_home_z, 3, 0, 1, 1);

        label_homed_z = new QLabel(frame_13);
        label_homed_z->setObjectName(QString::fromUtf8("label_homed_z"));
        label_homed_z->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(label_homed_z, 3, 2, 1, 1);

        pushButton_unhome_z = new QPushButton(frame_13);
        pushButton_unhome_z->setObjectName(QString::fromUtf8("pushButton_unhome_z"));
        pushButton_unhome_z->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_unhome_z, 3, 1, 1, 1);

        pushButton_home_y = new QPushButton(frame_13);
        pushButton_home_y->setObjectName(QString::fromUtf8("pushButton_home_y"));
        pushButton_home_y->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_home_y, 2, 0, 1, 1);

        label_homed_y = new QLabel(frame_13);
        label_homed_y->setObjectName(QString::fromUtf8("label_homed_y"));
        label_homed_y->setMaximumSize(QSize(20, 16777215));

        gridLayout_2->addWidget(label_homed_y, 2, 2, 1, 1);

        label_y_coordinate = new QLabel(frame_13);
        label_y_coordinate->setObjectName(QString::fromUtf8("label_y_coordinate"));
        label_y_coordinate->setFont(font);

        gridLayout_2->addWidget(label_y_coordinate, 2, 5, 1, 1);

        pushButton_jog_x_min = new QPushButton(frame_13);
        pushButton_jog_x_min->setObjectName(QString::fromUtf8("pushButton_jog_x_min"));

        gridLayout_2->addWidget(pushButton_jog_x_min, 1, 3, 1, 1);

        pushButton_home_all = new QPushButton(frame_13);
        pushButton_home_all->setObjectName(QString::fromUtf8("pushButton_home_all"));
        pushButton_home_all->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_home_all, 4, 0, 1, 1);

        pushButton_unhome_x = new QPushButton(frame_13);
        pushButton_unhome_x->setObjectName(QString::fromUtf8("pushButton_unhome_x"));
        pushButton_unhome_x->setMaximumSize(QSize(35, 16777215));

        gridLayout_2->addWidget(pushButton_unhome_x, 1, 1, 1, 1);

        label_x_coordinate = new QLabel(frame_13);
        label_x_coordinate->setObjectName(QString::fromUtf8("label_x_coordinate"));
        label_x_coordinate->setMinimumSize(QSize(80, 0));
        label_x_coordinate->setMaximumSize(QSize(16777215, 16777215));
        label_x_coordinate->setFont(font);

        gridLayout_2->addWidget(label_x_coordinate, 1, 5, 1, 1);

        label_29 = new QLabel(frame_13);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setFont(font);

        gridLayout_2->addWidget(label_29, 0, 0, 1, 4);

        label_17 = new QLabel(frame_13);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        QFont font1;
        font1.setItalic(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        label_17->setFont(font1);
        label_17->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_17, 4, 3, 1, 2);

        label_current_velocity = new QLabel(frame_13);
        label_current_velocity->setObjectName(QString::fromUtf8("label_current_velocity"));
        label_current_velocity->setFont(font);

        gridLayout_2->addWidget(label_current_velocity, 4, 5, 1, 1);


        gridLayout_28->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_13, 1, 0, 1, 2);

        frame_10 = new QFrame(frame_2);
        frame_10->setObjectName(QString::fromUtf8("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_25 = new QGridLayout(frame_10);
        gridLayout_25->setObjectName(QString::fromUtf8("gridLayout_25"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        pushButton_free = new QPushButton(frame_10);
        pushButton_free->setObjectName(QString::fromUtf8("pushButton_free"));

        gridLayout_6->addWidget(pushButton_free, 1, 2, 1, 1);

        pushButton_teleop = new QPushButton(frame_10);
        pushButton_teleop->setObjectName(QString::fromUtf8("pushButton_teleop"));

        gridLayout_6->addWidget(pushButton_teleop, 1, 1, 1, 1);

        pushButton = new QPushButton(frame_10);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_6->addWidget(pushButton, 1, 0, 1, 1);

        label_28 = new QLabel(frame_10);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setFont(font);

        gridLayout_6->addWidget(label_28, 0, 0, 1, 1);

        pushButton_coord = new QPushButton(frame_10);
        pushButton_coord->setObjectName(QString::fromUtf8("pushButton_coord"));

        gridLayout_6->addWidget(pushButton_coord, 2, 1, 1, 1);

        pushButton_2 = new QPushButton(frame_10);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_6->addWidget(pushButton_2, 2, 0, 1, 1);

        label_30 = new QLabel(frame_10);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_6->addWidget(label_30, 0, 1, 1, 1);


        gridLayout_25->addLayout(gridLayout_6, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_25->addItem(verticalSpacer, 1, 0, 1, 1);


        gridLayout_3->addWidget(frame_10, 5, 0, 1, 2);

        frame_14 = new QFrame(frame_2);
        frame_14->setObjectName(QString::fromUtf8("frame_14"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        gridLayout_29 = new QGridLayout(frame_14);
        gridLayout_29->setObjectName(QString::fromUtf8("gridLayout_29"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_estop_status = new QLabel(frame_14);
        label_estop_status->setObjectName(QString::fromUtf8("label_estop_status"));

        gridLayout_7->addWidget(label_estop_status, 3, 1, 1, 1);

        label_26 = new QLabel(frame_14);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setFont(font);

        gridLayout_7->addWidget(label_26, 0, 0, 1, 1);

        label_27 = new QLabel(frame_14);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_7->addWidget(label_27, 3, 0, 1, 1);

        pushButton_estop = new QPushButton(frame_14);
        pushButton_estop->setObjectName(QString::fromUtf8("pushButton_estop"));
        sizePolicy2.setHeightForWidth(pushButton_estop->sizePolicy().hasHeightForWidth());
        pushButton_estop->setSizePolicy(sizePolicy2);
        pushButton_estop->setCheckable(true);

        gridLayout_7->addWidget(pushButton_estop, 2, 0, 1, 2);

        pushButton_machine_on = new QPushButton(frame_14);
        pushButton_machine_on->setObjectName(QString::fromUtf8("pushButton_machine_on"));
        sizePolicy2.setHeightForWidth(pushButton_machine_on->sizePolicy().hasHeightForWidth());
        pushButton_machine_on->setSizePolicy(sizePolicy2);
        pushButton_machine_on->setCheckable(true);

        gridLayout_7->addWidget(pushButton_machine_on, 5, 0, 1, 2);

        label_31 = new QLabel(frame_14);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_7->addWidget(label_31, 6, 0, 1, 1);

        label_machine_on_off_status = new QLabel(frame_14);
        label_machine_on_off_status->setObjectName(QString::fromUtf8("label_machine_on_off_status"));

        gridLayout_7->addWidget(label_machine_on_off_status, 6, 1, 1, 1);


        gridLayout_29->addLayout(gridLayout_7, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_14, 0, 0, 1, 1);

        frame_9 = new QFrame(frame_2);
        frame_9->setObjectName(QString::fromUtf8("frame_9"));
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        gridLayout_20 = new QGridLayout(frame_9);
        gridLayout_20->setObjectName(QString::fromUtf8("gridLayout_20"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        pushButton_spindle_off = new QPushButton(frame_9);
        pushButton_spindle_off->setObjectName(QString::fromUtf8("pushButton_spindle_off"));

        gridLayout_8->addWidget(pushButton_spindle_off, 1, 0, 1, 1);

        label_16 = new QLabel(frame_9);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_8->addWidget(label_16, 5, 0, 1, 2);

        label_18 = new QLabel(frame_9);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_8->addWidget(label_18, 4, 0, 1, 2);

        pushButton_spindle_on_cw = new QPushButton(frame_9);
        pushButton_spindle_on_cw->setObjectName(QString::fromUtf8("pushButton_spindle_on_cw"));

        gridLayout_8->addWidget(pushButton_spindle_on_cw, 1, 1, 1, 1);

        horizontalScrollBar_spindle_rpm = new QScrollBar(frame_9);
        horizontalScrollBar_spindle_rpm->setObjectName(QString::fromUtf8("horizontalScrollBar_spindle_rpm"));
        horizontalScrollBar_spindle_rpm->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
""));
        horizontalScrollBar_spindle_rpm->setMaximum(5000);
        horizontalScrollBar_spindle_rpm->setValue(1);
        horizontalScrollBar_spindle_rpm->setOrientation(Qt::Horizontal);
        horizontalScrollBar_spindle_rpm->setInvertedAppearance(false);

        gridLayout_8->addWidget(horizontalScrollBar_spindle_rpm, 3, 0, 1, 3);

        label_spindle_override_status = new QLabel(frame_9);
        label_spindle_override_status->setObjectName(QString::fromUtf8("label_spindle_override_status"));

        gridLayout_8->addWidget(label_spindle_override_status, 7, 2, 1, 1);

        label_spindle_override = new QLabel(frame_9);
        label_spindle_override->setObjectName(QString::fromUtf8("label_spindle_override"));

        gridLayout_8->addWidget(label_spindle_override, 5, 2, 1, 1);

        horizontalScrollBar_spindle_override = new QScrollBar(frame_9);
        horizontalScrollBar_spindle_override->setObjectName(QString::fromUtf8("horizontalScrollBar_spindle_override"));
        horizontalScrollBar_spindle_override->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 39, 40);\n"
""));
        horizontalScrollBar_spindle_override->setMaximum(100);
        horizontalScrollBar_spindle_override->setValue(100);
        horizontalScrollBar_spindle_override->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(horizontalScrollBar_spindle_override, 6, 0, 1, 3);

        label_15 = new QLabel(frame_9);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_8->addWidget(label_15, 2, 0, 1, 2);

        label_8 = new QLabel(frame_9);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_8->addWidget(label_8, 7, 0, 1, 2);

        label_33 = new QLabel(frame_9);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setFont(font);

        gridLayout_8->addWidget(label_33, 0, 0, 1, 1);

        label_rpm_status = new QLabel(frame_9);
        label_rpm_status->setObjectName(QString::fromUtf8("label_rpm_status"));

        gridLayout_8->addWidget(label_rpm_status, 4, 2, 1, 1);

        pushButton_spindle_on_ccw = new QPushButton(frame_9);
        pushButton_spindle_on_ccw->setObjectName(QString::fromUtf8("pushButton_spindle_on_ccw"));

        gridLayout_8->addWidget(pushButton_spindle_on_ccw, 1, 2, 1, 1);

        label_spindle_rpm = new QLabel(frame_9);
        label_spindle_rpm->setObjectName(QString::fromUtf8("label_spindle_rpm"));

        gridLayout_8->addWidget(label_spindle_rpm, 2, 2, 1, 1);


        gridLayout_20->addLayout(gridLayout_8, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_9, 4, 0, 1, 2);

        frame_12 = new QFrame(frame_2);
        frame_12->setObjectName(QString::fromUtf8("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        gridLayout_27 = new QGridLayout(frame_12);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        pushButton_stop = new QPushButton(frame_12);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout_5->addWidget(pushButton_stop, 4, 0, 1, 1);

        pushButton_goto_zero = new QPushButton(frame_12);
        pushButton_goto_zero->setObjectName(QString::fromUtf8("pushButton_goto_zero"));

        gridLayout_5->addWidget(pushButton_goto_zero, 1, 0, 1, 1);

        label_38 = new QLabel(frame_12);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_5->addWidget(label_38, 5, 0, 1, 1);

        pushButton_resume = new QPushButton(frame_12);
        pushButton_resume->setObjectName(QString::fromUtf8("pushButton_resume"));

        gridLayout_5->addWidget(pushButton_resume, 2, 3, 1, 1);

        pushButton_load = new QPushButton(frame_12);
        pushButton_load->setObjectName(QString::fromUtf8("pushButton_load"));

        gridLayout_5->addWidget(pushButton_load, 1, 2, 1, 1);

        pushButton_pause = new QPushButton(frame_12);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));

        gridLayout_5->addWidget(pushButton_pause, 2, 2, 1, 1);

        pushButton_run = new QPushButton(frame_12);
        pushButton_run->setObjectName(QString::fromUtf8("pushButton_run"));

        gridLayout_5->addWidget(pushButton_run, 2, 0, 1, 1);

        label_12 = new QLabel(frame_12);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);

        gridLayout_5->addWidget(label_12, 0, 0, 1, 1);

        lineEdit_run_from_line = new QLineEdit(frame_12);
        lineEdit_run_from_line->setObjectName(QString::fromUtf8("lineEdit_run_from_line"));

        gridLayout_5->addWidget(lineEdit_run_from_line, 5, 2, 1, 2);

        pushButton_reverse = new QPushButton(frame_12);
        pushButton_reverse->setObjectName(QString::fromUtf8("pushButton_reverse"));

        gridLayout_5->addWidget(pushButton_reverse, 4, 2, 1, 1);

        pushButton_run_step = new QPushButton(frame_12);
        pushButton_run_step->setObjectName(QString::fromUtf8("pushButton_run_step"));

        gridLayout_5->addWidget(pushButton_run_step, 3, 0, 1, 1);

        pushButton_forward = new QPushButton(frame_12);
        pushButton_forward->setObjectName(QString::fromUtf8("pushButton_forward"));

        gridLayout_5->addWidget(pushButton_forward, 4, 3, 1, 1);


        gridLayout_27->addLayout(gridLayout_5, 0, 0, 1, 1);


        gridLayout_3->addWidget(frame_12, 2, 0, 1, 2);


        gridLayout_16->addWidget(frame_2, 0, 0, 3, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 952, 22));
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
        label_inifile->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "current line :", nullptr));
        label_active_scodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_file->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "G code ", nullptr));
        label_active_mcodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "file :", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "command :", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "motion line :", nullptr));
        label_active_gcodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "M code ", nullptr));
        label_command->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "inifile :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "S code :", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "F code :", nullptr));
        label_current_line->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_active_fcodes->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_motion_line->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "INFO", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans Mono'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">This app demonstrates the linuxcnc nml interface.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To load this program alongside linuxcnc first start </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">linuxcnc, for example axis_mm.</p>\n"
""
                        "<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">~/linuxcnc/scripts/. ./rip-environment</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">~/linuxcnc/scripts/. ./linuxcnc</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Then run this app and values should be updated.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-b"
                        "ottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">To run stand alone :</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">~/linuxcnc/scripts/linuxcnc '~/linuxcnc/configs/sim/axis/skynet.ini'</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Todo : </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-i"
                        "ndent:0; text-indent:0px;\">	1. Adaptive feed.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	2. Joint mode for homing sequence.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	3. Debug output.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Additional info :</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	When load is pressed, the gremlin screen is</p>\n"
"<p style=\" mar"
                        "gin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	not updated with new gcode, also the gcode line</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	preview is not updated, but the gcode is loaded</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	and can be executed.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">	the load button opens a .ngc file wich is a square 100x100mm</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-parag"
                        "raph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_jog_speed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "jog speed [mm/min]", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "MDI ", nullptr));
        pushButton_mdi_exec->setText(QCoreApplication::translate("MainWindow", "exec", nullptr));
        label_rapid_override->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "rapid override [%]", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "todo :adaptive feed [%]", nullptr));
        label_adaptive_feed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_adaptive_feed_status->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "feed override [%]", nullptr));
        label_feed_override_status->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_feed_overide->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_max_velocity_status->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "max velocity [mm/min]", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_max_velocity->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "FEEDS", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "MODE", nullptr));
        pushButton_manual->setText(QCoreApplication::translate("MainWindow", "manual", nullptr));
        pushButton_mdi->setText(QCoreApplication::translate("MainWindow", "mdi", nullptr));
        pushButton_auto->setText(QCoreApplication::translate("MainWindow", "auto", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_mode->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_homed_x->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_unhome_y->setText(QCoreApplication::translate("MainWindow", "UH", nullptr));
        pushButton_jog_z_min->setText(QCoreApplication::translate("MainWindow", "z -", nullptr));
        label_z_coordinate->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_jog_x_plus->setText(QCoreApplication::translate("MainWindow", "x +", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_home_x->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_home_x->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        pushButton_unhome_all->setText(QCoreApplication::translate("MainWindow", "UHA", nullptr));
        pushButton_jog_y_min->setText(QCoreApplication::translate("MainWindow", "y -", nullptr));
        pushButton_jog_z_plus->setText(QCoreApplication::translate("MainWindow", "z +", nullptr));
        label_homed_all->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_jog_y_plus->setText(QCoreApplication::translate("MainWindow", "y +", nullptr));
        pushButton_home_z->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        label_homed_z->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_unhome_z->setText(QCoreApplication::translate("MainWindow", "UH", nullptr));
        pushButton_home_y->setText(QCoreApplication::translate("MainWindow", "H", nullptr));
        label_homed_y->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_y_coordinate->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        pushButton_jog_x_min->setText(QCoreApplication::translate("MainWindow", "x -", nullptr));
        pushButton_home_all->setText(QCoreApplication::translate("MainWindow", "HA", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_unhome_x->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        pushButton_unhome_x->setText(QCoreApplication::translate("MainWindow", "UH", nullptr));
        label_x_coordinate->setText(QCoreApplication::translate("MainWindow", "0.000", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "CONTROLS", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "velocity [mm/min] ", nullptr));
        label_current_velocity->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_free->setText(QCoreApplication::translate("MainWindow", "free", nullptr));
        pushButton_teleop->setText(QCoreApplication::translate("MainWindow", "teleop", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "lube on - off", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "IO", nullptr));
        pushButton_coord->setText(QCoreApplication::translate("MainWindow", "coord", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "mist on - off", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "mode", nullptr));
        label_estop_status->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "MACHINE ", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        pushButton_estop->setText(QCoreApplication::translate("MainWindow", "e-stop", nullptr));
        pushButton_machine_on->setText(QCoreApplication::translate("MainWindow", "machine on", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_machine_on_off_status->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_spindle_off->setText(QCoreApplication::translate("MainWindow", "spindle off", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "override [%]", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        pushButton_spindle_on_cw->setText(QCoreApplication::translate("MainWindow", "spinde on cw", nullptr));
        label_spindle_override_status->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_spindle_override->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "spindle [rpm]", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "status", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "SPINDLE", nullptr));
        label_rpm_status->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_spindle_on_ccw->setText(QCoreApplication::translate("MainWindow", "spindle on ccw", nullptr));
        label_spindle_rpm->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("MainWindow", "stop", nullptr));
        pushButton_goto_zero->setText(QCoreApplication::translate("MainWindow", "goto zero", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "run from line", nullptr));
        pushButton_resume->setText(QCoreApplication::translate("MainWindow", "resume", nullptr));
        pushButton_load->setText(QCoreApplication::translate("MainWindow", "load", nullptr));
        pushButton_pause->setText(QCoreApplication::translate("MainWindow", "pause", nullptr));
        pushButton_run->setText(QCoreApplication::translate("MainWindow", "run", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "PROGRAM", nullptr));
        lineEdit_run_from_line->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_reverse->setText(QCoreApplication::translate("MainWindow", "reverse", nullptr));
        pushButton_run_step->setText(QCoreApplication::translate("MainWindow", "run step", nullptr));
        pushButton_forward->setText(QCoreApplication::translate("MainWindow", "forward", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
