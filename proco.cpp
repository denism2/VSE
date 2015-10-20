#include "systemc.h"

SC_MODULE (proco) {
	sc_out<sc_int<8>> addr;
	sc_out <bool> write;
	sc_out_rv <16> data;
}
	SC_CTOR(mem) {
		SC_METHOD(send_data);
		sensitive << addr << write << data;
	}
	
	void send_data {
		if (write) {
		
		}
	}
	}
int sc_main(int argc, char* argv[]) {


};
