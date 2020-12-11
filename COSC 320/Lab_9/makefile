run: BST.o	RBT.o	Lab9.o
		g++ -o run BST.o RBT.o Lab9.o

Lab9.o:	Lab9.cpp
		g++ -c -Wall -std=c++11 Lab9.cpp -g

RBT.o: RBT.h RBT.cpp
		g++ -c -Wall -std=c++11 RBT.cpp -g

BST.o:	BST.cpp BST.h
		g++ -c -Wall -std=c++11 BST.cpp -g

clean:
	rm -f run Lab9.o BST.o RBT.o

rebuild:
	make clean
	make
