#include "sc_pid.h"

sc_pid::sc_pid()
{
}

void sc_pid::sc_set_a_dv_interval(T a, T dv, T ival){
    engine->sc_set_a_dv(a,dv);
    interval=ival;
}

V sc_pid::sc_set_tarpos(T value){
    tarpos=value;
}

V sc_pid::sc_set_tarvel(T value){
    endvel=value;
}

V sc_pid::sc_set_curpos(T value){
    curpos=value;
}

V sc_pid::sc_set_curacc(T value){
    curacc=value;
}

V sc_pid::sc_set_curvel(T value){
    curvel=value;
}

V sc_pid::sc_set_maxvel(T value){
    maxvel=value;
}

V sc_pid::sc_result(T &pos,
                    T &vel,
                    T &acc){
    pos=curpos;
    vel=curvel;
    acc=curacc;
}

inline void sc_pid::sc_update_value(T pos_add, T vel, T acc, B reverse){
    if(reverse){
        curpos-=pos_add;
    } else {
        curpos+=pos_add;
    }

    curvel=vel;
    curacc=acc;
}

//! Connect to thread.
B sc_pid::sc_update(bool reverse){

    // std::cout<<"vm:"<<maxvel<<std::endl;

    //! Verbose flag to print situation.
    B verbose=0;

    T dtg=engine->netto_difference_of_2_values(curpos,tarpos);
    // std::cout<<"dtg:"<<dtg<<std::endl;

    //B reverse=0;
    if(tarpos<curpos){
        //reverse=true;
        //std::cerr<<"position overshoot"<<std::endl;

    }

    //! End of traject.
    if(curvel==endvel && curacc==0 && dtg==0.0){
        //! Do nothing.
        if(verbose){ std::cout<<"end of traject."<<std::endl; }
        return 1;
    }

    //! Start of traject.
    if(curvel==startvel && curacc==0 && dtg>0){
        //! Append a t1 operation.
        sc_period p;
        engine->t1_pid(curvel,curacc,interval,p);
        sc_update_value(p.ncs,p.ve,p.ace,reverse);

        if(verbose){ std::cout<<"start t1 given."<<std::endl; }
        return 0;
    }


    //! At t2.
    if(curacc==engine->as){
        //! Try to add a t2.
        sc_period p;
        T s=0;
        engine->t2_pid(curvel,curacc,interval,p);
        s+=p.ncs;
        //! If we finish curve from here, does it fit displacement?
        engine->t3(p.ve,p.ace,0,p);
        s+=p.ncs;

        T l=0;
        engine->t5_t6_t7(p.ve,endvel,l);
        s+=l;

        if(s<dtg && p.ve<maxvel){
            //! t2 ok.
            engine->t2_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);

            if(verbose){ std::cout<<"t2 pid ok."<<std::endl; }
        } else {
            //! Start the dcc period.
            engine->t3_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);
        }
        return 0;
    }

    //! At t1 or t3.
    if(curacc>0 && curacc<engine->as){

        //! Check if t1 may go up one pid cycle.
        sc_period p;
        T s=0;
        engine->t1_pid(curvel,curacc,interval,p);
        s+=p.ncs;
        engine->t3(p.ve,p.ace,0,p);
        s+=p.ncs;

        //! To finish curve from here ok for displacement?
        T l=0;

        engine->t5_t6_t7(p.ve,0,l);
        s+=l;

        if(s<dtg && p.ve<maxvel){
            //! t1 ok.
            engine->t1_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);

            if(verbose){ std::cout<<"t1 pid ok."<<std::endl; }
        } else {
            //! t3 ok.
            engine->t3_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);
            if(verbose){ std::cout<<"t3 pid ok."<<std::endl; }
        }
        return 0;
    }

    //! vm up interupt.
    if(curvel>0.01 && curacc==0 && dtg>0.01){

        //! Try to add a t4 period.
        sc_period p;
        T s=0;
        engine->t4_pid(curvel,curacc,interval,p);
        s+=p.ncs;
        //! Does it fits if we add dcc from here?
        T l=0;
        engine->t5_t6_t7(p.ve,endvel,l);

        s+=l;
        if(s<dtg){
            if(curvel<maxvel){ //! Vm interupt.
                engine->t1_pid(curvel,curacc,interval,p);
            }
            sc_update_value(p.ncs,p.ve,p.ace,reverse);
            return 0;
        }
    }

    //! at vm traject.
    if(curvel>0.01 && curacc==0 && dtg>0.01){

        //! Try to add a t4 period.
        sc_period p;
        T s=0;
        engine->t4_pid(curvel,curacc,interval,p);
        s+=p.ncs;
        //! Does it fits if we add dcc from here?
        T l=0;
        engine->t5_t6_t7(p.ve,endvel,l);

        s+=l;
        if(s<dtg){

            //! Add t4 ok.
            sc_update_value(p.ncs,p.ve,p.ace,reverse);

            if(verbose){ std::cout<<"at vm, t4."<<std::endl; }
        } else {
            //! Go dcc.
            engine->t5_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);

            if(verbose){ std::cout<<"t4 finished, starting the t5 pid dcc cycle."<<std::endl; }
        }
        return 0;
    }

    //! At t5 or t7.
    if(curacc<0 && curacc>-engine->as){

        sc_period p;
        T s=0;
        //! Is t5?
        engine->t5_pid(curvel,curacc,interval,p);
        s+=p.ncs;

        engine->t7(p.ve,p.ace,0,p);
        s+=p.ncs;

        if(p.ve>endvel){
            //! t5 ok.
            engine->t5_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);

            if(verbose){ std::cout<<"t5 pid ok."<<std::endl; }
        } else {
            //! t7 ok.
            engine->t7_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);

            if(verbose){ std::cout<<"t7 pid ok."<<std::endl; }
        }
        return 0;
    }

    //! At t6.
    if(curacc==-engine->as){
        //! Try to add a t6.
        sc_period p;
        T s=0;
        engine->t6_pid(curvel,curacc,interval,p);
        s+=p.ncs;

        engine->t7(p.ve,p.ace,0,p);
        s+=p.ncs;

        if(p.ve>endvel){
            //! t6 ok.
            engine->t6_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);

            if(verbose){ std::cout<<"t6 pid ok."<<std::endl; }
        } else {
            //! Start t7 period.
            engine->t7_pid(curvel,curacc,interval,p);
            sc_update_value(p.ncs,p.ve,p.ace,reverse);
        }
        return 0;
    }

    //! Problably exact endpos is not reached.
    if(verbose){ std::cerr<<"update error"<<std::endl; }

    if(verbose){ std::cerr<<"curpos:"<<curpos<<"curvel:"<<curvel<<" curacc:"<<curacc<<std::endl; }

    //! Do this only if we are very close to the target point. It could be caused by the interval resolution.
    tarpos=curpos;
    startvel=curvel;
    return 1;
}

