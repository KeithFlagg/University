#include "BST.h"
#include "TNode.h"
#include <iostream>

using namespace std;

BST :: BST(){
  root = NULL;
}

BST :: ~BST(){
  //destroys all tree nodes
  destroyTree(root);
}

int BST :: max(TNode*x){
if (x==NULL){
  return 0;
}
while (x->right !=NULL){
  x=x->right;
}
return x->data;
}

int BST :: min(TNode*x){
  if (x==NULL){
    return 0;
  }
  while(x->left !=NULL){
    x=x->left;
  }
  return x->data;
}

//if duplicate is found in tree returns true
bool BST :: searchNode(int k){
  TNode *ptr=root;
while(ptr)
{
  if(ptr->data==k){
    return true;
  }
  else if (k<ptr->data){
    ptr=ptr->left;
  }
  else
  ptr=ptr->right;
}
return false;
}

int BST :: success(TNode*&x, TNode*&y){
if (x-> right!= NULL)
{
  return min(x->right);
}
else
{
  y=x->parent;
  while((y!=NULL)&&(x==y->right)){
    x=y;
    y=y->parent;
  }
  return y->data;
}

}


void BST :: insert(TNode *&ptr, TNode *&newNode){
if (ptr == NULL){
  ptr=newNode;
  //inserts
}
  else if(newNode->data < ptr->data){
    insert(ptr->left,newNode);
  }
  else
  insert(ptr->right,newNode);

}

//takes in user's integer then calls the deletion function
void BST :: delet(int num, TNode*&ptr){
if(num<ptr->data){
  delet(num, ptr->left);
}
else if(num>ptr->data){
  delet(num, ptr->right);
}
else
makeDeletion(ptr);
}

void BST :: makeDeletion(TNode *& ptr){
TNode *temp = NULL;
if (ptr==NULL){
  cout<<"cannot delete a node that is empty"<<endl;
}
//reattach left
else if (ptr->right==NULL){
  temp=ptr;
  ptr=ptr->left;
  delete temp;
}
//reattach right
else if (ptr->left==NULL){
temp=ptr;
ptr=ptr->right;
delete temp;
}
//if node has two children
else
{
temp=ptr->right;

while(temp->left){
  temp = temp->left;
}
//reattach left
temp->left=ptr->left;
temp = ptr;
//reattach right
ptr=ptr->right;
delete temp;
}

}

void BST :: destroyTree(TNode *ptr){
if (ptr){
  if(ptr->left){
    destroyTree(ptr->left);
  }
  if(ptr->right){
    destroyTree(ptr->right);
  }
  delete ptr;
}


}

void BST :: remove(int num){
delet(num,root);
}

//creates node for tree
void BST :: createNode(int num){
TNode *newNode= NULL;

newNode=new TNode;
newNode->data =num;
newNode->left=newNode->right=NULL;

insert (root, newNode);
}

void BST :: inOrder(TNode *ptr){
if (ptr){
  inOrder(ptr->left);
  cout<<ptr->data<<" ";
  inOrder(ptr->right);
}
}
void BST :: preOrder(TNode *ptr){
if (ptr){
  cout<<ptr->data<<" ";
  preOrder(ptr->left);
  preOrder(ptr->right);
}
}

void BST :: postOrder(TNode *ptr){
if (ptr){
  postOrder(ptr->left);
  postOrder(ptr->right);
  cout<<ptr->data<<" ";
}
}

TNode* BST :: getRoot(){
  return root;
}
