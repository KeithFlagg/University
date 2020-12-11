#include "Stack.h"
#include <iostream>
using namespace std;

template <class DataType>
Stack<DataType> :: Stack(int size){
top = NULL;
maxSize=size;
numNode=0;
}

template <class DataType>
Stack<DataType> :: ~Stack(){
while(numNode!=0){
   pop();//destroys stack
}
}

template <class DataType>
bool Stack<DataType> :: isEmpty() const {
if (top == NULL){
        return true;
      }
    else{
        return false;
      }
}

template <class DataType>
bool Stack<DataType> :: isFull() const {
  if(maxSize==numNode){
      return true;
  }
  else{
    return false;
  }
}

template <class DataType>
DataType Stack<DataType> :: topStack() const{
  if (top){
    //returns first element
return top->data;
}
    else if(!top)
    {
      cout<<"Stack is empty!"<<endl;
    }
}

template <class DataType>
void Stack<DataType> :: push(const DataType C) {

    if (top == NULL) {
        this->top = new StackNode<DataType>;
        top->next = NULL;
        top->data = C;
        numNode++;
        cout<<"You have "<<numNode<<" nodes in the stack."<<endl;
    }
    else {
        StackNode<DataType>* temp = new StackNode<DataType>;
        temp->data = C;
        temp->next = this->top;
        this->top = temp;
        numNode++;
        cout<<"You have "<<numNode<<" nodes in the stack."<<endl;
    }
}

template <class DataType>
void Stack<DataType> :: pop(){
  if (top == NULL) {
          cout << "The stack is empty!" << endl;
          numNode=0;
          cout<<"You have "<<numNode<<" nodes in the stack."<<endl;
          return;
      }
      else {
          StackNode<DataType>* temp = top;
          top = top->next;
          delete temp;
          numNode--;
          cout<<"You have "<<numNode<<" nodes in the stack."<<endl;
      }
  }
