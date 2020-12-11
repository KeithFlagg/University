#include <iostream>
#include "Stack.h"
#include "Students.h"

using namespace std;

int main(){
  char choice='0';
cout<<"Hello, please choose your stack type:"<< endl;
cout<<"1.) student structure"<<endl<<"2.) integer stack"<<endl;
cin>>choice;
switch(choice){

  case '1':
  {
    //student type
    char choice1='0';
    Stack <Students> stack;
    do{
          cout<<endl;
          cout<<"Please select an option:"<<endl;
          //menu options
          cout<<"1. Push Stack"<<endl<<"2. Pop Stack"<<endl<<"3. Print node"<<endl<<"4. Quit"<<endl;
          cin>>choice1;

        switch (choice1){
          case '1':
          //inserting a node
          {
            if (stack.isFull()){
              cout<<"The stack is full!";
              break;
            }
            else if (!stack.isFull()){
            Students newguy;
            cout<< "Enter the first name: "<< endl;
            cin>>newguy.firstName;
            cout << "Enter the lastName: "<<endl;
            cin>>newguy.lastName;
            cout << "Enter ID: "<<endl;
            cin>> newguy.idNumber;
            cout<<endl;
            stack.push(newguy);
            break;
          }
      }
          case '2':{
          stack.pop();
          break;
      }
         case '3':{
        //printing the student
          if(!stack.isEmpty()){
          stack.topStack().printStudent();
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
    Stack <int> stack;
    int i = 0;
    char choice2 ='0';
    do{
          cout<<endl;
          cout<<"Please select an option:"<<endl;
          //menu options
          cout<<"1. Push Stack"<<endl<<"2. Pop Stack"<<endl<<"3. Print node"<<endl<<"4. Quit"<<endl;
          cin>>choice2;

        switch (choice2){
        case '1':
          //inserting an integer
          {
            cout<<"Type an integer to push"<<endl;
            cin>>i;
            stack.push(i);
            break;
      }
        case '2':{
          stack.pop();
          break;
      }
        case '3':{
        //printing the integer
        cout<<endl;
        if (!stack.isEmpty()){
        cout<<  stack.topStack() <<endl<<endl;
        break;
      }
      else if (stack.isEmpty()){
        cout<<"stack is empty"<<endl;
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
  cout<< "Not an option!"<<endl;

}



  return 0;
}
