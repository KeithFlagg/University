run: Graph.o Lab10.o
		g++ -o run Graph.o Lab10.o

Lab10.o: Lab10.cpp
		g++ -c -Wall -std=c++11 Lab10.cpp -g

Graph.o: Graph.h Graph.cpp
		g++ -c -Wall -std=c++11 Graph.cpp -g

clean:
		rm -f run Lab10.o Graph.o

rebuild:
		make clean
		make
