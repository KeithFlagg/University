run: Graph.o Lab11.o
		g++ -o run Graph.o Lab11.o

Lab11.o: Lab11.cpp
		g++ -c -Wall -std=c++11 Lab11.cpp -g

Graph.o: Graph.h Graph.cpp
		g++ -c -Wall -std=c++11 Graph.cpp -g

clean:
		rm -f run Lab11.o Graph.o

rebuild:
		make clean
		make
