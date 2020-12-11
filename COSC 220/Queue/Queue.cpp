#include "Queue.h"
#include <iostream>

using namespace std;

template <class DataType>
Queue<DataType> :: Queue(int size){
  front=NULL;
  back=NULL;
  queueSize=size;
  QueueCnt=0;
}

template <class DataType>
Queue<DataType> :: ~Queue(){
  while(QueueCnt!=0){
  deQueue();
  }
}

template <class DataType>
bool Queue<DataType> :: isEmpty() const {
if (QueueCnt==0){
        return true;
      }
    else{
        return false;
      }
}

template <class DataType>
bool Queue<DataType> :: isFull() const {
if (QueueCnt== queueSize){
        return true;
      }
    else{
        return false;
      }
}

template <class DataType>
DataType Queue<DataType> :: topQueue() const{
  if(!isEmpty()){
    return front->data;
  }
  else {
    cout<<"The Queue is empty!"<<endl;
  }
}

template <class DataType>
void Queue<DataType> :: enQueue(const DataType Z){
  if (isFull()){
  cout<<"The Queue is full!"<<endl;
  cout<<"You have "<<QueueCnt<<" nodes in the Queue."<<endl;
  }
  else if (isEmpty())
  {
    QueNode<DataType>* temp = new QueNode<DataType>;
    temp->data=Z;
    back = temp;
    front = temp;
    QueueCnt++;
    cout<<"You have "<<QueueCnt<<" nodes in the Queue."<<endl;
  }
  else{
    QueNode<DataType>* temp = new QueNode<DataType>;
    temp->data= Z;
    back->next= temp;
    back= temp;
    QueueCnt++;
    cout<<"You have "<<QueueCnt<<" nodes in the Queue."<<endl;
  }
}

template <class DataType>
void Queue<DataType> :: deQueue(){
  //makes two pointers to traverse the linked list
  QueNode <DataType> *temp= NULL;
  if (QueueCnt==0){
    cout<<"The Queue is empty!"<<endl;
  }

  else {
  temp=front;
  front=front->next;
  delete temp;
  QueueCnt--;
  }
}
