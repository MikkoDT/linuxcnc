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

enum sc_ruckig_state {
    sc_ruckig_none,
    sc_ruckig_finished,
    sc_ruckig_run,
    sc_ruckig_stop,
    sc_ruckig_pause,
    sc_ruckig_pause_resume,
    sc_ruckig_wait
};

class sc_ruckig
{
public:
    sc_ruckig();


    V set_a_jm(T maxacc, T jerkmax);

    T get_a();

    T get_jm();

    V set_vm(T maxvel);

    T get_vm();

    V run(T tarpos, T tarvel, T taracc);

    V stop();

    V pause();

    V pause_resume();

    //! For each cycle, incpos is the increment value to be added to your current position.
    //! Add this function to a update thread.
    B update(T &incpos, T &mempos, T &newpos, T &newvel, T &newacc);

    sc_ruckig_state get_state();

    V set_mem_pos(T value);

private:
    ruckig::InputParameter<1> myIn;
    ruckig::OutputParameter<1> myOut;

    std::array<double, 1> myVel, myAcc, myPos;
    ruckig::Ruckig<1> myOtg {0.001};
    ruckig::Result myResult;

    T myDuration=0;
    T myAtTime=0;

    T myOldpos=0;
    T myMempos=0;

    sc_ruckig_state myState=sc_ruckig_none;

    V run();
    V set_target(T tarpos, T tarvel, T taracc);
    V set_current(T curpos, T curvel, T curacc);
};

//! Here it tells if this code is used in c, convert the class to a struct. This is handy!
#else
typedef struct sc_ruckig sc_ruckig;
#endif //! cplusplus

#endif // SC_RUCKIG_H














