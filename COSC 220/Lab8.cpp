#include <iostream>
#include "heap.h"

using namespace std;

int main(){
  char choice = '0';
  int insert = 0;

  cout<<"Welcome to your array heap builder! Please select an option:"<<endl;

  Heap *heap = new Heap;


  do{
    cout<<endl;
    cout<<"1.) insert an element into your heap."<<endl<<"2.) Display the max value."<<endl<<"3.) extract the maximum element."<<endl<<"4.) Display the heap"<<endl<<"5.) Quit"<<endl<<endl;
    cin>>choice;
    cout<<endl;

      if (choice == '1'){
        cout<<"Please enter an integer to insert into your heap: "<<endl;
        cin>>insert;
        heap->insert(insert);
      }
      else if (choice == '2'){
        cout<<"The maximum value is: "<<endl;
        cout<<heap->max()<<endl;
      }

      else if (choice == '3'){
        cout<<"The maximum element is: "<<endl;
        cout<<heap->extractMax()<<endl;
      }
      else if (choice=='4'){
        heap->printHeap();
      }
      else if (choice!='5'){
        cout<<"Please select a valid menu option!"<<endl;
      }
  }while (choice!='5');

heap->sort();
  //prints
  heap->printHeap();
  cout<<endl<<"Thank You!"<<endl;
  delete heap;


return 0;
}
