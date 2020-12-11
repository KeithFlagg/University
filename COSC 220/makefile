run: linkedList.o	Node.o Lab3.o
		g++ -o run linkedList.o	Node.o Lab3.o

Lab3.o:	Lab3.cpp
		g++ -c -Wall -std=c++11 Lab3.cpp

linkedList.o:	linkedList.cpp Linkedlist.h
		g++ -c -Wall -std=c++11 linkedList.cpp

Node.o: Node.cpp Node.h
		g++ -c -Wall -std=c++11 Node.cpp

clean:
	rm -f run Lab3.o linkedList.o Node.o

rebuild:
	make
	make clean
