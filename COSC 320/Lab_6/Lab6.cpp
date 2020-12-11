//Keith Flagg
//COSC 320
//Dr. Anderson
//Lab6
#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <fstream>



using namespace std;

void swap(int &a, int &b);

void shuffle(int* a, int n);

void makeGood(int*a, int n);

void print(int* a, int n);

int hireAssisstant(int *arr, int n);

int partition(int *a, int start, int end);

void quickSort(int*a,int start,int end);

void randquickSort(int*a,int start,int end);

void merge(int *a, int start, int mid, int end);

void mergeSort(int *a, int start, int end);

void copy(int *a, int *b, int n);

void heapSort(int a[], int n);

void buildHeap(int a[], int n);

void heapify(int a[], int n, int i);

static int count = 1;

int main(){
cout<<fixed<<setprecision(15);
srand(time(0));
ofstream hire;
ofstream quick;
ofstream randquick;
ofstream merge;
ofstream heap;

hire.open("hire.txt");
quick.open("quicksort.txt");
randquick.open("randquicksort.txt");
merge.open("mergesort.txt");
heap.open("heapsort.txt");

double sum;
double sum1, sum2, sum3, sum4;
int sizes [20] = {10000, 60000, 110000,160000,210000,260000,310000,360000,410000,460000,510000,560000,610000,660000,710000,760000,810000,860000,910000,960000};
auto start = std::chrono::system_clock::now();
auto end = std::chrono::system_clock::now();
std::chrono::duration<double> elapsed_seconds = end-start;
std::chrono::duration<double> avr = elapsed_seconds;
std::time_t end_time = std::chrono::system_clock::to_time_t(end);

hire<<"Hire Assistant"<<endl;
quick<<"Quicksort"<<endl;
randquick<<"Quicksort randomized"<<endl;
merge<<"Mergesort"<<endl;
heap<<"Heapsort"<<endl;



//3(c)
  for(int i = 0; i<20; i++){
    cout<<endl<< endl<<"Analyzing hire assistant:"<<endl;

    int *arr = new int [sizes[i]];
    //creates ascending array
    makeGood(arr, sizes[i]);
    hire<<endl<<"Size: "<<sizes[i]<<endl;
    //shuffles array
      for(int j = 0; j < 10; j++) {
        shuffle(arr, sizes[i]);


        //hire assistant runs
        start = std::chrono::system_clock::now();
        hireAssisstant(arr, sizes[i]);
        end = std::chrono::system_clock::now();
        elapsed_seconds = end-start;
        end_time = std::chrono::system_clock::to_time_t(end);

        cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
        cout<<"New assistant hired "<< count << " times!"<<endl;
        count = 1;
        sum += elapsed_seconds.count();
        hire<<elapsed_seconds.count()<<",";
      }
      cout<<"Avg. Time: "<<sum/20.0<<endl;
      hire<<endl<<"Avg: " << sum/20.0<<",";
      cout<<"For size of n = " << sizes[i] << endl;
      delete []arr;


  }

for(int i = 0; i < 20; i++){
int *arr1 = new int [sizes[i]];
int *arr2 = new int [sizes[i]];
int *arr3 = new int [sizes[i]];
int *arr4 = new int [sizes[i]];
makeGood(arr1,sizes[i]);
shuffle(arr1,sizes[i]);
copy(arr1,arr2,sizes[i]);
copy(arr1,arr3,sizes[i]);
copy(arr1,arr3,sizes[i]);
copy(arr1,arr4,sizes[i]);
int n = 0;
sum1=0;
sum2=0;
sum3=0;
sum4=0;
quick<<endl<<"size: "<<sizes[i]<<endl;
randquick<<endl<<"size: "<<sizes[i]<<endl;
merge<<endl<<"size: "<<sizes[i]<<endl;
heap<<endl<<"size: "<<sizes[i]<<endl;




for(int j = 0; j < 10; j++){
cout << "Timing quicksort (normal) n = " << sizes[i] << endl;

//quickSort
shuffle(arr1,sizes[i]);
start = std::chrono::system_clock::now();
quickSort(arr1,0,sizes[i]-1);

end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);

cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
sum1 += elapsed_seconds.count();
quick<<elapsed_seconds.count()<<",";

cout << "Timing quicksort (randomized) n = " << sizes[i] << endl;
//randomizedquicksort
shuffle(arr2,sizes[i]);
start = std::chrono::system_clock::now();

randquickSort(arr2,0,sizes[i]-1);
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);

cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
sum2 += elapsed_seconds.count();
randquick<<elapsed_seconds.count()<<",";


cout << "Timing mergesort n = " << sizes[i] << endl;

//mergesort
shuffle(arr3,sizes[i]);
start = std::chrono::system_clock::now();
mergeSort(arr3,0,sizes[i]-1);
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);

cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
sum3 += elapsed_seconds.count();
merge<<elapsed_seconds.count()<<",";



cout << "Timing heapsort n = " << sizes[i] << endl;

//heapsort
shuffle(arr4,sizes[i]);
n = sizeof(arr4)/sizeof(arr4[0]);
start = std::chrono::system_clock::now();
heapSort(arr4,0);
end = std::chrono::system_clock::now();
elapsed_seconds = end-start;
end_time = std::chrono::system_clock::to_time_t(end);

cout << "finished at: " <<ctime(&end_time)<< "elapsed time: " <<elapsed_seconds.count() << "s\n"<<"-------------------------------"<<endl<<endl;
sum4 += elapsed_seconds.count();
heap<<elapsed_seconds.count()<<",";

}
cout<<"For qucksort (normal) n = "<< sizes[i]<<" Avg. Time: "<<sum1/10.0<<endl;
cout<<"For qucksort (randomized) n = "<< sizes[i]<<" Avg. Time: "<<sum2/10.0<<endl;
cout<<"For mergesort n = "<< sizes[i]<<" Avg. Time: "<<sum3/10.0<<endl;
cout<<"For heapsort n = "<< sizes[i]<<" Avg. Time: "<<sum4/10.0<<endl<<endl;

quick<<endl<<"Avg: "<<sum1/10.0<<endl;
randquick<<endl<<"Avg: "<<sum2/10.0<<endl;
merge<<endl<<"Avg: "<<sum3/10.0<<endl;
heap<<endl<<"Avg: "<<sum4/10.0<<endl;






delete []arr1;
delete []arr2;
delete []arr3;
delete []arr4;

}

hire.close();
quick.close();
randquick.close();
merge.close();
heap.close();
return 0;
}

void swap(int &a,int &b){
  int temp;
    temp = a;
    a = b;
    b = temp;
}

void shuffle(int* a, int n){
int size = n;
int num = 0;

  for(int i = 0; i < size-1; i++){
    num = (rand()%(size));
    swap(a[i],a[num]);
  }
}

void makeGood(int* a, int n){
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
}

void print(int* a, int n){
	for(int i=0; i<n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

int hireAssisstant(int *arr, int n){
int best = 0;

  for(int i = 0; i < n; i++){
    if(arr[i]>arr[best]){
      best = i;
      count++;
    }
  }
  return best;
}

int partition(int *a, int start, int end){
  int pivot = a[end]; //pivot initialized
  int i = start-1; //smaller index

  for (int j = start; j <= end-1; j++)
  {
    if (a[j] < pivot)
    {
      i++;
      swap(a[i], a[j]);
    }
  }
  swap(a[i+1], a[end]);
  return (i+1);
}

void quickSort(int *a, int start, int end){
  if (start < end)
  {
    int i = partition(a, start, end);

    quickSort(a, start, i-1);
    quickSort(a, i+1, end);
  }
}

void randquickSort(int *a, int start, int end){
  if (start < end)
  {
    int i = partition(a, start, (rand()%end));

    quickSort(a, start, i-1);
    quickSort(a, i+1, end);
  }
}

void copy(int *a,int* b,int n){
  for (int i=0;i<n;i++){
    b[i]=a[i];
  }
}

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

void heapify(int a[], int n, int i){

    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if ((l < n) && (a[l] > a[largest])) {
        largest = l;
  }

    if ((r < n) && (a[r] > a[largest])) {
        largest = r;
  }

    if (largest != i)
    {
        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}

void buildHeap(int a[], int n){
  for (int i = n / 2 - 1; i >= 0; i--)
      heapify(a, n, i);
}


void heapSort(int a[], int n){

    buildHeap(a, n);

    for (int i = (n-1); i>=0; i--)
    {
        swap(a[0], a[i]);

        heapify(a, i, 0);
    }
}
