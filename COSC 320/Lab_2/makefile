run: Lab2.o
	g++ -o run Lab2.o

Lab1.o:	Lab2.cpp
	g++ -c -Wall -std=c++11 Lab2.cpp -g

clean:
	rm -f run Lab2.o

rebuild:
	make clean
	make
