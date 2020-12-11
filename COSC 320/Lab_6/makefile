run: Lab6.o
	g++ -o run Lab6.o

Lab6.o: Lab6.cpp
	g++ -c -Wall -std=c++11 Lab6.cpp -g

clean:
	rm -f run Lab6.o

rebuild:
	make clean
	make
