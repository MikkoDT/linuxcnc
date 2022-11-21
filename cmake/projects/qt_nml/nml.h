#ifndef NML_H
#define NML_H

#include <config.h>

#include <emc.hh>
#include <emc_nml.hh>
#include <string.h>
#include <iostream>

class nml {
public:
    nml(){}

    struct status {
        bool estop=0;
        bool on=0;
        char task_active_gcodes_string[256];
        char task_active_mcodes_string[256];
        char task_active_fcodes_string[256];
        char task_active_scodes_string[256];
        //! 0=manual 1=mdi 2=auto.
        int mode;
    } theStatus;

    void update(){
        for(int i=0; i<1; i++){
            usleep(1);
            if(!stat->valid()) continue;
            if(stat->peek() != EMC_STAT_TYPE) continue;
            emcStatus = static_cast<EMC_STAT*>(stat->get_address());
        }

        if(emcStatus->task.state== EMC_TASK_STATE_ENUM::EMC_TASK_STATE_ESTOP){
            theStatus.estop=true;
        } else {
            theStatus.estop=false;
        }

        if(emcStatus->task.state== EMC_TASK_STATE_ENUM::EMC_TASK_STATE_ON){
            theStatus.on=true;
        } else {
            theStatus.on=false;
        }

        if(emcStatus->task.mode==EMC_TASK_MODE_ENUM::EMC_TASK_MODE_MANUAL){
            theStatus.mode=0;
        }
        if(emcStatus->task.mode==EMC_TASK_MODE_ENUM::EMC_TASK_MODE_MDI){
            theStatus.mode=1;
        }
        if(emcStatus->task.mode==EMC_TASK_MODE_ENUM::EMC_TASK_MODE_AUTO){
            theStatus.mode=2;
        }

        char string[256];
        int t;
        int code;

        //! Active G codes
        theStatus.task_active_gcodes_string[0] = 0;
        for (t = 1; t < ACTIVE_G_CODES; t++) {
            code = emcStatus->task.activeGCodes[t];
            if (code == -1) {
                continue;
            }
            if (code % 10) {
                sprintf(string, "G%.1f ", (double) code / 10.0);
            } else {
                sprintf(string, "G%d ", code / 10);
            }
            strcat(theStatus.task_active_gcodes_string, string);
        }

        //! Active M codes.
        theStatus.task_active_mcodes_string[0] = 0;
        for (t = 1; t < ACTIVE_M_CODES; t++) {
            code = emcStatus->task.activeMCodes[t];
            if (code == -1) {
                continue;
            }
            sprintf(string, "M%d ", code);
            strcat(theStatus.task_active_mcodes_string, string);
        }

        //! Active F and S codes.
        sprintf(string, "F%.0f ", emcStatus->task.activeSettings[1]);
        theStatus.task_active_fcodes_string[0] = 0;
        strcat(theStatus.task_active_fcodes_string, string);
        sprintf(string, "S%.0f", abs(emcStatus->task.activeSettings[2]));
        theStatus.task_active_scodes_string[0] = 0;
        strcat(theStatus.task_active_scodes_string, string);


    }
    void machine_on(){
        EMC_TASK_SET_STATE s;
        s.state=EMC_TASK_STATE_ENUM(EMC_TASK_STATE_ON);
        cmd->write(&s);
    }
    void machine_off(){
        EMC_TASK_SET_STATE s;
        s.state=EMC_TASK_STATE_ENUM(EMC_TASK_STATE_OFF);
        cmd->write(&s);
    }
    void estop_reset(){
        EMC_TASK_SET_STATE s;
        s.state=EMC_TASK_STATE_ENUM(EMC_TASK_STATE_ESTOP_RESET);
        cmd->write(&s);
    }
    void estop(){
        EMC_TASK_SET_STATE s;
        s.state=EMC_TASK_STATE_ENUM(EMC_TASK_STATE_ESTOP);
        cmd->write(&s);
    }
    void teleop(){
        EMC_TRAJ_SET_MODE x;
        x.mode=EMC_TRAJ_MODE_TELEOP;
        cmd->write(&x);
    }
    void coord(){
        EMC_TRAJ_SET_MODE x;
        x.mode=EMC_TRAJ_MODE_COORD;
        cmd->write(&x);
    }
    void free(){
        EMC_TRAJ_SET_MODE x;
        x.mode=EMC_TRAJ_MODE_FREE;
        cmd->write(&x);
    }
    void home_x(){
        EMC_JOINT_HOME m;
        m.joint=0; //x
        cmd->write(&m);
    }
    void home_y(){
        EMC_JOINT_HOME m;
        m.joint=1;
        cmd->write(&m);
    }
    void home_z(){
        EMC_JOINT_HOME m;
        m.joint=2;
        cmd->write(&m);
    }
    void home_all(){
        EMC_JOINT_HOME m;
        m.joint=-1;
        cmd->write(&m);
    }
    void unhome_all(){
        EMC_JOINT_UNHOME m;
        m.joint=-1;
        cmd->write(&m);
    }
    void mode_auto(){
        EMC_TASK_SET_MODE m;
        m.mode=EMC_TASK_MODE_AUTO;
        cmd->write(&m);
    }
    void mode_mdi(){
        EMC_TASK_SET_MODE m;
        m.mode=EMC_TASK_MODE_MDI;
        cmd->write(&m);
    }
    void mode_manual(){
        EMC_TASK_SET_MODE m;
        m.mode=EMC_TASK_MODE_MANUAL;
        cmd->write(&m);
    }
    void run(){
        EMC_TASK_PLAN_RUN r;
        cmd->write(&r);
    }
    void pause(){
        EMC_TASK_PLAN_PAUSE p;
        cmd->write(&p);
    }
    void resume(){
        EMC_TASK_PLAN_RESUME r;
        cmd->write(&r);
    }
    void reverse(){
        EMC_TASK_PLAN_REVERSE r;
        cmd->write(&r);
    }
    void end(){
        EMC_TASK_PLAN_END e;
        cmd->write(&e);
    }
    void stop(){
        EMC_TASK_ABORT e;
        cmd->write(&e);
    }
    void load(){
        //! Mention, the drawing will not be displayed by a gui like axis. But the code is
        //! loaded and will run.

        EMC_TASK_PLAN_CLOSE m0;
        cmd->write(&m0);

        EMC_TASK_PLAN_OPEN o;
        strcpy(o.file, "/home/user/linuxcnc/nc_files/test.ngc");
        cmd->write(&o);
    }
    void spindle(float spindlespeed){
        EMC_SPINDLE_ON m;
        m.spindle=0;
        m.speed=spindlespeed;
        cmd->write(&m);
    }
    void jog(int axis, float speed){
        EMC_JOG_CONT j;
        j.jjogmode = 0;
        j.joint_or_axis = axis;
        j.vel = speed/60;
        cmd->write(&j);
    }
    void jog_stop(int axis){
        EMC_JOG_STOP s;
        s.jjogmode = 0;
        s.joint_or_axis=axis;
        cmd->write(&s);
    }

private:
    RCS_CMD_CHANNEL *cmd = new RCS_CMD_CHANNEL(emcFormat, "emcCommand", "xemc", EMC2_DEFAULT_NMLFILE);
    RCS_STAT_CHANNEL *stat = new RCS_STAT_CHANNEL(emcFormat, "emcStatus", "xemc", EMC2_DEFAULT_NMLFILE);
    EMC_STAT  *emcStatus;
};
#endif



















