run: Graph.o Lab12.o
		g++ -o run Graph.o Lab12.o

Lab12.o: Lab12.cpp
		g++ -c -Wall -std=c++11 Lab12.cpp -g

Graph.o: Graph.h Graph.cpp
		g++ -c -Wall -std=c++11 Graph.cpp -g

clean:
		rm -f run Lab12.o Graph.o

rebuild:
		make clean
		make
