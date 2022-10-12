CXX = g++
CXXFLAGS = -g -Wall --std=c++11
VALGRIND = valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack_test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec-test: llrec-test.o llrec.o 
	$(CXX) $(CXXFLAGS) $^ -o $@

stack_test: stack_test.o 
	$(CXX) $(CXXFLAGS) $< -o $@

llrec-test.o: llrec-test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

stack_test.o: stack_test.cpp stack.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o rh llrec-test stack_test *~

.PHONY: clean 