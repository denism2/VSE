#include "proco.h"

void proco::send_data() {
	if (writing) {
		addr.read();
		data.read();
	}
}

void proco::read_data() {
	if (!writing) {
		data.write();
	}
}

int sc_main(int argc, char* argv[]) {


}
