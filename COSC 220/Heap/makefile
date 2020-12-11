run: heap.o Lab8.o
		g++ -o run heap.o Lab8.o

Lab8.o:	Lab8.cpp
		g++ -c -Wall -std=c++11 Lab8.cpp

heap.o:	heap.cpp heap.h
		g++ -c -Wall -std=c++11 heap.cpp

clean:
	rm -f run Lab8.o heap.o

rebuild:
	make clean
	make
