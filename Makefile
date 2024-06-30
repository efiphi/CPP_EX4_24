CXX = g++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SFML_INCLUDE = -I/usr/include/SFML

OBJS = main.o Complex.o NodeItem.o Demo.o

all: tree test demo

tree: main.o Complex.o NodeItem.o
	$(CXX) -o tree main.o Complex.o NodeItem.o $(LDFLAGS)

test: test.o Complex.o NodeItem.o
	$(CXX) -o test test.o Complex.o NodeItem.o $(LDFLAGS)

demo: Demo.o Complex.o NodeItem.o
	$(CXX) -o demo Demo.o Complex.o NodeItem.o $(LDFLAGS)

main.o: main.cpp Tree.hpp Complex.hpp NodeItem.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c main.cpp

Complex.o: Complex.cpp Complex.hpp
	$(CXX) $(CXXFLAGS) -c Complex.cpp

NodeItem.o: NodeItem.cpp NodeItem.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c NodeItem.cpp

test.o: test.cpp Tree.hpp Complex.hpp NodeItem.hpp doctest.h
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c test.cpp

Demo.o: Demo.cpp Tree.hpp Complex.hpp NodeItem.hpp
	$(CXX) $(CXXFLAGS) $(SFML_INCLUDE) -c Demo.cpp
	
clean:
	rm -f *.o tree test demo
