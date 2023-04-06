
#include "rtapi.h"
#include "rtapi_ctype.h"
#include "rtapi_app.h"
#include "rtapi_string.h"
#include "rtapi_errno.h"
#include "rtapi_math64.h"
#include <rtapi_io.h>
#include "hal.h"
#include "stdio.h"

#include "sc_struct.h"
#include "sc_extern.h"
#include "sc_block.h"
#include "sc_conversion.h"
#include "sc_interpolate.h"

#include "emcpose.h"
#include "motion.h"
#include "tc.h"

/*

To run this :
~/linuxcnc/cmake/components/sc_tp/$ ./runtest

When axis is up :
1. home all
2. run

Then open a hal viewer and set pins, params :
1. done = 1.
2. optimize = 1.
3. run = 1.
4. toggle pause.

*/

/* module information */
MODULE_AUTHOR("Skynet_Cyberdyne");
MODULE_DESCRIPTION("sc_tp");
MODULE_LICENSE("GPL2");

static int comp_idx;

typedef struct {
    bool ok;
} skynet_t;
skynet_t *skynet;

typedef struct {
    hal_float_t *Pin;
} float_data_t;

//! Pins
typedef struct {
    hal_bit_t *Pin;
} bit_data_t;
bit_data_t
*module,
*state_stop,
*state_run,
*state_wait,
*state_finished;

typedef struct { //! Int.
    hal_s32_t *Pin;
} s32_data_t;
s32_data_t
*tp_gcode_buffer_size,
*tp_gcode_loaded_lines;

typedef struct { //! Param int.
    hal_s32_t Pin;
} param_s32_data_t;
param_s32_data_t
*tp_done,
*tp_current_gcode_line;

typedef struct { //! Uint.
    hal_u32_t *Pin;
} u32_data_t;

typedef struct { //! Param Uint.
    hal_u32_t Pin;
} param_u32_data_t;

typedef struct {
    hal_port_t *Pin;
} port_data_t;
port_data_t *port;

//! Params
typedef struct {
    hal_float_t Pin;
} param_float_data_t;
param_float_data_t
*jm_rw_f, //! Jerk max.
*af_rw_f; //! Adaptive feed 0-1.

typedef struct {
    hal_bit_t Pin;
} param_bit_data_t;
param_bit_data_t
*tp_gcode_print,
*tp_gcode_optimize,
*tp_run;

static int comp_idx; /* component ID */

static void the_function();
static int setup_pins();

int rtapi_app_main(void) {

    int r = 0;
    comp_idx = hal_init("sc_tp");
    if(comp_idx < 0) return comp_idx;
    r = hal_export_funct("sc-tp", the_function, &skynet,0,0,comp_idx);

    r+=setup_pins();

    if(r) {
        hal_exit(comp_idx);
    } else {
        hal_ready(comp_idx);
    }
    return 0;
}

void rtapi_app_exit(void){
    hal_exit(comp_idx);
}

//! Perforn's every ms.
static void the_function(){
    *module->Pin=1;
}

