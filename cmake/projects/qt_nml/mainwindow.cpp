#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>

float jogspeed=0;
float spindlespeed=1000;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //! This activates a screen update when robot is moving and screen needs to be updated automaticly.
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update);
    timer->start(100);

    jogspeed=ui->horizontalScrollBar_jog_speed->value();
    ui->label_jog_speed->setText(QString::number(jogspeed,'f',3));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    myNml->update();

    if(myNml->theStatus.estop){
        ui->pushButton_estop->setChecked(true);
    } else {
        ui->pushButton_estop->setChecked(false);
    }


    if(myNml->theStatus.on){
        ui->pushButton_machine_on->setChecked(true);
    } else {
        ui->pushButton_machine_on->setChecked(false);
    }

    ui->label_active_gcodes->setText(myNml->theStatus.task_active_gcodes_string);
    ui->label_active_mcodes->setText(myNml->theStatus.task_active_mcodes_string);
    ui->label_active_fcodes->setText(myNml->theStatus.task_active_fcodes_string);
    ui->label_active_scodes->setText(myNml->theStatus.task_active_scodes_string);

    QString mode;
    if(myNml->theStatus.mode==0){
        mode="manual";
    }
    if(myNml->theStatus.mode==1){
        mode="mdi";
    }
    if(myNml->theStatus.mode==2){
        mode="auto";
    }
    ui->label_mode->setText(mode);
}

void MainWindow::on_pushButton_estop_pressed()
{
    //! Toggle.
    if(myNml->theStatus.estop){
        myNml->estop_reset();
    } else {
        myNml->estop();
    }
}
void MainWindow::on_pushButton_machine_on_pressed()
{
    //! Toggle.
    if(myNml->theStatus.on){
        myNml->machine_off();
    } else {
        myNml->machine_on();
    }
}
void MainWindow::on_pushButton_load_pressed()
{
    myNml->load();
}

void MainWindow::on_pushButton_auto_pressed()
{
    myNml->mode_auto();
}

void MainWindow::on_pushButton_mdi_pressed()
{
    myNml->mode_mdi();
}

void MainWindow::on_pushButton_manual_pressed()
{
    myNml->mode_manual();
}

void MainWindow::on_pushButton_run_pressed()
{
    myNml->mode_auto();
    myNml->run();
}
void MainWindow::on_pushButton_resume_pressed()
{
    myNml->resume();
}

void MainWindow::on_pushButton_reverse_pressed()
{
    myNml->reverse();
}

void MainWindow::on_pushButton_pause_pressed()
{
    myNml->pause();
}

void MainWindow::on_pushButton_teleop_pressed()
{
    myNml->teleop();
}

void MainWindow::on_pushButton_coord_pressed()
{
    myNml->coord();
}

void MainWindow::on_pushButton_free_pressed()
{
    myNml->free();
}

void MainWindow::on_pushButton_home_x_pressed()
{
    myNml->home_x();
}

void MainWindow::on_pushButton_home_y_pressed()
{
    myNml->home_y();
}

void MainWindow::on_pushButton_home_z_pressed()
{
    myNml->home_z();
}

void MainWindow::on_pushButton_stop_pressed()
{
    myNml->stop();
    myNml->mode_manual();
}

void MainWindow::on_pushButton_spindle_off_pressed()
{
    myNml->spindle(0);
}

void MainWindow::on_pushButton_spindle_on_cw_pressed()
{
    myNml->spindle(spindlespeed);
}

void MainWindow::on_pushButton_spindle_on_ccw_pressed()
{
    myNml->spindle(spindlespeed*-1);
}

void MainWindow::on_pushButton_jog_x_min_pressed()
{
    myNml->jog(0,jogspeed*-1);
}

void MainWindow::on_pushButton_jog_x_min_released()
{
    //myNml->jog(0,0);
    myNml->jog_stop(0);
}

void MainWindow::on_pushButton_jog_x_plus_pressed()
{
    myNml->jog(0,jogspeed);
}

void MainWindow::on_pushButton_jog_x_plus_released()
{
    //myNml->jog(0,0);
    myNml->jog_stop(0);
}

void MainWindow::on_pushButton_jog_y_min_pressed()
{
    myNml->jog(1,jogspeed*-1);
}

void MainWindow::on_pushButton_jog_y_min_released()
{
    //myNml->jog(1,0);
    myNml->jog_stop(1);
}

void MainWindow::on_pushButton_jog_y_plus_pressed()
{
    myNml->jog(1,jogspeed);
}

void MainWindow::on_pushButton_jog_y_plus_released()
{
    //myNml->jog(1,0);
    myNml->jog_stop(1);
}

void MainWindow::on_pushButton_jog_z_min_pressed()
{
    myNml->jog(2,jogspeed*-1);
}

void MainWindow::on_pushButton_jog_z_min_released()
{
    //myNml->jog(2,0);
    myNml->jog_stop(2);
}

void MainWindow::on_pushButton_jog_z_plus_pressed()
{
    myNml->jog(2,jogspeed);
}

void MainWindow::on_pushButton_jog_z_plus_released()
{
    //myNml->jog(2,0);
    myNml->jog_stop(2);
}

void MainWindow::on_horizontalScrollBar_jog_speed_valueChanged(int value)
{
    jogspeed=value;
    ui->label_jog_speed->setText(QString::number(jogspeed,'f',3));
}

void MainWindow::on_pushButton_home_all_pressed()
{
    myNml->home_all();
}

void MainWindow::on_pushButton_unhome_all_pressed()
{
    myNml->unhome_all();
}
