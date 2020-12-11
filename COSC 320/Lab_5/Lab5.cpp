#include "Heap.cpp"
#include <iostream>
#include <ctime>

using namespace std;

int main(){

  char choice = '0';
  int size = 0;
  int insert = 0;
  std :: string name;

  cout << endl << cyan << "Please enter the number of nodes in the heap: "<< reset <<endl;
  cin >> size;

  std :: string* arr = new string[size];

  for(int l = 0; l < size; l++){
      std::string name;
      cout << cyan << "Please enter a string: " << endl;
      cin >> name;
      arr[l] = name;
    };


  int* prior = new int[size];

  //sets priority
  for(int i = 0; i < size; i++){
    arr[i] = i;
  }

  //creates heap object
  Heap<std::string> Test(arr, prior, size);

  do{
      cout<<endl;
      cout<< red << "1.) insert an element into your heap."<< reset << endl<< green << "2.) Display the max value."<< reset << endl<< cyan << "3.) extract the maximum element."<< reset << endl << magenta << "4.) Display the heap"<< reset << endl<< red << "5.) Quit" << reset <<endl<<endl;
      cin>>choice;
      cout<<endl;

        if (choice == '1'){
          cout<< green <<"Please enter a string to insert into your heap with an integer priority: "<< reset <<endl;
          cin>>name;
          cin >> insert;
          Test.insert(name, insert);
        }
        else if (choice == '2'){
          Test.peek();
          cout<< endl;
        }

        else if (choice == '3'){
          Test.extractMax(Test);
        }
        else if (choice=='4'){
          Test.print();
        }
        else if (choice!='5'){
          cout<< red << "Please select a valid menu option!"<< reset << endl;
        }
    }while (choice!='5');

    //sorts
    Test.heapSort(Test);
    //prints
    Test.print();
    cout<<endl<< green <<"Thank You!" << reset<<endl;
    delete arr;
    delete prior;

  return 0;
}
