/*
* Memory.cpp
*  Authors: denism2, arctarus44
*  Date:  Jan 14, 2016
*/

#include "systemc.h"
#define MEM_SIZE 512

/*
* Memory with control of read/write state 
* and read/write count
*/
SC_MODULE(Memory) {

//Instanciate state memory
public:
	enum Function {
		FUNC_NONE,
		FUNC_READ,
		FUNC_WRITE
	};

	enum RETSignal {
		RSIG_NONE,
		RSIG_READ_FIN,
		RSIG_WRITE_FIN,
		RSIG_ERROR
	};

//
	sc_in<bool> Port_CLK;
	sc_in<Function> Port_Func;

	sc_in<int> Port_Addr;
	sc_inout<int> Port_Data;
	sc_out<RETSignal> Port_DoneSig;

	SC_CTOR(Memory) {
		SC_METHOD(execute);
		sensitive_neg(Port_CLK);

		m_clkCnt = 0;
		m_curAddr = 0;
		m_curData = 0;
		m_curFunc = Memory::FUNC_NONE;

		m_data = new int[MEM_SIZE];

		m_writesCnt = 0;
		m_readsCnt = 0;
		m_errorsCnt = 0;
		m_errorCode = 0;
}

	~Memory() {
		delete [] m_data;
	}

private:
	int m_clkCnt;
	int m_curAddr;
	int m_curData;
	Function m_curFunc;

	int* m_data;
	int m_errorCode;
	int m_writesCnt;
	int m_readsCnt;
	int m_errorsCnt;

// get data at current address
RETSignal read() {
	if (m_errorCode == 0) {
		Port_Data.write(m_data[m_curAddr]);
		m_readsCnt++;
		return RSIG_READ_FIN;
	} else {
		m_errorsCnt++;
		return RSIG_ERROR;
	}
}

// set information at current address
RETSignal write() {
	if (m_errorCode == 0) {
		m_data[m_curAddr] = m_curData;
		m_writesCnt++;
		return RSIG_WRITE_FIN;
	} else {
		m_errorsCnt++;
		return RSIG_ERROR;
	}
}

void execute() {
// Controls of memory functions
	if (m_curFunc != Memory::FUNC_NONE) {
		m_clkCnt++;
		if (m_clkCnt == 100) {
			RETSignal retSig = Memory::RSIG_ERROR;
			switch (m_curFunc) {
				case Memory::FUNC_READ : { retSig = read(); break; }
				case Memory::FUNC_WRITE : { retSig = write(); break; }
			}
		Port_DoneSig.write(retSig);
		m_clkCnt = 0;
		m_curFunc = Memory::FUNC_NONE;
		}
	return;
	}
	if (Port_Func.read() == Memory::FUNC_NONE) {
		return;
	}

	m_curFunc = Port_Func.read();
	m_curAddr = Port_Addr.read();
	m_curData = Port_Data.read();

	Port_DoneSig.write(Memory::RSIG_NONE);
	}
};

// DEBUG ONLY
// int sc_main(int argc, char* argv[]) {

// 	Memory mem("main_memory");
// 	sc_start();
// 	return 0;
// }
