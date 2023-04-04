
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
bit_data_t *module;

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
*tp_pause,
*tp_stop,
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
*tp_curpos_z,
*tp_cycle_time,
*tp_velocity_max,
*tp_ini_velocity_max,
*tp_acceleration_max;

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

    tp_pause = (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.pause",HAL_RW,&(tp_pause->Pin),comp_idx);

    tp_stop= (param_s32_data_t*)hal_malloc(sizeof(param_s32_data_t));
    r+=hal_param_s32_new("sc-tp.stop",HAL_RW,&(tp_stop->Pin),comp_idx);

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

    tp_cycle_time = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.cycle_time",HAL_RW,&(tp_cycle_time->Pin),comp_idx);

    tp_velocity_max = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.velocity_max",HAL_RW,&(tp_velocity_max->Pin),comp_idx);

    tp_ini_velocity_max = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.ini_velocity_max",HAL_RW,&(tp_ini_velocity_max->Pin),comp_idx);

    tp_acceleration_max = (param_float_data_t*)hal_malloc(sizeof(param_float_data_t));
    r+=hal_param_float_new("sc-tp.acceleration_max",HAL_RW,&(tp_acceleration_max->Pin),comp_idx);

    return r;
}

#include "rtapi.h"
#include "posemath.h"
#include "emcpose.h"
#include "rtapi_math.h"
#include "motion.h"
#include "tc.h"

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
T vm=0;
T a=2;
T jm=4;
T cycle_time=0;
T traject_progress=0;
T traject_lenght=0;

//! Ruckig vars.
T curpos=0, curvel=0, curacc=0, newpos=0, newvel=0, newacc=0;
B finished=0;

T *ptr_path;
int ptr_path_size;
T traject_lenght;
int ptr_path_exec;

struct sc_pnt xyz;
struct sc_dir abc;
struct sc_ext uvw;

enum tp_gcode_primitive_id {
    line,
    arc
};

struct sc_block *pvec;
int pvec_exec_nr;
int pvec_size;

//! C style vector functions thanks to chatgdp, not verified.
void block_add(struct sc_block **blocks, int *num_blocks, struct sc_block new_block);
void block_insert_front(struct sc_block **pvec, int *size, struct sc_block *block);
void insert_at_index(struct sc_block **pvec, int *size, int index, struct sc_block *block);
void block_delete(struct sc_block **pvec, int *size, int index);
void block_pop_back(struct sc_block **pvec, int *size);
void block_pop_front(struct sc_block **pvec, int *size);
void block_print(struct sc_block *pvec, int size);

struct sc_pnt emc_pose_to_sc_pnt(EmcPose pose);
struct sc_dir emc_pose_to_sc_dir(EmcPose pose);
struct sc_ext emc_pose_to_sc_ext(EmcPose pose);
struct sc_pnt emc_cart_to_sc_pnt(PmCartesian pnt);
PmCartesian sc_pnt_to_emc_cart(struct sc_pnt pnt);


//! C++ source and header file compiled with this project.
//! Function call to c++.
extern V sc_arc_get_mid_waypoint_c(struct sc_pnt start,
                                   struct sc_pnt center,
                                   struct sc_pnt end,
                                   struct sc_pnt *waypoint);

//! Interpolation.
extern T arc_lenght_c(struct sc_pnt start, struct sc_pnt way, struct sc_pnt end);
extern T line_lenght_c(struct sc_pnt start, struct sc_pnt end);
extern V interpolate_line_c(struct sc_pnt p0, struct sc_pnt p1, T progress, struct sc_pnt *pi);
extern V interpolate_dir_c(struct sc_dir p0, struct sc_dir p1, T progress, struct sc_dir *pi);
extern V interpolate_ext_c(struct sc_ext p0, struct sc_ext p1, T progress, struct sc_ext *pi);
extern V interpolate_arc_c(struct sc_pnt p0, struct sc_pnt p1, struct sc_pnt p2, T progress, struct sc_pnt *pi);

extern T blocklenght_c(struct sc_block b);

//! Interpolates traject progress 0-1.
void interpolate_traject(struct sc_block *blockvec, int size, T traject_progress, T traject_lenght, T *curve_progress, int *curve_nr){

    T ltot=traject_lenght;
    T l=0;
    for(int i=0; i<size; i++){
        T blocklenght=blockvec[i].path_lenght;
        if(traject_progress>=l/ltot && traject_progress<(l+blocklenght)/ltot){

            T low_pct=l/ltot;                                   //10%
            T high_pct=(l+blocklenght)/ltot;                    //25%
            T range=high_pct-low_pct;                           //25-10=15%
            T offset_low=traject_progress-low_pct;              //12-10=2%
            *curve_progress=offset_low/range;
            *curve_nr=i;
            return;
        }
        l+=blocklenght;
    }
}

extern void optimize_gcode_c(struct sc_block *pvec, int size, T vm, T **path_lenghts, int *path_lenght_size, T *stot);

