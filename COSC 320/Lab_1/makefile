run: Lab1.o
	g++ -o run Lab1.o

Lab1.o:	Lab1.cpp
	g++ -c -Wall -std=c++11 Lab1.cpp -g

clean:
	rm -f run Lab1.o

rebuild:
	make clean
	make
