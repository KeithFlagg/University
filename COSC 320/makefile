run: Lab5.o Heap.o
		g++ -o run Lab5.o Heap.o -g

Lab5.o:	Lab5.cpp
		g++ -c -Wall -std=c++11 Lab5.cpp -g

Heap.o: Heap.cpp 
		g++ -c -Wall -std=c++11 Heap.cpp -g

clean:
		rm -f run Lab5.o Heap.o

rebuild:
	make clean
	make
