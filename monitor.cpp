#include "monitor.h"

void monitor::enum_activity() {
	int reading = 0;
	int writing = 0;
	
	(writable) ? (writable++);
	(readable) ? (readable++);
}
	
void monitor::display_activity() {
	//......	
	cout <<"System actvity of this demo"<< endl;
	cout <<"	Read access: "<< reading<< endl;
	cout <<"	Write access: "<< writing<< endl;
}
