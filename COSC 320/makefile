run: BST.o	Lab8.o
		g++ -o run BST.o Lab8.o

Lab8.o:	Lab8.cpp
		g++ -c -Wall -std=c++11 Lab8.cpp -g

BST.o:	BST.cpp BST.h
		g++ -c -Wall -std=c++11 BST.cpp -g

clean:
	rm -f run Lab8.o BST.o

rebuild:
	make clean
	make
