#include "Heap.h"
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

const std::string cyan("\033[0;36m");
const std::string reset("\033[0m");
const std::string magenta("\033[0;35m");
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");

template <class T>
Heap<T>::Heap(T* a, int* priority, int l){

  arr = new HeapObj<T>[l];

  heapSize = l;
  length = l;

  for (int i = 0; i < l; i++){
    arr[i].data = a[i];
    arr[i].key = priority[i];
  }
}



template <class T>
Heap<T>::Heap(){
  arr = new HeapObj<T>[5];
  heapSize = 5;
  length = 0;
}

template <class T>
Heap<T>::~Heap(){
  delete[] arr;
}


template <class T>
void Heap<T>::increaseKey(T A, int i, int k){
  if (k<A[i]){
    cout<<red<<"The new key is not greater than previous key!"<<reset<<endl;
    return;
  }

  else{
    A[i] = k;
  }

  while((i>1)&&(A[parent(i)]<A[i])){
    HeapObj<T> temp;
    temp.key = A[i-1];

    A[i-1] = A[parent(i)-1];
    A[parent(i)-1] = temp.key;
    i = parent(i);
  }
}


template <class T>
void Heap<T>::insert(T A, int k){
  heapSize++;
  length++;
  heapSize = -999;
  increaseKey(A, heapSize, k);
}


template <class T>
void Heap<T>::peek(){
  cout<<endl<<green<<arr[0].data<<" is at the top of the queue!"<< reset << endl;
}


template <class T>
T Heap<T>::extractMax(Heap&A){
  if (heapSize < 1){
    cout<< red << "The heap is empty!" << reset << endl;
    return arr[0].data;
  }
  else {
    HeapObj<T> max;
    max.data = arr[0].data;
    max.key = arr[0].key;
    arr[0] = arr[heapSize-1];
    heapSize--;
    maxHeapify(A,0);
    cout<< green << "Max extracted: " << max.data << reset << endl;
    return max.data;
  }

}


template <class T>
void Heap<T>::print(){
  for (int i =0; i <= length; i++ ){
    if (arr[i].key >= 0){
      cout << cyan << arr[i-1].data << reset;
    }
    for(int j = 1; j <= length; j++){
      if (i == (pow(2,j))){
        cout << endl;
      }
    }
  }
}


template <class T>
void Heap<T>::maxHeapify(Heap &A, int i){
  int l = left(i);
  int r = right(i);
  int largest;

  if ((l <= A.heapSize)&&(A.arr[l].key>A.arr[i].key)){
  		largest = l;
  	}
  	else{
  		largest = i;
  	}

  	if ((r <= A.heapSize) && (A.arr[r].key > A.arr[largest].key)){
  		largest = r;
  	}

  	if (largest != i)
  	{
      HeapObj<T> temp;
       temp.data = A.arr[0].data;
      A.arr[0].data = A.arr[i].data;
      A.arr[i].data = temp.data;

  		// Recursively heapify
  		maxHeapify(A, largest);
    }
}


template <class T>
void Heap<T>::buildHeap(Heap &A){
  A.heapSize = A.length;
  for (int i = (A.length/2); i >= 1; i--){
    maxHeapify(A,i);
  }
}

template <class T>
void Heap<T>::heapSort(Heap &A){
  buildHeap(A);

	for(int i = A.length; i >= 2; i--){
		//swap
		HeapObj<T> temp;
     temp.data = A.arr[0].data;
		A.arr[0].data = A.arr[i].data;
		A.arr[i].data = temp.data;

		A.heapSize = A.heapSize-1;

		maxHeapify(A, 0);
	}
}
