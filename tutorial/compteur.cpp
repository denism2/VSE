#include "systemc.h"

SC_MODULE(compteur){

    sc_in<bool> clock;
    sc_in<bool> reset;
    sc_in<sc_uint<8> > in;
    sc_out<sc_uint<8> > out;
    sc_in<bool> load;
    unsigned char value;

    void compte(){
        if(load == true){
            value = in.read();
        }

        if(reset == false){
            value = 0;
        } else {
            value++;
        }
        out = value;
    };

    SC_CTOR(compteur){
        SC_METHOD(compte);
        sensitive << clock.pos();
    };
};
