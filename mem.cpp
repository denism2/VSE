#include "mem.h"

void mem::read_data() {
	if (!wdis && wena) {
		data = ram_data[addr.read()];
	} else {
		data = "zzzzzzzzzzzzzzzz";
	}
}
void mem::write_data() {
	if (wdis && !wena) {
		ram_data[addr.read()] = data;
	}
}
