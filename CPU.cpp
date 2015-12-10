#include "systemc.h"
#include "Memory.cpp"

SC_MODULE(CPU) {

public:
	sc_in<bool> Port_CLK;
	sc_in<Memory::RETSignal> Port_MemDone;
	sc_out<Memory::Function> Port_MemFunc;
	sc_out<int> Port_MemAddr;
	sc_inout<int> Port_MemData;

	SC_CTOR(CPU) {
		SC_METHOD(execCycle);
		sensitive_pos(Port_CLK);
		dont_initialize();

		SC_METHOD(memDone);
		sensitive(Port_MemDone);
		dont_initialize();
		
		m_waitMem = false;
	}

private:
	bool m_waitMem;
	Memory::Function getrndfunc() {
		int rndnum=(rand() % 10);
		if (rndnum < 5)
			return Memory::FUNC_READ;
		else
			return Memory::FUNC_WRITE;
	}

	int getRndAddress() {
		return (rand() % MEM_SIZE);
	}
	
	int getRndData() {
		return rand();
	}
	
	void execCycle() {
		if(m_waitMem) {
			return;
		}

		int addr = getRndAddress();
		Memory::Function f = getrndfunc();
		Port_MemFunc.write(f);
		Port_MemAddr.write(addr);

		if (f == Memory::FUNC_WRITE)
			Port_MemData.write(getRndData());
	
		m_waitMem = true;
	}

	void memDone() {
		if (Port_MemDone.read() == Memory::RSIG_NONE) {
			return;
		}
		m_waitMem = false;
		Port_MemFunc.write(Memory::FUNC_NONE);
	}
};

int sc_main(int argc, char* argv[]) {

	cout << "\n\nCreating Modules............";
/* Instantiate Modules */
	Memory mem("main_memory");
	CPU cpu("cpu");

/* Signals */
	sc_signal<Memory::Function> sigMemFunc;
	sc_signal<Memory::RETSignal> sigMemDone;
	sc_signal<int> sigMemAddr;
	sc_signal<int> sigMemData;

/* The clock that will drive the CPU and Memory*/
	sc_clock clk;
	cout << "DONE\nConnecting Modules' Ports...";

/* Connecting module ports with signals */
	mem.Port_Func(sigMemFunc);
	mem.Port_Addr(sigMemAddr);
	mem.Port_Data(sigMemData);
	mem.Port_DoneSig(sigMemDone);
	cpu.Port_MemFunc(sigMemFunc);
	cpu.Port_MemAddr(sigMemAddr);
	cpu.Port_MemData(sigMemData);
	cpu.Port_MemDone(sigMemDone);
	mem.Port_CLK(clk);
	cpu.Port_CLK(clk);
	cout << "DONE\n" << endl
		<< "\n\nRunning (press CTRL+C to exit)... ";

/* Start Simulation */
	sc_start();
	return 0;
}
