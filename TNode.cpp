#include <iostream>
#include "TNode.h"

using namespace std;

TNode :: TNode(){
  parent = NULL;
  left = NULL;
  right = NULL;

}

//prints value of node
void TNode :: printNode(){
  cout<<data<<endl;
}
