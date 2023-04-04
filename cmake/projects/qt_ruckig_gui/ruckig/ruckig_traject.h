#ifndef RUCKIG_TRAJECT_H
#define RUCKIG_TRAJECT_H

#define to_override ((r.feed_overide/100)+1)
#define time_interval 0.01

#ifdef __cplusplus

//! LibRuckig scurve lib
//! https://github.com/pantor/ruckig, extra info: https://github.com/pantor/ruckig/issues/64
//! Examples
//! https://docs.ruckig.com/pages.html
#include "ruckig.hpp"

class ruckig_traject
{
public:
    ruckig_traject();

    //! Calculates new pos,vel,acc for every servo cycle.
    void ruckig_calc(double maxacc, double maxjerk, double maxvel, double curpos, double curvel, double curacc,
                     double tarpos, double tarvel, double taracc,
                     double *newpos, double *newvel, double *newacc);

    //! Calculates end velocity given displacement "s".
    void ruckig_endvel(double vo, double vm, double ve, double s, double a, double jm,
                       double &si, double &vi, double &ai);

};

//! Here it tells if this code is used in c, convert the class to a struct. This is handy!
#else
typedef struct ruckig_traject ruckig_traject;
#endif //! cplusplus

#endif // RUCKIG_TRAJECT_H














