#ifndef SC_RUCKIG_H
#define SC_RUCKIG_H

#define to_override ((r.feed_overide/100)+1)
#define time_interval 0.01

#ifdef __cplusplus

//! LibRuckig scurve lib
//! https://github.com/pantor/ruckig, extra info: https://github.com/pantor/ruckig/issues/64
//! Examples
//! https://docs.ruckig.com/pages.html
#include "ruckig.hpp"

typedef double T;
typedef bool B;
typedef void V;

class sc_ruckig
{
public:
    sc_ruckig();

    V set_a_jm(T maxacc, T jerkmax);

    V set_vm(T maxvel);

    V set_target(T tarpos, T tarvel, T taracc);

    V set_current(T curpos, T curvel, T curacc);

    V calculate();

    B update(T *newpos, T *newvel, T *newacc);

private:
    ruckig::InputParameter<1> in;
    ruckig::OutputParameter<1> out;
    // std::array<double, 1> vel, acc, pos;

    ruckig::Ruckig<1> otg {0.001};
    ruckig::Result result;

    T duration=0;
    T at_time=0;
};

//! Here it tells if this code is used in c, convert the class to a struct. This is handy!
#else
typedef struct sc_ruckig sc_ruckig;
#endif //! cplusplus

#endif // SC_RUCKIG_H














