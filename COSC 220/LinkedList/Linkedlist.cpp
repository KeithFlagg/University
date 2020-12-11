//Keith Flagg
#include <iostream>
#include "Linkedlist.h"
using namespace std;

Node *Linkedlist::createNode(){
  //makes a new node
Node *n = new Node;
return n;
}

Linkedlist::~Linkedlist(){
  Node *prev = NULL;
  //keeps track of prev node
  prev = head;
  while(prev!=NULL){
    Node *next=prev->next;
    //keeps track of next node
    delete prev;
    //deletes the node before
    prev=next;
}
head = NULL;
}


Linkedlist::Linkedlist(){
head = NULL;
}

Node *Linkedlist::searchLocation(int id){
if (head==NULL){
  //check if empty
  return NULL;
}
Node* curr=head;
  while((curr != NULL) && (curr->idNumber != id)){
    //condition not empty not = id
    curr=curr->next;
    //moves pointer though list
  }
  return curr;
}

//inserts node
void Linkedlist::insertNode(){
Node *temp = head;
Node *n = createNode();
// creates node
if (head == NULL){
  head = n;
  //only one element in list
}
else if (searchLocation(n->idNumber) == NULL)
{
  Node* prev = NULL;
  while ((temp != NULL) && (temp->idNumber < n->idNumber))
  //checks if there is a node in list
  {
    prev=temp;//saves head pointer
    temp=temp->next;
  }
  if (prev == NULL)
  {
    //if there is nothing assign head to insert
    n->next=temp;
    head=n;
  }
  else
  {
    //insert at end
    n->next=temp;
    prev->next=n;
  }
}
  else
  cout<<"This student is already in the list!"<<endl;
}



void Linkedlist::deleteNode(int id){
  Node* prev = NULL;
  //keeps prev node
  Node* ptr1 = head;
  if(searchLocation(id) !=NULL){
  while ((ptr1 != NULL) && (ptr1->idNumber != id))
  {
    prev=ptr1;
    //assigns the previous pointer
    ptr1=ptr1->next;
    //moves to the next pointer
  }
  if (prev == NULL)
  //first node
  {
    head=head->next;
  }
  else
  {
    prev->next = prev->next->next;
    //skips node to make sure it is not deleted
  }
  delete ptr1;
  //deletes ptr1
}
else if(searchLocation(id)==NULL){
  //If it returns NULL student is not found
  cout<<"Cannot delete not found in list!"<<endl;
}
}




void Linkedlist::printList(){
  Node *curr = head;
  //keeps track of current node
  while(curr!=NULL){
    curr->printNode();
    curr=curr->next;
  }
  cout<<endl;
}

void Linkedlist::searchNode(){
  int id=0;
  cout<<"Please enter an id to search"<<endl;
    cin >> id;
    //search for val
    //keeps track of prev node


      if(searchLocation(id)){
        cout<<id<<" was found in list!"<<endl;
      }
    //cout if val in list or not
    else if (searchLocation(id)==NULL){
      cout<<id<<" was not found!"<<endl;
    }

}
