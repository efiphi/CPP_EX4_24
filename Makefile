CXX = g++
CXXFLAGS = -std=c++11 -I.
LDFLAGS = `pkg-config --cflags --libs Qt5Widgets`

OBJS = main.o Complex.o demo.o

all: tree test demo

tree: main.o Complex.o
	$(CXX) -o tree main.o Complex.o $(LDFLAGS)

test: test.o Complex.o
	$(CXX) -o test test.o Complex.o $(LDFLAGS)

demo: demo.o Complex.o
	$(CXX) -o demo demo.o Complex.o $(LDFLAGS)

main.o: main.cpp Tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Complex.o: Complex.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Complex.cpp

test.o: test.cpp Tree.hpp Complex.hpp doctest.h
	$(CXX) $(CXXFLAGS) -c test.cpp

demo.o: demo.cpp Tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c demo.cpp
	
clean:
	rm -f *.o tree test demo
