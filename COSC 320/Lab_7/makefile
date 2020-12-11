run: Lab7.o
	g++ -o run Lab7.o

Lab7.o:	Lab7.cpp
	g++ -c -Wall -std=c++11 Lab7.cpp -g

clean:
	rm -f run Lab7.o

rebuild:
	make clean
	make
