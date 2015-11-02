#include "systemc.h"

SC_MODULE (proco) {
	sc_out<sc_uint<8> > addr;
	sc_out <bool> writing;
	
	sc_out_rv <16> data;
	
	void send_data();
	void read_data();

	SC_CTOR(proco) {
		SC_METHOD(send_data);
		sensitive << addr << writing << data;
		SC_METHOD(read_data);
		sensitive << writing << data;
	}
};
