//Keith Flagg
//COSC 320
//Dr. Anderson
//Lab1
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

void bubbleSort(int* a, int size);
void insertionSort(int* a, int size);
void selectionSort(int* a, int size);
// swapping funct for sorts
void swap(int *x, int *y);
//prints array
void print(int* a, int n);
//Creates an ascending array i+1
void makeGood(int*a, int n);
//Creates a backwards array n-1
void makeBad(int*a, int n);
//Randomly populates an array
void makeRand(int*a, int n);
//returns true if the array is sorted
bool isSorted(int* a, int n);
//creates an array filled with duplicates
void makeAlike(int* a, int n);

void copy(int *a, int *b, int n);

int main(){
int sizes [3]= {100,1000,10000};
int *small = new int[sizes[0]];
int *small1 = new int[sizes[0]];
int *small2 = new int[sizes[0]];
int *med = new int[sizes[1]];
int *med1 = new int[sizes[1]];
int *med2 = new int[sizes[1]];
int *big = new int[sizes[2]];
int *big1 = new int[sizes[2]];
int *big2 = new int[sizes[2]];

cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"Small random array(n=100):"<<endl<<endl;
//small arrays
makeRand(small,sizes[0]);
copy(small,small1,sizes[0]);
copy(small1,small2,sizes[0]);
//start timer
auto start = std::chrono::system_clock::now();
bubbleSort(small,sizes[0]);
//end timer
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running insertion Sort Analyses:"<<endl<<endl;
cout<<"Small random array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(small1,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running selection Sort Analyses:"<<endl<<endl;
cout<<"Small random array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(small2,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

makeGood(small,sizes[0]);
copy(small,small1,sizes[0]);
copy(small1,small2,sizes[0]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"small 'good' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(small,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running insertion Sort Analyses:"<<endl<<endl;
cout<<"small 'good' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(small1,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running selection Sort Analyses:"<<endl<<endl;
cout<<"small 'good' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(small2,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

makeBad(small,sizes[0]);
copy(small,small1,sizes[0]);
copy(small1,small2,sizes[0]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"small 'bad' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(small,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"small 'bad' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(small1,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"small 'bad' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(small2,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

makeAlike(small,sizes[0]);
copy(small,small1,sizes[0]);
copy(small1,small2,sizes[0]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"small 'duplicate' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(small,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"small 'duplicate' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(small1,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"small 'duplicate' array(n=100):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(small2,sizes[0]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;




//medium arrays
makeGood(med,sizes[1]);
copy(med,med1,sizes[1]);
copy(med1,med2,sizes[1]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"medium 'good' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(med,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"medium 'good' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(med1,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"medium 'good' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(med2,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << std::ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;


makeBad(med,sizes[1]);
copy(med,med1,sizes[1]);
copy(med1,med2,sizes[1]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"medium 'bad' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(med,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"medium 'bad' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(med1,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"medium 'bad' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(med2,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

makeRand(med,sizes[1]);
copy(med,med1,sizes[1]);
copy(med1,med2,sizes[1]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"medium 'random' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(med,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running insertion Sort Analyses:"<<endl<<endl;
cout<<"medium 'random' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(med1,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"medium 'random' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(med2,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;


makeAlike(med,sizes[1]);
copy(med,med1,sizes[1]);
copy(med1,med2,sizes[1]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"medium 'duplicate' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(med,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"medium 'duplicate' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(med1,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"medium 'duplicate' array(n=1000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(med2,sizes[1]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

//Large arrays
makeBad(big,sizes[2]);
copy(big,big1,sizes[2]);
copy(big1,big2,sizes[2]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"Large 'bad' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(big,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"Large 'bad' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(big1,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running insertion Sort Analyses:"<<endl<<endl;
cout<<"Large 'bad' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(big2,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;


makeGood(big,sizes[2]);
copy(big,big1,sizes[2]);
copy(big1,big2,sizes[2]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"Large 'Good' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(big,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"Large 'Good' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(big1,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;


cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"Large 'Good' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(big2,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

makeRand(big,sizes[2]);
copy(big,big1,sizes[2]);
copy(big1,big2,sizes[2]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"Large 'Random' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(big,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"Large 'Random' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(big1,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"Large 'Random' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(big2,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;


makeAlike(big,sizes[2]);
copy(big,big1,sizes[2]);
copy(big1,big2,sizes[2]);
cout<<"Running Bubble Sort Analyses:"<<endl<<endl;
cout<<"Large 'duplicate' array (n=10000): "<<endl<<endl;
start = std::chrono::system_clock::now();
bubbleSort(big,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)
<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Insertion Sort Analyses:"<<endl<<endl;
cout<<"Large 'duplicate' array (n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
insertionSort(big1,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

cout<<"Running Selection Sort Analyses:"<<endl<<endl;
cout<<"Large 'duplicate' array(n=10000):"<<endl<<endl;
start = std::chrono::system_clock::now();
selectionSort(big2,sizes[2]);
//end timer
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);
std::cout << "finished at " << ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;

delete []small;
delete []small1;
delete []small2;
delete []med;
delete []med1;
delete []med2;
delete []big;
delete []big1;
delete []big2;
  return 0;
}




//swaps for bubble
void swap(int *x, int *y){
  int temp = *x;
  *x = *y;
  *y = temp;
}

void print(int* a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

void bubbleSort(int* a, int size){
  bool swapped;
  int count=0;
  for (int i=0; i < size-1; i++){
    swapped = false;
    for (int j=0; j < size-i-1; j++){
      if(a[j]>a[j+1]){
        swap(&a[j],&a[j+1]);
        swapped = true;
        count++;

      }
    }
    if (swapped==false){
      break;
    }
  }
  cout<<"Bubble sort swapped "<<count<<" times!"<<endl;
}

void selectionSort(int* a, int size){
  int min, count=0;
for (int i=0; i<size-1;i++){
  min = i;
  for (int j = i+1; j < size; j++){
        if (a[j] < a[min]){
            min = j;
          }
        }
        swap(&a[min], &a[i]);
        count++;
    }
    cout<<"Selection sort swapped "<<count<<" times!"<<endl;
}

bool isSorted(int* a, int n){
	for (int i=0;i<(n-1); i++){
    if (a[i]>a[i+1]){
      return false;
    }
  }
	return true;
}

void insertionSort(int* a, int size){
  int num, j, count=0;
  for (int i=1; i<size;i++){
    num = a[i];
    j= i-1;

  while(j>=0 && a[j]>num){
    a[j+1]=a[j];
    j=j-1;
    }
    a[j+1]=num;
    count++;
  }
  cout<<"insertion sort swapped "<<count<<" times!"<<endl;
}

void makeGood(int* a, int n){
  for(int i=0;i<n;i++){
    a[i]=i+1;
  }
}

void makeBad(int* a, int n){
  int num=n-1;
  for(int i=0; i<n; i++){
    a[i] = num--;
  }
}

void makeRand(int* a, int n){
  srand(time(0));
  srand((unsigned)time(NULL));

  for(int i=0; i<n;i++){
    a[i] = (rand()%(n));
  }
}

void makeAlike(int* a, int n){
  for (int i=0; i<(n/2); i++){
    a[i]=i;
  }
  for (int i=(n/2); i<n; i++){
    a[i]=i;
  }
}

void copy(int *a,int* b,int n){
for (int i=0;i<n;i++){
  b[i]=a[i];
}
}
