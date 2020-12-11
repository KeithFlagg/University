#include "heap.h"
#include <iostream>

using namespace std;

Heap :: Heap(){
size = 10;

int arr1[]={4, 12, 3, 19, 23, 5, 32, 11, 2, 24};
for (int i =0;i<10;i++){
  arr[i]=arr1[i];
}
buildHeap();
}

Heap :: ~Heap(){

}

void Heap :: swap(int &x, int &y)
{
  //swap references
    int temp = x;
    x = y;
    y = temp;
}

int Heap :: parent(int i){
  if ((i%2)==0){
    return ((i-1)/2);
  }
  else{
    return ((i-2)/2);
  }
}

int Heap :: left(int i){
  return ((2*i)+1);
}

int Heap :: right(int i){
  return ((2*i)+2);
}

void Heap :: heapify(int i){
  int l,r,largest;
  l=left(i);
  r=right(i);
  largest = i;
//left larger than root
  if ((l<size)&&(arr[l]>arr[largest])){
    largest=l;
  }
  //right is larger than max
    if ((r<size)&&(arr[r]>arr[largest]))
    {
  largest=r;
  }
//if largest is not root
  if (largest!=i){
    swap(arr[i],arr[largest]);
    heapify(largest);
  }
}

//creates heap property
void Heap :: buildHeap(){
  for(int i=((size/2)-1);i>=0;i--){
    heapify(i);
  }
}

void Heap :: sort(){
  buildHeap();
  int tempsize = size;
  for(int i=size-1;i>=1;i--){
    swap(arr[0],arr[i]);
    size--;
    heapify(0);
  }
  size = tempsize;
}

void Heap :: printHeap(){

  cout<<"The heap array is: "<<endl;
  for (int i=0; i<size;++i){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}

int Heap :: extractMax(){
  int max=0;

  if (size < 1){
    cerr<<"Heap Underflow!"<<endl;
    return -1;
  }
  else {
    max=arr[0];
    arr[0]=arr[size-1];
    size=size-1;
    heapify(0);
    return max;
  }
}

int Heap :: max(){
  int max = arr[0];
		for(int i = 1; i < size;i++)
		{
			if(arr[i] > max)
			{
				max = arr[i];
			}
		}
    return max;
}

void Heap :: insert(int n){
  size++;

  //highest index
  int i=size-1;
  //copies val
  arr[i]=n;

  while((i>=0)&&(arr[parent(i)])<arr[i]){
    swap(arr[i], arr[parent(i)]);
    i = parent(i);
  }
}