static int setup_pins(){
    int r=0;

    //! Output pins, type bit.
    module = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
    r+=hal_pin_bit_new("sc-tp.module",HAL_OUT,&(module->Pin),comp_idx);

    state_run = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
    r+=hal_pin_bit_new("sc-tp.state_run",HAL_OUT,&(state_run->Pin),comp_idx);

    state_stop = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
    r+=hal_pin_bit_new("sc-tp.state_stop",HAL_OUT,&(state_stop->Pin),comp_idx);

    state_wait = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
    r+=hal_pin_bit_new("sc-tp.state_wait",HAL_OUT,&(state_wait->Pin),comp_idx);

    state_finished = (bit_data_t*)hal_malloc(sizeof(bit_data_t));
    r+=hal_pin_bit_new("sc-tp.state_finished",HAL_OUT,&(state_finished->Pin),comp_idx);


    //! Parameter bit.
    tp_gcode_print = (param_bit_data_t*)hal_malloc(sizeof(param_bit_data_t));
    r+=hal_param_bit_new("sc-tp.print",HAL_RW,&(tp_gcode_print->Pin),comp_idx);

    tp_gcode_optimize = (param_bit_data_t*)hal_malloc(sizeof(param_bit_data_t));
    r+=hal_param_bit_new("sc-tp.optimize",HAL_RW,&(tp_gcode_optimize->Pin),comp_idx);

    tp_run = (param_bit_data_t*)hal_malloc(sizeof(param_bit_data_t));
    r+=hal_param_bit_new("sc-tp.run",HAL_RW,&(tp_run->Pin),comp_idx);

    //! Parameter float.
    jm_rw_f = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.jm",HAL_RW,&(jm_rw_f->Pin),comp_idx);

    af_rw_f = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.adaptive_feed",HAL_RW,&(af_rw_f->Pin),comp_idx);

    //! Integer pins.
    tp_gcode_buffer_size= (s32_data_t*)hal_malloc(sizeof(s32_data_t));
    r+=hal_pin_s32_new("sc-tp.buffer_size",HAL_OUT,&(tp_gcode_buffer_size->Pin),comp_idx);

    tp_gcode_loaded_lines= (s32_data_t*)hal_malloc(sizeof(s32_data_t));
    r+=hal_pin_s32_new("sc-tp.loaded_gcode_lines",HAL_OUT,&(tp_gcode_loaded_lines->Pin),comp_idx);

    //! Integer parameters.
    tp_done = (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.done",HAL_RW,&(tp_done->Pin),comp_idx);

    tp_current_gcode_line = (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.gcode_current_line",HAL_RW,&(tp_current_gcode_line->Pin),comp_idx);

    return r;
}


//! Status and config from motion.h
static emcmot_status_t *emcmotStatus;
static emcmot_config_t *emcmotConfig;

//==========================================================
// tp module interface
// motmod function ptrs for functions called by tp:
static void(  *_DioWrite)(int,char);
static void(  *_AioWrite)(int,double);
static void(  *_SetRotaryUnlock)(int,int);
static int (  *_GetRotaryIsUnlocked)(int);
static double(*_axis_get_vel_limit)(int);
static double(*_axis_get_acc_limit)(int);

void tpMotFunctions(void(  *pDioWrite)(int,char)
                    ,void(  *pAioWrite)(int,double)
                    ,void(  *pSetRotaryUnlock)(int,int)
                    ,int (  *pGetRotaryIsUnlocked)(int)
                    ,double(*paxis_get_vel_limit)(int)
                    ,double(*paxis_get_acc_limit)(int)
                    )
{
    _DioWrite            = *pDioWrite;
    _AioWrite            = *pAioWrite;
    _SetRotaryUnlock     = *pSetRotaryUnlock;
    _GetRotaryIsUnlocked = *pGetRotaryIsUnlocked;
    _axis_get_vel_limit  = *paxis_get_vel_limit;
    _axis_get_acc_limit  = *paxis_get_acc_limit;
}

void tpMotData(emcmot_status_t *pstatus
               ,emcmot_config_t *pconfig
               )
{
    emcmotStatus = pstatus;
    emcmotConfig = pconfig;
}
//! Example how to get values :
//! printf("adaptive feed scale, feed overide.. : %f \n",emcmotStatus->net_feed_scale);
//! printf("emc config max feed scale: %f \n",emcmotConfig->maxFeedScale);


//! Skynet.
EmcPose tp_current_emc_pose;
EmcPose tp_gcode_last_pose;


void update_gui();

//! Current 3d position.
struct sc_pnt xyz;
struct sc_dir abc;
struct sc_ext uvw;

//! Holds lcnc recieved values.
T vm=15;
T a=15;
B reverse=0;

//! Gcode.
struct sc_block *pvec;
int pvec_exec_nr;
int pvec_size;

//! Gcode optimzer.
T *ptr_path_lenghts;
int ptr_path_size;
int ptr_path_exec;
T traject_lenght=0;
bool gcode_optimized=0;

//! Lcnc, for addLine, addArc.
int gcode_last_loaded_line_nr;

//! Ruckig stuff.
bool ruckig_init=0;
sc_ruckig *ruckig_ptr;
enum sc_ruckig_state {
    sc_ruckig_none,
    sc_ruckig_finished,
    sc_ruckig_run,
    sc_ruckig_stop,
    sc_ruckig_pause,
    sc_ruckig_pause_resume,
    sc_ruckig_wait
} state;
B last_reverse_state=0;
T feed_overide=0;
T curpos=0, curvel=0, curacc=0;
T newvel=0, newacc=0;

//! Id was optional input, for setup hal pins.
int tpCreate(TP_STRUCT * const tp, int _queueSize,int id)
{
    //! Loads a gcode line to prevent slow down lcnc at startup.
    tp_done->Pin=1;

    traject_lenght=0;

    ruckig_ptr=ruckig_init_ptr();

    if(jm_rw_f->Pin==0){
        rtapi_print_msg(RTAPI_MSG_ERR,"jerk max set to 15.");
        jm_rw_f->Pin=15;
    }
    if(af_rw_f->Pin==0){
        rtapi_print_msg(RTAPI_MSG_ERR,"adaptive feed set to 1.");
        af_rw_f->Pin=1;
    }

    return 0;
}

int tpClear(TP_STRUCT * const tp)
{
    pvec=NULL;
    return 0;
}

int tpInit(TP_STRUCT * const tp)
{
    return 0;
}

int tpSetCycleTime(TP_STRUCT * const tp, double secs)
{
    if(secs!=0.001){ //! Only check the cycle time. This time is fixed compiled in Ruckig.
        rtapi_print_msg(RTAPI_MSG_ERR,"cycle time != 0.001 sec.");
    }
    return 0;
}

int tpSetVmax(TP_STRUCT * const tp, double vMax, double ini_maxvel)
{
    // printf("vmax: %f \n",vMax);
    return 0;
}

int tpSetVlimit(TP_STRUCT * const tp, double vLimit)
{
    vm=vLimit;
    return 0;
}

int tpSetAmax(TP_STRUCT * const tp, double aMax)
{
    a=aMax;
    return 0;
}

//! Sets gcode line nr id for upcoming new line, arc.
int tpSetId(TP_STRUCT * const tp, int id)
{
    gcode_last_loaded_line_nr=id;
    return 0;
}

int tpGetExecId(TP_STRUCT * const tp)
{
    //! Using pvec:
    T nr=0;
    if(pvec_size>0){
        nr=pvec[pvec_exec_nr].gcode_line_nr;
        tp_current_gcode_line->Pin=nr;
    }
    return nr;
}

int tpSetTermCond(TP_STRUCT * const tp, int cond, double tolerance)
{
    // rtapi_print_msg(RTAPI_MSG_ERR,"set term cond\n");
    return 0;
}

int tpSetPos(TP_STRUCT * const tp, EmcPose const * const pos)
{
    // rtapi_print_msg(RTAPI_MSG_ERR,"set pos\n");

    //! For loading the gcode line by line, the startpoint of the
    //! first gcode line is *pos. From there the sequence is updated.
    tp_gcode_last_pose=*pos;
    return 0;
}

int tpSetCurrentPos(TP_STRUCT * const tp, EmcPose const * const pos)
{
    tp_current_emc_pose=*pos;
    // rtapi_print_msg(RTAPI_MSG_ERR,"set current pos\n");
    return 0;
}

int tpAddCurrentPos(TP_STRUCT * const tp, EmcPose const * const disp)
{
    // rtapi_print_msg(RTAPI_MSG_ERR,"add current pos\n");
    return 0;
}

int tpErrorCheck(TP_STRUCT const * const tp) {

    return 0;
}

//! map the input range of 0 to 1 to the output range of 0.000001 to 0.001,
//! you can use the following C function:
double convert_range(double val) {
  double output = val * 0.001 + 0.000001;
  if (output > 0.001) {
    output = 0.001;
  }
  return output;
}

int tpRunCycle(TP_STRUCT * const tp, long period)
{
    //! Print gcode.
    if(tp_gcode_print->Pin){

        block_print(pvec,pvec_size);
        tp_gcode_print->Pin=0;
    }

    //! Optimize gcode path, todo for ruckig.
    if(tp_gcode_optimize->Pin){

        traject_lenght=0;
        ptr_path_size=0;
        ptr_path_exec=0;

        optimize_gcode_c(pvec,pvec_size,vm,&ptr_path_lenghts,&ptr_path_size,&traject_lenght);

        printf("total pathlenght: %f \n",traject_lenght);
        printf("ptr path size: %i \n",ptr_path_size);
        printf("ptr path at 0: %f \n",ptr_path_lenghts[0]);

        tp_gcode_optimize->Pin=0; //! Reset.
        gcode_optimized=1;
    }

    state=ruckig_get_state(ruckig_ptr);

    if(tp_run->Pin){

        ruckig_update(ruckig_ptr,&curpos,&newvel,&newacc);

        switch (state) {
        case sc_ruckig_finished:
            *state_run->Pin=false;
            *state_stop->Pin=false;
            *state_wait->Pin=false;
            *state_finished->Pin=true;

            ruckig_set_a_jm(ruckig_ptr, a, jm_rw_f->Pin);
            ruckig_set_interval(ruckig_ptr,0.001);
            ruckig_set_vm(ruckig_ptr,vm);
            ruckig_run(ruckig_ptr,ptr_path_lenghts[ptr_path_exec],0,0);

            //! Forward motion finished, set to next gcode line.
            if(!reverse && ptr_path_exec<ptr_path_size){
                ptr_path_exec++;
            }
            //! Reverse motion finished, set to previous gcode line.
            if(reverse && ptr_path_exec>0){
                ptr_path_exec--;
            }
            //! Path completed. End.
            if(!reverse && ptr_path_exec==ptr_path_exec-1){
                tp_done->Pin=1; //! Triggers a lcnc stop.
            }
            break;
        case sc_ruckig_pause:
            *state_run->Pin=false;
            *state_stop->Pin=true;
            *state_wait->Pin=false;
            *state_finished->Pin=false;
            break;
        case sc_ruckig_pause_resume:
            *state_run->Pin=true;
            *state_stop->Pin=false;
            *state_wait->Pin=false;
            *state_finished->Pin=false;
            break;
        case sc_ruckig_run:
            *state_run->Pin=true;
            *state_stop->Pin=false;
            *state_wait->Pin=false;
            *state_finished->Pin=false;

            if(jm_rw_f->Pin==0){ //! Avoid a zero.
                jm_rw_f->Pin=0.1;
            }

            //! Only update ruckig if values are changed.
            //! Feed overide changed?
            T vm_with_vel_overide=vm*emcmotStatus->net_feed_scale;
            T vm_with_vel_overide_and_adaptive=vm_with_vel_overide*af_rw_f->Pin;

            if(vm_with_vel_overide_and_adaptive<0){ //! input range -1 to 1. -1 to -0 is negative feed.
                reverse=1; //! Set reverse.
            } else {
                reverse=0;
            }

            //! Jerk max changed?
            if(jm_rw_f->Pin!=ruckig_get_jm(ruckig_ptr) || a!=ruckig_get_a(ruckig_ptr)){
                ruckig_set_a_jm(ruckig_ptr, a, jm_rw_f->Pin);
            }
            //! Velocity max changed? Note: input positve velocity.
            if(fabs(vm_with_vel_overide_and_adaptive)!=ruckig_get_vm(ruckig_ptr)){
                ruckig_set_vm(ruckig_ptr,fabs(vm_with_vel_overide_and_adaptive));
            }

            //! Motion reverse changed?
            if(last_reverse_state!=reverse){
                if(reverse==1){ //! If reverse..
                    ruckig_run(ruckig_ptr,ptr_path_lenghts[(int)fmax(ptr_path_exec-1,0)],0,0);
                }
                if(reverse==0){ //! If forward, set target to end of segment.
                    ruckig_run(ruckig_ptr,ptr_path_lenghts[ptr_path_exec],0,0);
                }
                last_reverse_state=reverse;
            }

            // printf("adaptive feed scale, feed overide.. : %f \n",emcmotStatus->net_feed_scale);
            // printf("emc config max feed scale: %f \n",emcmotConfig->maxFeedScale);

            break;
        case sc_ruckig_wait: //! If state stop or pause is at vel=0, state becomes wait.
            *state_run->Pin=false;
            *state_stop->Pin=false;
            *state_wait->Pin=true;
            *state_finished->Pin=false;
            break;
        case sc_ruckig_stop:
            *state_run->Pin=false;
            *state_stop->Pin=true;
            *state_wait->Pin=false;
            *state_finished->Pin=false;
            break;
        case sc_ruckig_none:
            *state_run->Pin=false;
            *state_stop->Pin=false;
            *state_wait->Pin=false;
            *state_finished->Pin=false;

            //! Set run state, then will jump to finish state.
            ruckig_run(ruckig_ptr,0,0,0);
            break;
        default:
            break;
        }
    }

    update_gui();

    return 0;
}

void update_gui(){

    T traject_progress=curpos/traject_lenght;
    //! Test interpolate traject. For test just increment each cycle.

    if(pvec_size>0){
        T curve_progress=0;
        interpolate_traject(pvec,pvec_size,traject_progress,traject_lenght,&curve_progress,&pvec_exec_nr);
        //traject_progress+=0.00001;


        if(pvec[pvec_exec_nr].primitive_id==sc_line){
            interpolate_line_c(pvec[pvec_exec_nr].pnt_s,
                               pvec[pvec_exec_nr].pnt_e,
                               curve_progress,
                               &xyz);
        }
        if(pvec[pvec_exec_nr].primitive_id==sc_arc){
            interpolate_arc_c(pvec[pvec_exec_nr].pnt_s,
                              pvec[pvec_exec_nr].pnt_w,
                              pvec[pvec_exec_nr].pnt_e,
                              curve_progress,
                              &xyz);
        }
        tp_current_emc_pose.tran.x=xyz.x;
        tp_current_emc_pose.tran.y=xyz.y;
        tp_current_emc_pose.tran.z=xyz.z;

        interpolate_dir_c(pvec[pvec_exec_nr].dir_s,
                          pvec[pvec_exec_nr].dir_e,
                          curve_progress,
                          &abc);
        tp_current_emc_pose.a=abc.a;
        tp_current_emc_pose.b=abc.b;
        tp_current_emc_pose.c=abc.c;

        interpolate_ext_c(pvec[pvec_exec_nr].ext_s,
                          pvec[pvec_exec_nr].ext_e,
                          curve_progress,
                          &uvw);
        tp_current_emc_pose.u=uvw.u;
        tp_current_emc_pose.v=uvw.v;
        tp_current_emc_pose.w=uvw.w;

        //! Update emc with some values.
        emcmotConfig->trajCycleTime=0.001;
        emcmotStatus->distance_to_go=traject_lenght-curpos;

        EmcPose pose;
        pose.tran.x=pvec[pvec_exec_nr].pnt_e.x-xyz.x;
        pose.tran.y=pvec[pvec_exec_nr].pnt_e.y-xyz.y;
        pose.tran.z=pvec[pvec_exec_nr].pnt_e.z-xyz.z;
        emcmotStatus->dtg=pose;
        emcmotStatus->current_vel=newvel;

        //printf("adaptive feed: %f \n",*emcmot_hal_data->adaptive_feed);
    }
}

int tpSetSpindleSync(TP_STRUCT * const tp, int spindle, double sync, int mode) {
    return 0;
}

int tpPause(TP_STRUCT * const tp)
{
    // printf("pause \n");
    ruckig_pause(ruckig_ptr);
    return 0;
}

int tpResume(TP_STRUCT * const tp)
{
    // printf("resume \n");
    ruckig_pause_resume(ruckig_ptr);
    return 0;
}

int tpAbort(TP_STRUCT * const tp)
{
    // printf("abort \n");
    ruckig_stop(ruckig_ptr);
    return 0;
}

int tpGetMotionType(TP_STRUCT * const tp)
{
    return tp->motionType;
}

//! Update gui dro's.
int tpGetPos(TP_STRUCT const * const tp, EmcPose * const pos)
{
    // tp_current_emc_pose.tran.x=tp_curpos_x->Pin; //! To test.
    *pos=tp_current_emc_pose;
    return 0;
}

int tpIsDone(TP_STRUCT * const tp)
{
    return tp_done->Pin;
}

int tpQueueDepth(TP_STRUCT * const tp)
{
    return 0;
}

int tpActiveDepth(TP_STRUCT * const tp)
{
    return 0;
}

int tpSetAout(TP_STRUCT * const tp, unsigned char index, double start, double end) {
    return 0;
}

int tpSetDout(TP_STRUCT * const tp, int index, unsigned char start, unsigned char end) {
    return 0;
}

int tpSetRunDir(TP_STRUCT * const tp, tc_direction_t dir)
{
    //! Forward=0, reverse=1;
     //reverse_rw_int->Pin=dir;
    return 0;
}

struct state_tag_t tpGetExecTag(TP_STRUCT * const tp)
{

}

//! This function is responsible for long startup delay if return=1.
int tcqFull(TC_QUEUE_STRUCT const * const tcq)
{
    return 0;
}

int tpAddRigidTap(TP_STRUCT * const tp,
                  EmcPose end,
                  double vel,
                  double ini_maxvel,
                  double acc,
                  unsigned char enables,
                  double scale,
                  struct state_tag_t tag) {
    rtapi_print_msg(RTAPI_MSG_ERR,"add rigid tap, setId \n");

    return 0;
}

int tpAddLine(TP_STRUCT *
              const tp,
              EmcPose end,
              int canon_motion_type,
              double vel,
              double ini_maxvel,
              double acc,
              unsigned char enables,
              char atspeed,
              int indexer_jnum,
              struct state_tag_t tag)


{
    // A way to store gcode into a pvec.
    struct sc_block b;
    b.primitive_id=sc_line;
    b.type=canon_motion_type;
    b.pnt_s=emc_pose_to_sc_pnt(tp_gcode_last_pose);
    b.pnt_e=emc_pose_to_sc_pnt(end);

    b.dir_s=emc_pose_to_sc_dir(tp_gcode_last_pose);
    b.dir_e=emc_pose_to_sc_dir(end);

    b.ext_s=emc_pose_to_sc_ext(tp_gcode_last_pose);
    b.ext_e=emc_pose_to_sc_ext(end);

    b.gcode_line_nr=gcode_last_loaded_line_nr;

    b.vo=0;
    b.vm=vm;
    b.ve=0;

    b.path_lenght=line_lenght_c(b.pnt_s,b.pnt_e);
    traject_lenght+=b.path_lenght;

    block_add(&pvec,&pvec_size,b);

    //! Update last pose to end of gcode block.
    tp_gcode_last_pose=end;

    //! End of request.
    tp_done->Pin=0;

    //! Update loaded items to hal.
    *tp_gcode_loaded_lines->Pin=pvec_size;

    return 0;
}

int tpAddCircle(TP_STRUCT * const tp,
                EmcPose end,
                PmCartesian center,
                PmCartesian normal,
                int turn,
                int canon_motion_type, //! arc_3->lin_2->GO_1
                double vel,
                double ini_maxvel,
                double acc,
                unsigned char enables,
                char atspeed,
                struct state_tag_t tag)
{
    struct sc_block b;
    b.primitive_id=sc_arc;
    b.type=canon_motion_type;
    b.pnt_s=emc_pose_to_sc_pnt(tp_gcode_last_pose);

    b.dir_s=emc_pose_to_sc_dir(tp_gcode_last_pose);
    b.dir_e=emc_pose_to_sc_dir(end);

    b.ext_s=emc_pose_to_sc_ext(tp_gcode_last_pose);
    b.ext_e=emc_pose_to_sc_ext(end);

    //! Create a 3d arc using waypoint technique.
    sc_arc_get_mid_waypoint_c(emc_pose_to_sc_pnt(tp_gcode_last_pose),
                              emc_cart_to_sc_pnt(center),
                              emc_pose_to_sc_pnt(end),&b.pnt_w);

    b.pnt_e=emc_pose_to_sc_pnt(end);
    b.gcode_line_nr=gcode_last_loaded_line_nr;

    b.vo=0;
    b.vm=vm;
    b.ve=0;

    b.path_lenght=arc_lenght_c(b.pnt_s,b.pnt_w,b.pnt_e);
    traject_lenght+=b.path_lenght;

    block_add(&pvec,&pvec_size,b);

    //! Update last pose to end of gcode block.
    tp_gcode_last_pose=end;

    //! End of request.
    tp_done->Pin=0;

    //! Update loaded items to hal.
    *tp_gcode_loaded_lines->Pin=pvec_size;

    return 0;
}

void tpToggleDIOs(TC_STRUCT * const tc) {

}


EXPORT_SYMBOL(tpMotFunctions);
EXPORT_SYMBOL(tpMotData);

EXPORT_SYMBOL(tpAbort);
EXPORT_SYMBOL(tpActiveDepth);
EXPORT_SYMBOL(tpAddCircle);
EXPORT_SYMBOL(tpAddLine);
EXPORT_SYMBOL(tpAddRigidTap);
EXPORT_SYMBOL(tpClear);
EXPORT_SYMBOL(tpCreate);
EXPORT_SYMBOL(tpGetExecId);
EXPORT_SYMBOL(tpGetExecTag);
EXPORT_SYMBOL(tpGetMotionType);
EXPORT_SYMBOL(tpGetPos);
EXPORT_SYMBOL(tpIsDone);
EXPORT_SYMBOL(tpPause);
EXPORT_SYMBOL(tpQueueDepth);
EXPORT_SYMBOL(tpResume);
EXPORT_SYMBOL(tpRunCycle);
EXPORT_SYMBOL(tpSetAmax);
EXPORT_SYMBOL(tpSetAout);
EXPORT_SYMBOL(tpSetCycleTime);
EXPORT_SYMBOL(tpSetDout);
EXPORT_SYMBOL(tpSetId);
EXPORT_SYMBOL(tpSetPos);
EXPORT_SYMBOL(tpSetRunDir);
EXPORT_SYMBOL(tpSetSpindleSync);
EXPORT_SYMBOL(tpSetTermCond);
EXPORT_SYMBOL(tpSetVlimit);
EXPORT_SYMBOL(tpSetVmax);
EXPORT_SYMBOL(tcqFull);






































