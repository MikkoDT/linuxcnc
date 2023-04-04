#include "sc_ruckig.h"

sc_ruckig::sc_ruckig()
{

}

V sc_ruckig::set_a_jm(T maxacc, T jerkmax){
    in.max_acceleration[0]=maxacc;
    in.max_jerk[0]=jerkmax;

    //! enum: position, velocity
    in.control_interface=ruckig::ControlInterface::Position;
    //! Phase, ///< Phase synchronize the DoFs when possible, else fallback to "Time" strategy
    //! Time, ///< Always synchronize the DoFs to reach the target at the same time (Default)
    //! TimeIfNecessary, ///< Synchronize only when necessary (e.g. for non-zero target velocity or acceleration)
    //! None, ///< Calculate every DoF independently
    in.synchronization=ruckig::Synchronization::None;
    //! Continuous, ///< Every trajectory duration is allowed (Default), in lcnc this is called the split cycle.
    //! Discrete, ///< The trajectory duration must be a multiple of the control cycle
    in.duration_discretization=ruckig::DurationDiscretization::Continuous;

    in.enabled[0]=1;
}

V sc_ruckig::set_target(T tarpos, T tarvel, T taracc){
    in.target_position[0]=tarpos;
    in.target_velocity[0]=tarvel;
    in.target_acceleration[0]=taracc;
}

V sc_ruckig::set_current(T curpos, T curvel, T curacc){
    in.current_position[0]=curpos;
    in.current_velocity[0]=curvel;
    in.current_acceleration[0]=curacc;
}

V sc_ruckig::set_vm(T maxvel){
    in.max_velocity[0]=maxvel;

     // std::cout<<"sc_ruckig maxvel:"<<maxvel<<std::endl;
}

V sc_ruckig::calculate(){
    result=otg.update(in, out);
    duration=out.trajectory.get_duration();

    // std::cout<<"sc_ruckig calculated duration:"<<duration<<std::endl;

    at_time=0; //! Reset.
}

//! Finished returns 1.
B sc_ruckig::update(T *newpos, T *newvel, T *newacc){

    std::array<double, 1> vel, acc, pos;

    out.trajectory.at_time(std::min(at_time,duration),pos, vel, acc);
    at_time+=0.001;

    *newpos=pos[0];
    *newvel=vel[0];
    *newacc=acc[0];


    // std::cout<<"update at_time:"<<at_time<<std::endl;
    // std::cout<<"newpos:"<<pos[0]<<std::endl;

    //! Finished.
    if(at_time>duration){
        return 1;
    }
    //! Not finished.
    return 0;
}

//! Create intance.
extern "C" sc_ruckig* ruckig_init_c(){
    return new sc_ruckig();
}

extern "C" V ruckig_set_a_jm_c(sc_ruckig *ptr, T maxacc, T jerkmax){
    ptr->set_a_jm(maxacc,jerkmax);
}

extern "C" V ruckig_set_target_c(sc_ruckig *ptr, T tarpos, T tarvel, T taracc){
    ptr->set_target(tarpos,tarvel,taracc);
}

extern "C" V ruckig_set_current_c(sc_ruckig *ptr, T curpos, T curvel, T curacc){
    ptr->set_current(curpos,curvel,curacc);
}

extern "C" V ruckig_set_vm_c(sc_ruckig *ptr, T velmax){
    ptr->set_vm(velmax);
}

extern "C" V ruckig_calculate(sc_ruckig *ptr){
    ptr->calculate();
}

extern "C" B ruckig_update(sc_ruckig *ptr, T *newpos, T *newvel, T *newacc){
    return ptr->update(newpos,newvel,newacc);
}












