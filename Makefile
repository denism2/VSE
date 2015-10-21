SYSTEMC =/home/denism2/git/systemc-2.3
LDFLAGS = -L$(SYSTEMC)/lib-linux64 -lsystemc
CXXFLAGS =-Wno-deprecated -I$(SYSTEMC)/include -fpermissive
#EXE = testing.cpp
all:
	g++ $(CXXFLAGS) *.cpp $(LDFLAGS)
	./a.out
clean:
	rm a.out
