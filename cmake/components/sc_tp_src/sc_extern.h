#include "sc_lines.h"
#include "sc_arcs.h"

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

extern void optimize_gcode_c(struct sc_block *pvec, int size, T vm, T **path_lenghts, int *path_lenght_size, T *stot);


#include "ruckig/sc_ruckig.h"
extern sc_ruckig* ruckig_init_ptr();
extern V ruckig_set_a_jm(sc_ruckig *ptr, T maxacc, T jerkmax);
extern V ruckig_set_interval(sc_ruckig *ptr, T value);
extern V ruckig_set_vm(sc_ruckig *ptr, T velmax);
extern V ruckig_run(sc_ruckig *ptr, T tarpos, T tarvel, T taracc);
extern V ruckig_stop(sc_ruckig *ptr);
extern V ruckig_pause(sc_ruckig *ptr);
extern V ruckig_pause_resume(sc_ruckig *ptr);
extern V ruckig_set_mempos(sc_ruckig *ptr, T value);
extern B ruckig_update(sc_ruckig *ptr, T *mempos, T *newvel, T *newacc);
//! Status callback.
extern enum sc_ruckig_state ruckig_get_state(sc_ruckig *ptr);

extern B ruckig_state_run(sc_ruckig *ptr);
extern B ruckig_state_stop(sc_ruckig *ptr);
extern B ruckig_state_pause(sc_ruckig *ptr);
extern B ruckig_state_pause_resume(sc_ruckig *ptr);
extern B ruckig_state_finished(sc_ruckig *ptr);

extern T ruckig_get_a(sc_ruckig *ptr);
extern T ruckig_get_jm(sc_ruckig *ptr);
extern T ruckig_get_vm(sc_ruckig *ptr);