//! Ruckig stuff.
#include "ruckig/sc_ruckig.h"
bool init_ruckig=0;
sc_ruckig *ptr_ruckig;
T sfront=0;
extern sc_ruckig* ruckig_init_c();
extern V ruckig_set_a_jm_c(sc_ruckig *ptr, T maxacc, T jerkmax);
extern V ruckig_set_target_c(sc_ruckig *ptr, T tarpos, T tarvel, T taracc);
extern V ruckig_set_current_c(sc_ruckig *ptr, T curpos, T curvel, T curacc);
extern V ruckig_set_vm_c(sc_ruckig *ptr, T velmax);
extern V ruckig_calculate(sc_ruckig *ptr);
extern B ruckig_update(sc_ruckig *ptr, T *newpos, T *newvel, T *newacc);

//! Id was optional input, for setup hal pins.
int tpCreate(TP_STRUCT * const tp, int _queueSize,int id)
{

    //! Loads a gcode line to prevent slow down lcnc at startup.
    tp_done->Pin=1;

    traject_lenght=0;

    ptr_ruckig=ruckig_init_c();

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
    cycle_time=secs;
    tp_cycle_time->Pin=secs;

    return 0;
}

int tpSetVmax(TP_STRUCT * const tp, double vMax, double ini_maxvel)
{
    tp_velocity_max->Pin=vMax;
    tp_ini_velocity_max->Pin=ini_maxvel;
    return 0;
}

int tpSetVlimit(TP_STRUCT * const tp, double vLimit)
{
    vm=vLimit;
    tp_velocity_max->Pin=vLimit;

    return 0;
}

int tpSetAmax(TP_STRUCT * const tp, double aMax)
{
    a=aMax;
    tp_acceleration_max->Pin=aMax;

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
    rtapi_print_msg(RTAPI_MSG_ERR,"set term cond\n");
    return 0;
}

int tpSetPos(TP_STRUCT * const tp, EmcPose const * const pos)
{
    rtapi_print_msg(RTAPI_MSG_ERR,"set pos\n");

    //! For loading the gcode line by line, the startpoint of the
    //! first gcode line is *pos. From there the sequence is updated.
    tp_gcode_last_pose=*pos;
    return 0;
}

int tpSetCurrentPos(TP_STRUCT * const tp, EmcPose const * const pos)
{
    tp_current_emc_pose=*pos;
    rtapi_print_msg(RTAPI_MSG_ERR,"set current pos\n");
    return 0;
}

int tpAddCurrentPos(TP_STRUCT * const tp, EmcPose const * const disp)
{
    rtapi_print_msg(RTAPI_MSG_ERR,"add current pos\n");
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
        //ptr_path=NULL;
        ptr_path_exec=0;

        optimize_gcode_c(pvec,pvec_size,vm,&ptr_path,&ptr_path_size,&traject_lenght);

        printf("total pathlenght: %f \n",traject_lenght);
        printf("ptr path size: %i \n",ptr_path_size);
        printf("ptr path at 0: %f \n",ptr_path[0]);

        tp_gcode_optimize->Pin=0; //! Reset.
    }

    if(tp_run->Pin){ //! Run from line pvec line 0.


        if(!init_ruckig){

            ruckig_set_a_jm_c(ptr_ruckig, a, jm);
            ruckig_set_vm_c(ptr_ruckig, vm);

            ruckig_set_current_c(ptr_ruckig, 0, 0, 0);

            T tarpos=ptr_path[ptr_path_exec];
            // printf("tarpos: %f \n",tarpos);
            ruckig_set_target_c(ptr_ruckig, tarpos, 0, 0);

            //! Resets timer to zero.
            ruckig_calculate(ptr_ruckig);

            init_ruckig=1;
        }

        B finished=ruckig_update(ptr_ruckig, &newpos, &newvel, &newacc);

        if(finished){
            init_ruckig=0;
            printf("finished \n");

            sfront+=newpos;
            ptr_path_exec++;
        }


        traject_progress=(newpos+sfront)/traject_lenght;


        //! Test interpolate traject. For test just increment each cycle.
        T curve_progress;
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

    return 0;
}

int tpSetSpindleSync(TP_STRUCT * const tp, int spindle, double sync, int mode) {
    return 0;
}

int tpPause(TP_STRUCT * const tp)
{
    tp_pause->Pin=1;
    return 0;
}

int tpResume(TP_STRUCT * const tp)
{
    tp_pause->Pin=0;
    return 0;
}

int tpAbort(TP_STRUCT * const tp)
{
    tp_pause->Pin=1;
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

void block_add(struct sc_block **blocks, int *num_blocks, struct sc_block new_block) {
    (*num_blocks)++;
    *blocks = realloc(*blocks, (*num_blocks) * sizeof(struct sc_block));
    (*blocks)[(*num_blocks) - 1] = new_block;
}

// function to delete a block from an array
void block_delete(struct sc_block **pvec, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Error: invalid index\n");
        return;
    }

    // free the memory for the block being deleted
    free(pvec[index]);

    // shift all the blocks after the deleted block to the left by one position
    for (int i = index; i < *size-1; i++) {
        pvec[i] = pvec[i+1];
    }

    // decrement the size of the array
    (*size)--;
}

