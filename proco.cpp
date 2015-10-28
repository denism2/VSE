#include "systemc.h"

SC_MODULE (proco) {
	sc_out<sc_uint<8> > addr;
	sc_out <bool> write;
	sc_out_rv <16> data;

	SC_CTOR(proco) {
		SC_METHOD(send_data);
		sensitive << addr << write << data;
	}
	
	void send_data() {
		if (write) {
			addr.read();
			data.read();
		}
	}
};

int sc_main(int argc, char* argv[]) {


}
