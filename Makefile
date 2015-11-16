SYSTEMC =./systemc-2.3
LDFLAGS = -L$(SYSTEMC)/lib-linux64 -lsystemc
CXXFLAGS =-Wno-deprecated -I$(SYSTEMC)/include -fpermissive
EXE = mem.cpp simu.cpp
all:
	g++ $(CXXFLAGS) $(EXE) $(LDFLAGS)
	./a.out
clean:
	rm a.out
