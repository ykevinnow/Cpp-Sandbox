PROGRAM   = lazy_val
CXX       = g++
CXXFLAGS  = -g -std=c++17 -Wall

$(PROGRAM): lazy_val.o
	$(CXX) -o $(PROGRAM) lazy_val.o

.PHONY: clean dist

clean:
	-rm -f *.o $(PROGRAM) *core

dist: clean
	-tar -chvj -C .. -f ../$(PROGRAM).tar.bz2 $(PROGRAM)


