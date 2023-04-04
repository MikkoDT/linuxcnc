#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include "../qt_ruckig_gui/ruckig/ruckig.hpp"

typedef double T;
typedef bool B;
std::vector<T> vvec,svec,avec;

ruckig::InputParameter<1> in;
ruckig::OutputParameter<1> out;
ruckig::Ruckig<1> otg {0.001};
ruckig::Result r;
bool thread_1=0, thread_2=0;
T increment_timer=0;
T duration_=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //! OpenGl output to verify.
    myOpenGl = new opengl();
    //! Graph scale.
    myOpenGl->setScale(25,25);
    myOpenGl->setInterval(0.001);
    myOpenGl->set2VecShift(100);
    myOpenGl->set1VecScale(0.1);

    //! Timer to simulate servo cycle.
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(thread()));
    timer->start(1);

    on_pushButton_run_pressed();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_run_pressed()
{
    thread_1=0;
    thread_2=0;

    //! Inputs:
    in.max_acceleration[0]=ui->doubleSpinBox_a->value();
    in.max_jerk[0]=ui->doubleSpinBox_jm->value();
    in.max_velocity[0]=ui->doubleSpinBox_vm->value();

    in.current_position[0]=0;
    in.current_velocity[0]=ui->doubleSpinBox_vo->value();
    in.current_acceleration[0]=ui->doubleSpinBox_acs->value();

    in.target_position[0]=ui->doubleSpinBox_s->value();
    in.target_velocity[0]=ui->doubleSpinBox_ve->value();
    in.target_acceleration[0]=ui->doubleSpinBox_ace->value();

    //! enum: position, velocity
    in.control_interface=ruckig::ControlInterface::Position;
    //! Phase, ///< Phase synchronize the DoFs when possible, else fallback to "Time" strategy
    //! Time, ///< Always synchronize the DoFs to reach the target at the same time (Default)
    //! TimeIfNecessary, ///< Synchronize only when necessary (e.g. for non-zero target velocity or acceleration)
    //! None, ///< Calculate every DoF independently
    in.synchronization=ruckig::Synchronization::None;
    //! Continuous, ///< Every trajectory duration is allowed (Default), in lcnc this is called the split cycle.
    //! Discrete, ///< The trajectory duration must be a multiple of the control cycle
    in.duration_discretization=ruckig::DurationDiscretization::Discrete;

    in.enabled[0]=1;

    auto result=otg.update(in, out);

    if(result==ruckig::Result::Error){
        std::cout<<"error"<<std::endl;
    }
    if(result==ruckig::Result::ErrorExecutionTimeCalculation){
        std::cout<<"ErrorExecutionTimeCalculation"<<std::endl;
    }
    if(result==ruckig::Result::ErrorInvalidInput){
        std::cout<<"ErrorInvalidInput"<<std::endl;
    }
    if(result==ruckig::Result::ErrorPositionalLimits){
        std::cout<<"ErrorPositionalLimits"<<std::endl;
    }
    if(result==ruckig::Result::ErrorSynchronizationCalculation){
        std::cout<<"ErrorSynchronizationCalculation"<<std::endl;
    }
    if(result==ruckig::Result::ErrorTrajectoryDuration){
        std::cout<<"ErrorTrajectoryDuration"<<std::endl;
    }
    if(result==ruckig::Result::Finished){
        std::cout<<"Finished"<<std::endl;
    }
    if(result==ruckig::Result::Working){
        std::cout<<"Working"<<std::endl;
    }

    T ttot=out.trajectory.get_duration();
    std::array<double, 1> vel, acc, pos;
    out.trajectory.at_time(ttot,pos,vel,acc);
    std::cout<<"ttot:"<<ttot<<" endpos:"<<pos[0]<<" endvel:"<<vel[0]<<" endacc:"<<acc[0]<<std::endl;

    vvec.clear();
    svec.clear();
    avec.clear();
    myOpenGl->setj0vec(vvec);
    myOpenGl->setj1vec(svec);
    myOpenGl->setj2vec(avec);

    for(T i=0; i<ttot; i+=0.001){

        std::array<double, 1> vel, acc, pos;
        out.trajectory.at_time(i,pos, vel, acc);

        svec.push_back(pos[0]);
        vvec.push_back(vel[0]);
        avec.push_back(acc[0]);

        myOpenGl->setj0vec(vvec);
        myOpenGl->setj1vec(svec);
        myOpenGl->setj2vec(avec);
    }
}

