task = disjoint
all: $(task)

$(task): $(task).o
	g++ -o $(task) $(task).o

$(task).o: $(task).cpp
	g++ -std=c++11 -c $(task).cpp

clean:
	rm -rf *.o $(task)
