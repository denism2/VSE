#include "systemc.h"

SC_MODULE (mem) {
	sc_in<sc_uint<8> > addr;
	sc_in <bool> wdis;
	sc_in <bool> wena;
	sc_inout_rv <16> data;
	sc_lv<16> ram_data[256];
	SC_CTOR(mem) {
		SC_METHOD(read_data);
		sensitive << addr << wdis << wena;
		SC_METHOD(write_data);
		sensitive << addr << wdis << wena << data;
	}
	void read_data() {
		if (!wdis && wena) {
			data = mem_data[addr.read()];
		} else {
			data = "zzzzzzzzzzzzzzzz";
		}
	}
	void write_data() {
		if (wdis && !wena) {
			ram_data[addr.read()] = data;
		}
	}
};
