CXXFLAGS=-Wall -Wextra -O0 -g -std=c++11

main: main.o forest.o tree.o node.o
	g++ main.o forest.o tree.o node.o -o main

main.o: main.cpp forest.h tree.h node.h
	g++ -o main.o -c main.cpp

forest.o: forest.cpp forest.h 
	g++ -o forest.o -c forest.cpp
	
tree.o: tree.cpp tree.h node.h forest.h
	g++ -o tree.o -c tree.cpp
	
node.o: node.cpp node.h forest.h tree.h
	g++ -o node.o -c node.cpp

clean: 
	rm main main.o forest.o tree.o node.o
