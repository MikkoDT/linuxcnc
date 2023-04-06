
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
#include "ruckig/sc_ruckig.h"

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
*tp_array_counter,
*tp_direction,
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
*tc_motiontype,
*tc_canon_motiontype,
*tp_curpos_x,
*tp_curpos_y,
*tp_curpos_z;


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




    //! Output pins, type parameter bit.
    tp_gcode_print = (param_bit_data_t*)hal_malloc(sizeof(param_bit_data_t));
    r+=hal_param_bit_new("sc-tp.tp_gcode_print",HAL_RW,&(tp_gcode_print->Pin),comp_idx);

    tp_gcode_optimize = (param_bit_data_t*)hal_malloc(sizeof(param_bit_data_t));
    r+=hal_param_bit_new("sc-tp.tp_gcode_optimize",HAL_RW,&(tp_gcode_optimize->Pin),comp_idx);

    tp_run = (param_bit_data_t*)hal_malloc(sizeof(param_bit_data_t));
    r+=hal_param_bit_new("sc-tp.tp_run",HAL_RW,&(tp_run->Pin),comp_idx);


    //! Integer pins.
    tp_gcode_buffer_size= (s32_data_t*)hal_malloc(sizeof(s32_data_t));
    r+=hal_pin_s32_new("sc-tp.gcode_buffer_size",HAL_OUT,&(tp_gcode_buffer_size->Pin),comp_idx);

    tp_gcode_loaded_lines= (s32_data_t*)hal_malloc(sizeof(s32_data_t));
    r+=hal_pin_s32_new("sc-tp.tp_gcode_loaded_lines",HAL_OUT,&(tp_gcode_loaded_lines->Pin),comp_idx);


    //! Integer parameters.
    tp_done = (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.done",HAL_RW,&(tp_done->Pin),comp_idx);


    tp_array_counter= (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.array_counter",HAL_RW,&(tp_array_counter->Pin),comp_idx);

    tp_current_gcode_line = (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.gcode_current_line",HAL_RW,&(tp_current_gcode_line->Pin),comp_idx);

    tp_direction = (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.direction",HAL_RW,&(tp_direction->Pin),comp_idx);

    //! Float parameters.
    tp_curpos_x = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.curpos_x",HAL_RW,&(tp_curpos_x->Pin),comp_idx);

    tp_curpos_y = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.curpos_y",HAL_RW,&(tp_curpos_y->Pin),comp_idx);

    tp_curpos_z = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.curpos_z",HAL_RW,&(tp_curpos_z->Pin),comp_idx);

    return r;
}

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

//! Skynet.
EmcPose tp_current_emc_pose;
EmcPose tp_gcode_last_pose;

int gcode_last_loaded_line_nr;
T vm=15;
T a=15;
T jm=15;
T cycle_time=0;

T traject_lenght=0;

B lcnc_pause_request=0;

T *ptr_path_lenghts;
int ptr_path_size;
T traject_lenght;
int ptr_path_exec;

struct sc_pnt xyz;
struct sc_dir abc;
struct sc_ext uvw;

struct sc_block *pvec;
int pvec_exec_nr;
int pvec_size;

bool gcode_optimized=0;

//! Ruckig stuff.
//! A nice ruckig gui example to test your stuff : ~/linuxcnc/cmake/projects/qt_ruckig_gui/mainwindow.cpp

bool ruckig_init=0;
sc_ruckig *ruckig_ptr;
//! Ruckig vars.
T curpos=0, curvel=0, curacc=0;
T incpos=0, newvel=0, newacc=0;
T newpos=0, oldpos=0;
B finished=0;
T sfront=0;

inline void update_gui();

enum sc_ruckig_state {
    sc_ruckig_none,
    sc_ruckig_finished,
    sc_ruckig_run,
    sc_ruckig_stop,
    sc_ruckig_pause,
    sc_ruckig_pause_resume,
    sc_ruckig_wait
};

extern sc_ruckig* ruckig_init_ptr();
extern V ruckig_set_a_jm(sc_ruckig *ptr, T maxacc, T jerkmax);
extern V ruckig_set_vm(sc_ruckig *ptr, T velmax);
extern V ruckig_run(sc_ruckig *ptr, T tarpos, T tarvel, T taracc);
extern V ruckig_stop(sc_ruckig *ptr);
extern V ruckig_pause(sc_ruckig *ptr);
extern V ruckig_pause_resume(sc_ruckig *ptr);
extern V ruckig_set_mempos(sc_ruckig *ptr, T value);
extern B ruckig_update(sc_ruckig *ptr, T *mempos, T *newvel, T *newacc);
//! Status callback.
extern enum sc_ruckig_state ruckig_get_state(sc_ruckig *ptr);
enum sc_ruckig_state state;
extern B ruckig_state_run(sc_ruckig *ptr);
extern B ruckig_state_stop(sc_ruckig *ptr);
extern B ruckig_state_pause(sc_ruckig *ptr);
extern B ruckig_state_pause_resume(sc_ruckig *ptr);
extern B ruckig_state_finished(sc_ruckig *ptr);

extern T ruckig_get_a(sc_ruckig *ptr);
extern T ruckig_get_jm(sc_ruckig *ptr);
extern T ruckig_get_vm(sc_ruckig *ptr);

//! Id was optional input, for setup hal pins.
int tpCreate(TP_STRUCT * const tp, int _queueSize,int id)
{
    //! Loads a gcode line to prevent slow down lcnc at startup.
    tp_done->Pin=1;

    traject_lenght=0;

    ruckig_ptr=ruckig_init_ptr();

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

            ruckig_set_a_jm(ruckig_ptr, a, jm);
            ruckig_set_vm(ruckig_ptr,vm);
            ruckig_run(ruckig_ptr,ptr_path_lenghts[ptr_path_exec],0,0);

            if(ptr_path_exec<ptr_path_size){
                ptr_path_exec++;
            } else {
                tp_done->Pin=1; //! Eof.
                ptr_path_exec=0;
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

            //! Only update ruckig if values are changed.
            if(jm!=ruckig_get_jm(ruckig_ptr) || a!=ruckig_get_a(ruckig_ptr)){
                ruckig_set_a_jm(ruckig_ptr, a, jm);
            }
            if(vm!=ruckig_get_vm(ruckig_ptr)){
                ruckig_set_vm(ruckig_ptr,vm);
            }

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

//! This functions only updates the gui preview path, and sets the current pose, cq 3d state of the machine.
//! We use this as inline, that means it gets compiled into the main function, instead of a function call.
//! Inline is little faster during runtime.
inline void update_gui(){

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
    tp_direction->Pin=dir;
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

#undef MAKE_TP_HAL_PINS







































