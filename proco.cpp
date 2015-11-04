#include "proco.h"

void proco::send_data() {
	if (writing && !reading) {
		addr.read();
		data.read();
	}
}

void proco::read_data() {
	if (!writing && reading) {
		data.write();
	}
}

