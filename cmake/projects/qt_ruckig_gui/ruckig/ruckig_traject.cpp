#include "ruckig_traject.h"

ruckig_traject::ruckig_traject()
{

}




//! Set ruckig inputs, use some defaults.
void ruckig_traject::ruckig_calc(double maxacc, double maxjerk, double maxvel,
                                 double curpos, double curvel, double curacc,
                                 double tarpos, double tarvel, double taracc,
                                 double *newpos, double *newvel, double *newacc){

    ruckig::InputParameter<1> in;
    ruckig::OutputParameter<1> out;
    std::array<double, 1> vel, acc, pos;

    ruckig::Ruckig<1> otg {0.001};
    ruckig::Result result;

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

    in.max_acceleration[0]=maxacc; // 2
    in.max_jerk[0]=maxjerk; // 4
    in.max_velocity[0]=maxvel; // 10

    in.current_position[0]=curpos;
    in.current_velocity[0]=curvel;
    in.current_acceleration[0]=curacc;

    in.target_position[0]=tarpos;
    in.target_velocity[0]=tarvel;
    in.target_acceleration[0]=taracc;

    result=otg.update(in, out);

    double cycle_time=0.001;
    if(out.trajectory.get_duration()<0.001){
        cycle_time=out.trajectory.get_duration();

        *newpos=in.target_position[0];
        *newvel=in.target_velocity[0];
        *newacc=in.target_acceleration[0];

        std::cout<<"ending ruckig motion"<<std::endl;
        return;
    }

    out.trajectory.at_time(cycle_time,pos, vel, acc);

    *newpos=pos[0];
    *newvel=vel[0];
    *newacc=acc[0];
}

//! Allocate memory for new sc_planner.
extern "C" ruckig_traject* ruckig_init_c(ruckig_traject *ptr){
    ptr=new ruckig_traject();
    return ptr;
}