void MainWindow::on_pushButton_run_while_pressed()
{
    thread_1=0;
    thread_2=0;

    //! Inputs:
    in.max_acceleration[0]=ui->doubleSpinBox_a->value();
    in.max_jerk[0]=ui->doubleSpinBox_jm->value();
    in.max_velocity[0]=ui->doubleSpinBox_vm->value();

    in.current_position[0]=0;
    in.current_velocity[0]=ui->doubleSpinBox_vo->value();
    in.current_acceleration[0]=ui->doubleSpinBox_acs->value();

    in.target_position[0]=ui->doubleSpinBox_s->value();
    in.target_velocity[0]=ui->doubleSpinBox_ve->value();
    in.target_acceleration[0]=ui->doubleSpinBox_ace->value();

    //! enum: position, velocity
    in.control_interface=ruckig::ControlInterface::Position;
    //! Phase, ///< Phase synchronize the DoFs when possible, else fallback to "Time" strategy
    //! Time, ///< Always synchronize the DoFs to reach the target at the same time (Default)
    //! TimeIfNecessary, ///< Synchronize only when necessary (e.g. for non-zero target velocity or acceleration)
    //! None, ///< Calculate every DoF independently
    in.synchronization=ruckig::Synchronization::None;
    //! Continuous, ///< Every trajectory duration is allowed (Default), in lcnc this is called the split cycle.
    //! Discrete, ///< The trajectory duration must be a multiple of the control cycle
    in.duration_discretization=ruckig::DurationDiscretization::Discrete;

    in.enabled[0]=1;

    auto result=otg.update(in, out);

    if(result==ruckig::Result::Error){
        std::cout<<"error"<<std::endl;
    }
    if(result==ruckig::Result::ErrorExecutionTimeCalculation){
        std::cout<<"ErrorExecutionTimeCalculation"<<std::endl;
    }
    if(result==ruckig::Result::ErrorInvalidInput){
        std::cout<<"ErrorInvalidInput"<<std::endl;
    }
    if(result==ruckig::Result::ErrorPositionalLimits){
        std::cout<<"ErrorPositionalLimits"<<std::endl;
    }
    if(result==ruckig::Result::ErrorSynchronizationCalculation){
        std::cout<<"ErrorSynchronizationCalculation"<<std::endl;
    }
    if(result==ruckig::Result::ErrorTrajectoryDuration){
        std::cout<<"ErrorTrajectoryDuration"<<std::endl;
    }
    if(result==ruckig::Result::Finished){
        std::cout<<"Finished"<<std::endl;
    }
    if(result==ruckig::Result::Working){
        std::cout<<"Working"<<std::endl;
    }

    T ttot=out.trajectory.get_duration();
    std::array<double, 1> vel, acc, pos;
    out.trajectory.at_time(ttot,pos,vel,acc);

    std::cout<<"ttot:"<<ttot<<" endpos:"<<pos[0]<<" endvel:"<<vel[0]<<" endacc:"<<acc[0]<<std::endl;

    vvec.clear();
    svec.clear();
    avec.clear();
    myOpenGl->setj0vec(vvec);
    myOpenGl->setj1vec(svec);
    myOpenGl->setj2vec(avec);

    // Generate the trajectory within the control loop
    //std::cout << "t | p1 | p2 | p3" << std::endl;
    while (otg.update(in, out) == ruckig::Result::Working) {
        auto& p = out.new_position;
        // std::cout << out.time << " " << p[0] << " " << p[1] << " " << p[2] << " " << std::endl;

        out.pass_to_input(in);

        svec.push_back(out.new_position[0]);
        vvec.push_back(out.new_velocity[0]);
        avec.push_back(out.new_acceleration[0]);

        myOpenGl->setj0vec(vvec);
        myOpenGl->setj1vec(svec);
        myOpenGl->setj2vec(avec);
    }
}

void MainWindow::on_pushButton_thread_1_pressed()
{
    in.max_acceleration[0]=ui->doubleSpinBox_a->value();
    in.max_jerk[0]=ui->doubleSpinBox_jm->value();
    in.max_velocity[0]=ui->doubleSpinBox_vm->value();

    in.current_position[0]=0;
    in.current_velocity[0]=ui->doubleSpinBox_vo->value();
    in.current_acceleration[0]=ui->doubleSpinBox_acs->value();

    in.target_position[0]=ui->doubleSpinBox_s->value();
    in.target_velocity[0]=ui->doubleSpinBox_ve->value();
    in.target_acceleration[0]=ui->doubleSpinBox_ace->value();

    r=otg.update(in, out);

    duration_=out.trajectory.get_duration();

    vvec.clear();
    svec.clear();
    avec.clear();

    thread_1=1;
    increment_timer=0;
}

void MainWindow::on_pushButton_thread_2_clicked()
{
    in.max_acceleration[0]=ui->doubleSpinBox_a->value();
    in.max_jerk[0]=ui->doubleSpinBox_jm->value();
    in.max_velocity[0]=ui->doubleSpinBox_vm->value();

    in.current_position[0]=0;
    in.current_velocity[0]=ui->doubleSpinBox_vo->value();
    in.current_acceleration[0]=ui->doubleSpinBox_acs->value();

    in.target_position[0]=ui->doubleSpinBox_s->value();
    in.target_velocity[0]=ui->doubleSpinBox_ve->value();
    in.target_acceleration[0]=ui->doubleSpinBox_ace->value();

    vvec.clear();
    svec.clear();
    avec.clear();

    thread_2=1;
    increment_timer=0;
}


