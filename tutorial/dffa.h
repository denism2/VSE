#include "systemc.h"

SC_MODULE(dffa){
    sc_in<bool> clock;
    sc_in<bool> reset;
    sc_in<bool> din;
    sc_out<bool> dout;

    void do_bascule(){
        if(reset==false){
            dout = false;
        }
        else{
            if(clock.event()){
                dout = din;
            }
        }
    };

    SC_CTOR(dff){
        SC_METHOD(do_bascule);
        sensitive << reset;
        sensitive << clock.pos();
    }
};
