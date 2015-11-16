#include "monitor.h"

void monitor::enum_activity() {
	int reading = 0;
	int writing = 0;
	
	if (writable) writing++;
	if (readable /*&& data == "zzzzzzzzzzzzzzzz"*/) {
		reading++;
	}

	//......	
	cout <<"System actvity of this demo"<< endl;
	cout <<"	Read access: "<< reading<< endl;
	cout <<"	Write access: "<< writing<< endl;
}
