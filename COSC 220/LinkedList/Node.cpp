//Keith Flagg
#include <iostream>
#include "Node.h"
using namespace std;
Node::Node(){
  //cin from keyboard
  cout<< "Enter your Id number:"<<endl;
  cin>>idNumber;
  cout<<"Enter your first name:"<<endl;
  cin>>firstName;
  cout<<"Enter you last name:"<<endl;
  cin>>lastName;
  next = NULL;
}
void Node::printNode(){
  //prints node object
    cout<<idNumber<<" ";
    cout<<firstName<<" ";
    cout<<lastName<<endl;
}
