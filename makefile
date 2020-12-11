run: BST.o	TNode.o Lab6.o
		g++ -o run BST.o	TNode.o Lab6.o

Lab6.o:	Lab6.cpp
		g++ -c -Wall -std=c++11 Lab6.cpp -g

BST.o:	BST.cpp BST.h
		g++ -c -Wall -std=c++11 BST.cpp -g

Node.o: TNode.cpp TNode.h
		g++ -c -Wall -std=c++11 TNode.cpp -g

clean:
	rm -f run Lab6.o BST.o TNode.o

rebuild:
	make clean
	make
