#include "systemc.h"
#include "mem.h"
#include "proco.h"

SC_MODULE(monitor) {
	sc_in <bool> writable;
	sc_in <bool> readable;
//	sc_in_rv<16> data;
	
	void enum_activity();
	
	SC_CTOR(monitor) {
		SC_MONITOR(enum_activity);
		sensitive << writable << readable;
	}
};
