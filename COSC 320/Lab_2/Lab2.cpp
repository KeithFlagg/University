//Keith Flagg
//COSC 320
//Dr. Anderson
//Lab2
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

//function prototypes for sorting algorithms
int partition(int *a, int start, int end);
void quickSort(int*a,int start,int end);

void merge(int *a, int start, int mid, int end);
void mergeSort(int *a, int start, int end);
//prints array
void print(int* a, int n);
//returns true if the array is sorted
bool isSorted(int* a, int n);
//Creates an ascending array i+1
void makeGood(int*a, int n);
//Creates a backwards array n-1
void makeBad(int*a, int n);
//Randomly populates an array
void makeRand(int*a, int n);
//creates an array filled with duplicates
void makeAlike(int* a, int n);
//copies arrays
void copy(int *a, int *b, int n);
//counter
static int count = 0;//merge counter global
static int count1 = 0;//quick counter global

int main(){
  int sizes [3]= {100,1000,50000};
  int *small = new int[sizes[0]];
  int *small1 = new int[sizes[0]];
  int *med = new int[sizes[1]];
  int *med1 = new int[sizes[1]];
  int *big = new int[sizes[2]];
  int *big1 = new int[sizes[2]];

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Small random array(n=100):"<<endl<<endl;
  //small arrays
  makeRand(small,sizes[0]);
  copy(small,small1,sizes[0]);

  //start timer
  auto start = std::chrono::system_clock::now();
  quickSort(small,0,sizes[0]-1);
  //end timer
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Small random array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(small1,0,sizes[0]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

//second test
  makeGood(small,sizes[0]);
  copy(small,small1,sizes[0]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Small 'good' array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(small,0,sizes[0]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Small 'good' array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(small1,0,sizes[0]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

//third test
  makeBad(small,sizes[0]);
  copy(small,small1,sizes[0]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Small 'bad' array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(small,0,sizes[0]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Small 'bad' array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(small1,0,sizes[0]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

//fourth test
  makeAlike(small,sizes[0]);
  copy(small,small1,sizes[0]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Small duplicate array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(small,0,sizes[0]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Small duplicate array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(small1,0,sizes[0]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;


  makeRand(med,sizes[1]);
  copy(med,med1,sizes[1]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Medium random array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(med,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Medium random array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(med1,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

//second test
  makeGood(med,sizes[1]);
  copy(med,med1,sizes[1]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Medium 'good' array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(med,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Medium 'good' array(n=100):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(med1,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

//third test
  makeBad(med,sizes[1]);
  copy(med,med1,sizes[1]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Medium 'bad' array(n=1000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(med,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Medium 'bad' array(n=1000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(med1,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

//fourth test
  makeAlike(med,sizes[1]);
  copy(med,med1,sizes[1]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Medium duplicate array(n=1000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(med,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Medium duplicate array(n=1000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(med1,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

  makeRand(big,sizes[2]);
  copy(big,big1,sizes[2]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Large random array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(big,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Large random array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(big1,0,sizes[2]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

  makeGood(big,sizes[2]);
  copy(big,big1,sizes[2]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Large 'good' array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(big,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Large 'good' array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(big1,0,sizes[2]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

  makeBad(big,sizes[2]);
  copy(big,big1,sizes[2]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Large 'bad' array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(big,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Large 'bad' array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(big1,0,sizes[2]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

  makeAlike(big,sizes[2]);
  copy(big,big1,sizes[2]);
  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Quick Sort Analyses:"<<endl<<endl;
  cout<<"Large duplicate array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  quickSort(big,0,sizes[1]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Quick Sort made "<<count1<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count1 = 0;

  cout<<"Sorting Algorithm Analysis:"<<endl<<endl;
  cout<<"Running Merge Sort Analyses:"<<endl<<endl;
  cout<<"Large duplicate array(n=50000):"<<endl<<endl;
  //start timer
  start = std::chrono::system_clock::now();
  mergeSort(big1,0,sizes[2]-1);
  //end timer
  end = std::chrono::system_clock::now();
  elapsed_seconds = end-start;
  end_time = std::chrono::system_clock::to_time_t(end);
  cout<<"Merge Sort made "<<count<<" comparisons!"<<endl;
  cout << "finished at " << std::ctime(&end_time)<< "elapsed time: " << elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl;
  count = 0;

  //deallocate arrays
  delete []small;
  delete []small1;
  delete []med;
  delete []med1;
  delete []big;
  delete []big1;
return 0;
}


//functions!!!
//utility function for sorting
void swap(int &a,int &b){
  int temp;
    temp = a;
    a = b;
    b = temp;
}

//smaller elements to left of pivot greater elements to right
int partition(int *a, int start, int end){
  int pivot = a[end]; //pivot initialized
  int i = start-1; //smaller index

  for (int j = start; j <= end-1; j++)
  {
    if (a[j] < pivot)
    {
      i++;
      swap(a[i], a[j]);
      count1++;
    }
  }
  swap(a[i+1], a[end]);
  return (i+1);
}

//recusively calls quickSort
void quickSort(int *a, int start, int end){
  if (start < end)
  {
    int i = partition(a, start, end);

    quickSort(a, start, i-1);
    quickSort(a, i+1, end);
  }
}

//fuction used by mergesort to merge arrays
void merge(int *a, int start, int mid, int end){
  int k,i,j;
  int n = mid-start+1;
  int m = end - mid;
  int L[n];
  int R[m];

  for (i = 0; i < n; i++){
        L[i] = a[start + i];
      }
  for (j = 0; j < m; j++){
        R[j] = a[mid + 1 + j];
      }

    i = 0;
    j = 0;
    k = start;

  while ((i < n) && (j < m)){
    if (L[i] <= R[j]){
      a[k] = L[i++];
    }

    else
    {
      a[k] = R[j++];
    }
    k++;
    count++;
  }

  while(i < n)
  {
    a[k++] = L[i++];
  }

  while(j < m)
  {
    a[k++] = R[j++];
  }
}

void mergeSort(int *a, int start, int end){
  if(start<end){
    int mid = (start + end)/2;
    mergeSort(a, start, mid);
    mergeSort(a, mid+1, end);
    merge(a, start, mid, end);
  }
}

bool isSorted(int* a, int n){
	for (int i=0;i<(n-1); i++){
    if (a[i]>a[i+1]){
      return false;
    }
  }
	return true;
}

void makeAlike(int* a, int n){
  for (int i=0; i<(n/2); i++){
    a[i]=i;
  }
  for (int i=(n/2); i<n; i++){
    a[i]=i;
  }
}

void makeRand(int* a, int n){

  srand(time(0));
  srand((unsigned)time(NULL));

    for(int i=0; i<n;i++){
      a[i] = (rand()%(n));
    }

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

void copy(int *a,int* b,int n){
  for (int i=0;i<n;i++){
    b[i]=a[i];
  }
}

void print(int* a, int n){
  for(int i=0; i<n; i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
}
