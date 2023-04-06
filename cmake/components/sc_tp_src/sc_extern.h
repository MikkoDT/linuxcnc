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