// function to add a block to the beginning of an array
void block_insert_front(struct sc_block **pvec, int *size, struct sc_block *block) {
    // allocate memory for a new block array
    struct sc_block *temp = malloc((*size + 1) * sizeof(struct sc_block));

    // assign the new block to the first position in the array
    temp[0] = *block;

    // copy the existing blocks to the remaining positions in the array
    for (int i = 0; i < *size; i++) {
        temp[i+1] = (*pvec)[i];
    }

    // free the memory allocated for the original block array
    free(*pvec);

    // assign the new block array to pvec and update the size
    *pvec = temp;
    (*size)++;
}

void insert_at_index(struct sc_block **pvec, int *size, int index, struct sc_block *block) {
    // allocate memory for a new block array
    struct sc_block *temp = malloc((*size + 1) * sizeof(struct sc_block));

    // copy the existing blocks up to the insertion point
    for (int i = 0; i < index; i++) {
        temp[i] = (*pvec)[i];
    }

    // insert the new block
    temp[index] = *block;

    // copy the remaining blocks
    for (int i = index+1; i < *size+1; i++) {
        temp[i] = (*pvec)[i-1];
    }

    // free the memory allocated for the original block array
    free(*pvec);

    // assign the new block array to pvec and update the size
    *pvec = temp;
    (*size)++;
}

// function to delete the last element from an array
void block_pop_back(struct sc_block **pvec, int *size) {
    if (*size > 0) {
        // decrement the size of the array
        (*size)--;
        // deallocate the memory for the last element
        free(pvec[*size]);
    }
}

// function to delete the first element from an array
void block_pop_front(struct sc_block **pvec, int *size) {
    if (*size > 0) {
        // decrement the size of the array
        (*size)--;
        // shift all the elements to the left by one position
        for (int i = 0; i < *size; i++) {
            pvec[i] = pvec[i+1];
        }
        // deallocate the memory for the first element
        free(pvec[0]);
    }
}

void block_print(struct sc_block *pvec, int size) {
    printf("Printing %d blocks:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Block %d:\n", i+1);
        printf("  G-code primitive ID: %d\n", pvec[i].primitive_id);
        printf("  G-code line number: %d\n", pvec[i].gcode_line_nr);
        printf("  Canonical motion type: %d\n", pvec[i].type);
        printf("  Start position: (%f, %f, %f, %f, %f, %f, %f, %f, %f)\n",
               pvec[i].pnt_s.x, pvec[i].pnt_s.y, pvec[i].pnt_s.z,
               pvec[i].dir_s.a, pvec[i].dir_s.b, pvec[i].dir_s.c,
               pvec[i].ext_s.u, pvec[i].ext_s.v, pvec[i].ext_s.w);
        printf("  Way position: (%f, %f, %f)\n",
               pvec[i].pnt_w.x, pvec[i].pnt_w.y, pvec[i].pnt_w.z);
        printf("  End position: (%f, %f, %f, %f, %f, %f, %f, %f, %f)\n",
               pvec[i].pnt_e.x, pvec[i].pnt_e.y, pvec[i].pnt_e.z,
               pvec[i].dir_e.a, pvec[i].dir_e.b, pvec[i].dir_e.c,
               pvec[i].ext_e.u, pvec[i].ext_e.v, pvec[i].ext_e.w);
        printf("  Center point: (%f, %f, %f)\n", pvec[i].pnt_c.x, pvec[i].pnt_c.y, pvec[i].pnt_c.z);
        //! Velcocity, acc.
        printf("  vo: %f\n", pvec[i].vo);
        printf("  ve: %f\n", pvec[i].ve);

        printf("\n");
    }
    //! Reset.
    tp_gcode_print->Pin=0;
}

struct sc_pnt emc_pose_to_sc_pnt(EmcPose pose){
    struct sc_pnt pnt;
    pnt.x=pose.tran.x;
    pnt.y=pose.tran.y;
    pnt.z=pose.tran.z;
    return pnt;
}

struct sc_dir emc_pose_to_sc_dir(EmcPose pose){
    struct sc_dir dir;
    dir.a=pose.a;
    dir.b=pose.b;
    dir.c=pose.c;
    return dir;
}

struct sc_ext emc_pose_to_sc_ext(EmcPose pose){
    struct sc_ext ext;
    ext.u=pose.u;
    ext.v=pose.v;
    ext.w=pose.w;
    return ext;
}

struct sc_pnt emc_cart_to_sc_pnt(PmCartesian pnt){
    struct sc_pnt p;
    p.x=pnt.x;
    p.y=pnt.y;
    p.z=pnt.z;
    return p;
}

PmCartesian sc_pnt_to_emc_cart(struct sc_pnt pnt){
    PmCartesian p;
    p.x=pnt.x;
    p.y=pnt.y;
    p.z=pnt.z;
    return p;
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







































