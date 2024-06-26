CXX = g++
CXXFLAGS = -std=c++11 -I.
LDFLAGS = `pkg-config --cflags --libs Qt5Widgets`

OBJS = main.o Complex.o Demo.o

all: tree test demo

tree: main.o Complex.o
	$(CXX) -o tree main.o Complex.o 

test: test.o Complex.o
	$(CXX) -o test test.o Complex.o 

demo: Demo.o Complex.o
	$(CXX) -o demo Demo.o Complex.o 

main.o: main.cpp Tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Complex.o: Complex.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Complex.cpp

test.o: test.cpp Tree.hpp Complex.hpp doctest.h
	$(CXX) $(CXXFLAGS) -c test.cpp

Demo.o: Demo.cpp Tree.hpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Demo.cpp
	
clean:
	rm -f *.o tree test demo
