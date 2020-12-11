run: card.o	proj.o
		g++ -o run card.o	proj.o

proj.o:	proj.cpp
		g++ -c -Wall -std=c++11 proj.cpp

card.o:	card.cpp card.h
		g++ -c -Wall -std=c++11 card.cpp

clean:
	rm -f run proj.o card.o

rebuild:
	make clean
	make
