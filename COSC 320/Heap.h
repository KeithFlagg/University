#ifndef HEAP_H
#define HEAP_H
#include <iostream>
//Macros for header


template <class T>
struct HeapObj {
T data;
int key;
};


template <class T>
class Heap{

private:



  HeapObj<T>* arr;
  int heapSize;
  int length;

  void increaseKey(T, int i, int k);

  int left(int i){
    return 2*i+1;
  }

  int right(int i){
    return 2*i +2;
  }

  int parent(int i){
    if (i != 1){
      return i/2;
    }
    else{
      std :: cout<<"No Parent node!"<<std::endl;
      return -1;
    }
  }

public:
Heap();
Heap(T*, int*, int);
~Heap();

void insert(T, int);
void peek();
T extractMax(Heap<T>&);
void print();
void buildHeap(Heap<T>&);
void maxHeapify(Heap<T>&, int);
void heapSort(Heap <T>&);
};
#endif
