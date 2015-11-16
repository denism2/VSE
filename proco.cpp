#include "proco.h"

void proco::send_data() {
	if (writing && !reading) {
		addr.read();
		data.read();
	}
}

void proco::receive_data() {
	if (!writing && reading) {
	// à revoir la noton d'écriture dans un port
	// problème de type pour write()
		data.write();
	}
}

