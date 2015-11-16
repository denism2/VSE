#include "mem.h"

int sc_main(int argc, char* argv[]) {

int mess = 101010;

mem m1("memory");

m1.addr = 00000001;
m1.wdis = false;
m1.data = mess;
m1.wena = true;

m1.read_data();

m1.data = 0000000000000000;
m1.wdis = true;
m1.wena = false;

m1.write_data();
cout << m1.data << endl;

return(0);
}
