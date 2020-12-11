#ifndef HEAP_H
#define HEAP_H

class Heap{
private:
int arr[100];
int size;

int parent(int);
int left(int);
int right(int);
void heapify(int);
void buildHeap();

public:
Heap();
~Heap();

void swap(int &x, int &y);
void insert(int);
void sort();
int extractMax();
void printHeap();
int max();
};
#endif
