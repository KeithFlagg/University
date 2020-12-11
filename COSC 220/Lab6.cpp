#include <iostream>
#include "Queue.h"
#include "Students.h"

using namespace std;

int main(){

char choice = '0';

cout<<"Hello, please choose the data type of the queue you would like to create:"<<endl;
cout<<"Press 1 -> Student Queue"<< endl<<"Press 2 -> integer Queue"<<endl;

cin>>choice;
switch(choice){
case '1':
{
  //student type
  char choice1='0';
  Queue <Students> Queue;
  do{
        cout<<endl;
        cout<<"Please select an option:"<<endl;
        //menu options
        cout<<"1 -> Enqueue"<<endl<<"2 -> Dequeue"<<endl<<"3 -> Display the front of queue"<<endl<<"4 -> Quit"<<endl;
        cin>>choice1;
        cout<<endl;

      switch (choice1){
        case '1':
        //inserting a node
        {
          if (Queue.isFull()){
            cout<<"The queue is full!";
            break;
          }
          else if (!Queue.isFull()){
          Students newguy;
          cout<< "Enter the first name: "<< endl;
          cin>>newguy.firstName;
          cout << "Enter the lastName: "<<endl;
          cin>>newguy.lastName;
          cout << "Enter ID: "<<endl;
          cin>> newguy.idNumber;
          cout<<endl;
          Queue.enQueue(newguy);
          break;
        }
    }
        case '2':{
        Queue.deQueue();

        break;
    }
       case '3':{
      //printing the student
        if(!(Queue.isEmpty())){
        Queue.topQueue().printStudent();
        break;
      }
      else
      cout<<"No students to print!"<<endl;
        break;
    }
    case '4':{
      break;
    }
       default:
    cout<<"Not a valid menu option!"<<endl;
    break;
      }
    }while (choice1!='4');
    break;
}

case '2':
{
  //integer type
  Queue <int> Queue;
  int i = 0;
  char choice2 ='0';
  do{
        cout<<endl;
        cout<<"Please select an option:"<<endl;
        //menu options
        cout<<"1 -> Enqueue"<<endl<<"2 -> Dequeue"<<endl<<"3 -> Display the front of queue"<<endl<<"4 -> Quit"<<endl;
        cin>>choice2;
        cout<<endl;
      switch (choice2){
      case '1':
        //inserting an integer
        {
          cout<<"Enter an integer to enqueue:"<<endl;
          cin>>i;
          Queue.enQueue(i);
          break;
    }
      case '2':{
        Queue.deQueue();
        break;
    }
      case '3':{
      //printing the integer
      cout<<endl;
      if (!Queue.isEmpty()){
      cout<<  "Top of the Queue: "<< Queue.topQueue() <<endl<<endl;
      break;
    }
    else if (Queue.isEmpty()){
      cout<<"The Queue is empty!"<<endl;
      break;
    }
    }
      case '4':{
        break;
    }
      default:

    cout<<"Not a valid menu option!"<<endl;
    break;

    }
}while (choice2!='4');
  break;
}
break;
default:
cout<< "Not an option from the menu!"<<endl;
break;
}

return 0;
}