//! This function simulates the servo cycle. And is called every 1 millisecond.
void MainWindow::thread(){

    //! Works best.
    if(thread_1){

        std::array<double, 1> vel, acc, pos;
        out.trajectory.at_time(increment_timer,pos, vel, acc);

        in.current_position=pos;
        in.current_velocity=vel;
        in.current_acceleration=acc;

        svec.push_back(pos[0]);
        vvec.push_back(vel[0]);
        avec.push_back(acc[0]);
        myOpenGl->setj0vec(vvec);
        myOpenGl->setj1vec(svec);
        myOpenGl->setj2vec(avec);

        //! It will never trigger the finished flag.
        if(r==ruckig::Result::Finished){
            std::cout<<"Finished"<<std::endl;
            thread_1=0;
        }
        if(r==ruckig::Result::Working){
            std::cout<<"Working"<<std::endl;
            std::cout<<"t left:"<<out.trajectory.get_duration()<<std::endl;
        }

        increment_timer+=0.001;

        if(increment_timer>duration_){
            thread_1=0;
        }

        std::cout<<"ttot:"<<increment_timer<<" endpos:"<<pos[0]<<" endvel:"<<vel[0]<<" endacc:"<<acc[0]<<std::endl;

    }

    if(thread_2){
        ruckig::Result r=otg.update(in,out);
        std::array<double,1> pos,vel,acc;
        out.trajectory.at_time(0.001,pos,vel,acc);

        svec.push_back(pos[0]);
        vvec.push_back(vel[0]);
        avec.push_back(acc[0]);
        myOpenGl->setj0vec(vvec);
        myOpenGl->setj1vec(svec);
        myOpenGl->setj2vec(avec);

        in.current_position[0]=pos[0];
        in.current_velocity[0]=vel[0];
        in.current_acceleration[0]=acc[0];

        if(r==ruckig::Result::Finished){
            std::cout<<"Finished"<<std::endl;
            thread_2=0;
        }
    }
}

typedef double T;

//! To create a scurved motion over segments with the same vm, we collect the segements and calculate stot.
//! To avoid a vel transition with acc=0, we test this method to find the transition ace.
void MainWindow::on_pushButton_short_segment_pressed(){

    T a=ui->doubleSpinBox_a->value();
    T jm=ui->doubleSpinBox_jm->value();
    T vm=ui->doubleSpinBox_vm->value();

    T vo=ui->doubleSpinBox_vo->value();
    T ve=ui->doubleSpinBox_vo->value();

    T acs=ui->doubleSpinBox_acs->value();
    T ace=ui->doubleSpinBox_ace->value();
    T s=0;

    std::vector<double> segments;
    segments.push_back(0.1);
    segments.push_back(segments.back()+0.15);
    segments.push_back(segments.back()+0.13);
    segments.push_back(segments.back()+1);
    segments.push_back(segments.back()+10);
    segments.push_back(segments.back()+100);
    segments.push_back(segments.back()+0.1);
    segments.push_back(segments.back()+0.15);
    segments.push_back(segments.back()+0.13);

    s+=segments.back();
    std::cout<<"short segments stot:"<<s<<std::endl;

    //! Inputs:
    in.max_acceleration[0]=a;
    in.max_jerk[0]=jm;
    in.max_velocity[0]=vm;

    in.current_position[0]=0;
    in.current_velocity[0]=vo;
    in.current_acceleration[0]=acs;

    in.target_position[0]=s;
    in.target_velocity[0]=ve;
    in.target_acceleration[0]=ace;

    opengl_clear();

    uint i=0;
    uint j=0;
    while (otg.update(in, out) == ruckig::Result::Working) {

        out.pass_to_input(in);
        opengl_add(out.new_position[0],out.new_velocity[0],out.new_acceleration[0]);

        //! Check the vector positions.
        for(i=j; i<segments.size(); i++){
            if(out.new_position[0]>segments.at(i)){
                j=i;
                std::cout<<"segment i:"<<i<<" pos:"<<out.new_position[0]<<std::endl;
                break;
            }
        }

    }
}

void MainWindow::opengl_clear(){
    vvec.clear();
    svec.clear();
    avec.clear();
    myOpenGl->setj0vec(vvec);
    myOpenGl->setj1vec(svec);
    myOpenGl->setj2vec(avec);
}

void MainWindow::opengl_add(T pos, T vel,T acc){
    svec.push_back(pos);
    vvec.push_back(vel);
    avec.push_back(acc);
    myOpenGl->setj0vec(vvec);
    myOpenGl->setj1vec(svec);
    myOpenGl->setj2vec(avec);
}
void MainWindow::on_doubleSpinBox_tarpos_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_vm_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_a_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_jm_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_vo_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_ve_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_s_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_acs_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}

void MainWindow::on_doubleSpinBox_ace_valueChanged(double arg1)
{
    on_pushButton_run_pressed();
}


