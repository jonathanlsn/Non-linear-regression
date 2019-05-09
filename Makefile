CXXFLAGS=-Wall -Wextra -O0 -g -std=c++11

main: main.o node.o tree.o forest.o matrix.o 
	g++ main.o node.o tree.o forest.o matrix.o  -o main

main.o: main.cpp forest.h tree.h node.h
	g++ -o main.o -c main.cpp

node.o: node.cpp node.h 
	g++ -o node.o -c node.cpp

tree.o: tree.cpp tree.h node.h 
	g++ -o tree.o -c tree.cpp
	
forest.o: forest.cpp forest.h tree.h node.h 
	g++ -o forest.o -c forest.cpp

matrix.o: matrix.cpp matrix.h 
	g++ -o matrix.o -c matrix.cpp

clean: 
	rm main main.o forest.o tree.o node.o
