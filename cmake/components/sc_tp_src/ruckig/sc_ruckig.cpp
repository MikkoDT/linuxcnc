#include "sc_ruckig.h"

sc_ruckig::sc_ruckig()
{

}

V sc_ruckig::set_a_jm(T maxacc, T jerkmax){
    myIn.max_acceleration[0]=maxacc;
    myIn.max_jerk[0]=jerkmax;

    //! Phase, ///< Phase synchronize the DoFs when possible, else fallback to "Time" strategy
    //! Time, ///< Always synchronize the DoFs to reach the target at the same time (Default)
    //! TimeIfNecessary, ///< Synchronize only when necessary (e.g. for non-zero target velocity or acceleration)
    //! None, ///< Calculate every DoF independently
    myIn.synchronization=ruckig::Synchronization::None;
    //! Continuous, ///< Every trajectory duration is allowed (Default), in lcnc this is called the split cycle.
    //! Discrete, ///< The trajectory duration must be a multiple of the control cycle
    myIn.duration_discretization=ruckig::DurationDiscretization::Continuous;

    myIn.enabled[0]=1;
}

V sc_ruckig::set_interval(T value){
    myInterval=value;
}

T sc_ruckig::get_a(){
    return myIn.max_acceleration[0];
}

T sc_ruckig::get_jm(){
    return myIn.max_jerk[0];
}

V sc_ruckig::set_target(T tarpos, T tarvel, T taracc){
    myIn.target_position[0]=tarpos-myMempos;
    myIn.target_velocity[0]=tarvel;
    myIn.target_acceleration[0]=taracc;
}

V sc_ruckig::set_current(T curpos, T curvel, T curacc){
    myIn.current_position[0]=curpos;
    myIn.current_velocity[0]=curvel;
    myIn.current_acceleration[0]=curacc;
}

V sc_ruckig::set_vm(T maxvel){

    myIn.max_velocity[0]=maxvel;
    //! Set new run path from here.
    run();
}

T sc_ruckig::get_vm(){
    return myIn.max_velocity[0];
}

V sc_ruckig::set_mem_pos(T value){
    myMempos=value;
}

V sc_ruckig::run(T tarpos, T tarvel, T taracc){
    set_target(tarpos,tarvel,taracc);
    run();
}

V sc_ruckig::run(){

    myState=sc_ruckig_run;

    //! enum: position, velocity
    myIn.control_interface=ruckig::ControlInterface::Position;

    set_current(0,myVel[0],myAcc[0]);

    ruckig::Ruckig<1> myOtg {myInterval}; //! Normally 0.001
    myResult=myOtg.update(myIn, myOut);
    myDuration=myOut.trajectory.get_duration();

    myAtTime=0; //! Reset.
    myOldpos=0;
}

V sc_ruckig::stop(){

    std::cout<<"ruckig stop request"<<std::endl;

    myState=sc_ruckig_stop;

    //! enum: position, velocity
    myIn.control_interface=ruckig::ControlInterface::Velocity;

    myIn.target_acceleration[0]=0;
    myIn.target_velocity[0]=0;

    set_current(0,myVel[0],myAcc[0]);

    ruckig::Ruckig<1> myOtg {myInterval}; //! Normally 0.001
    myResult=myOtg.update(myIn, myOut);
    myDuration=myOut.trajectory.get_duration();

    myAtTime=0; //! Reset.
    myOldpos=0;
}

V sc_ruckig::pause(){
    stop();
}

V sc_ruckig::pause_resume(){
    run();
}

//! Finished returns 1.
B sc_ruckig::update(T &incpos, T &mempos, T &newpos, T &newvel, T &newacc){

    myOut.trajectory.at_time(std::min(myAtTime,myDuration),myPos, myVel, myAcc);
    myAtTime+=0.001;

    newpos=myPos[0];
    incpos=myPos[0]-myOldpos;
    newvel=myVel[0];
    newacc=myAcc[0];

    myOldpos=myPos[0];

    myMempos+=incpos;
    mempos=myMempos;

    //! Finished.
    if(myAtTime>myDuration){

        //! If in pause, stay in pause state.
        if(myState==sc_ruckig_wait){
            return 1;
        }

        //! If stop complete, set wait state.
        if(myState==sc_ruckig_stop){
            myState=sc_ruckig_wait;
            return 1;
        }

        //! If run complete, set finished state.
        if(myState==sc_ruckig_run){
            myState=sc_ruckig_finished;
            return 1;
        }
    }
    //! Not finished.
    return 0;
}

sc_ruckig_state sc_ruckig::get_state(){
    return myState;
}

//! Create intance.
extern "C" sc_ruckig* ruckig_init_ptr(){
    return new sc_ruckig();
}

extern "C" V ruckig_set_a_jm(sc_ruckig *ptr, T maxacc, T jerkmax){
    ptr->set_a_jm(maxacc,jerkmax);
}

extern "C" V ruckig_set_interval(sc_ruckig *ptr, T value){
    ptr->set_interval(value);
}

extern "C" V ruckig_set_vm(sc_ruckig *ptr, T velmax){
    ptr->set_vm(velmax);
}

extern "C" V ruckig_run(sc_ruckig *ptr, T tarpos, T tarvel, T taracc){
    ptr->run(tarpos,tarvel,taracc);
}

extern "C" V ruckig_stop(sc_ruckig *ptr){
    ptr->stop();
}

extern "C" V ruckig_pause(sc_ruckig *ptr){
    ptr->stop();
}

extern "C" V ruckig_pause_resume(sc_ruckig *ptr){
    ptr->pause_resume();
}

extern "C" V ruckig_set_mempos(sc_ruckig *ptr, T value){
    ptr->set_mem_pos(value);
}

extern "C" B ruckig_update(sc_ruckig *ptr, T *mempos, T *newvel, T *newacc){

    //! Vars for converting c++ by reference to c pointer style.
    T incpos_=0, mempos_=0, newpos_=0, newvel_=0, newacc_=0;

    B finished=ptr->update(incpos_,mempos_,newpos_,newvel_,newacc_);

    *mempos=mempos_;
    *newvel=newvel_;
    *newacc=newacc_;

    return finished;
}

extern "C" T ruckig_get_vm(sc_ruckig *ptr){
    return ptr->get_vm();
}

extern "C" T ruckig_get_a(sc_ruckig *ptr){
    return ptr->get_a();
}

extern "C" T ruckig_get_jm(sc_ruckig *ptr){
    return ptr->get_jm();
}

extern "C" enum sc_ruckig_state ruckig_get_state(sc_ruckig *ptr){
    return ptr->get_state();
}

extern "C" B ruckig_state_run(sc_ruckig *ptr){
    if(ptr->get_state()==sc_ruckig_run){
        return 1;
    }
    return 0;
}

extern "C" B ruckig_state_pause(sc_ruckig *ptr){
    if(ptr->get_state()==sc_ruckig_stop){
        return 1;
    }
    return 0;
}

extern "C" B ruckig_state_stop(sc_ruckig *ptr){
    if(ptr->get_state()==sc_ruckig_stop){
        return 1;
    }
    return 0;
}

extern "C" B ruckig_state_pause_resume(sc_ruckig *ptr){
    if(ptr->get_state()==sc_ruckig_run){
        return 1;
    }
    return 0;
}

extern "C" B ruckig_state_finished(sc_ruckig *ptr){
    if(ptr->get_state()==sc_ruckig_finished){
        return 1;
    }
    return 0;
}

























