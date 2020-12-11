run: Lab4.o Matrix.o
		g++ -o run Lab4.o Matrix.o -g

Lab4.o:	Lab4.cpp
		g++ -c -Wall -std=c++11 Lab4.cpp -g

Matrix.o: Matrix.cpp Matrix.h
		g++ -c -Wall -std=c++11 Matrix.cpp -g

clean:
		rm -f run Lab4.o Matrix.o

rebuild:
	make clean
	make