extern "C" sc_pid* new_pid(){
    return new sc_pid();
}

extern "C" V pid_set_a_dv_interval_c(sc_pid *ptr, T a, T dv, T interval){
    ptr->sc_set_a_dv_interval(a,dv,interval);
}

extern "C" V pid_set_maxvel(sc_pid *ptr, T vm){
    ptr->sc_set_maxvel(vm);
}

extern "C" V pid_set_tarpos(sc_pid *ptr, T pos){
    ptr->sc_set_tarpos(pos);
}

extern "C" V pid_set_tarvel(sc_pid *ptr, T pos){
    ptr->sc_set_tarvel(pos);
}

extern "C" V pid_set_curpos(sc_pid *ptr, T pos){
    ptr->sc_set_curpos(pos);
}

extern "C" V pid_set_curvel(sc_pid *ptr, T pos){
    ptr->sc_set_curvel(pos);
}

extern "C" V pid_set_curacc(sc_pid *ptr, T pos){
    ptr->sc_set_curacc(pos);
}


extern "C" B pid_update_c(sc_pid *ptr, T *pos, T *vel, T *acc){
    bool reverse=0;
    B finished=ptr->sc_update(reverse);
    T p,v,a;
    ptr->sc_result(p,v,a);

    *pos=p;
    *vel=v;
    *acc=a;

    return finished;
}








