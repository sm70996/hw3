CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.o
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ llrec-test.o

llrec-test.o: llrec-test.cpp llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c llrec-test.cpp

clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 