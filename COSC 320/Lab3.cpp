//Keith Flagg
//COSC 320
//Dr. Anderson
//Lab3
#include<iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Heap {
int* arr;
int length;
int heap_size;
};

void printHeap(int *a, int n);
void swap(int&, int &);
void maxHeapify(int *a, int n);



int main(){



  return 0;
}

void maxHeapify(int *a, int size, int root){
largest = root;
left = (2*size+1);
right = (2*size+2);




}




void swap(int &a,int &b){
  int temp;
    temp = a;
    a = b;
    b = temp;
}
