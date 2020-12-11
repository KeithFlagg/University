#include "BST.h"
#include <iostream>

using namespace std;

BST :: BST(){
  root = NULL;
}

BST :: ~BST(){
  //destroys all tree nodes
  destroyTree(root);
}

void BST :: printNode(Node* node){
  if (node){
  cout<<node->data<<endl;
  }
}

int BST :: max(Node*x){
  if (x==NULL){
  return 0;
  }
  while (x->right !=NULL){
    x = x->right;
  }
  return x->data;
}

int BST :: min(Node*x){
  if (x == NULL){
    return 0;
  }
  while(x->left != NULL){
    x = x->left;
  }
  return x->data;
}

//switches nodes in the BST
void BST :: transplant(Node* oldNode, Node* newNode){
  if ((oldNode == root) && (oldNode->parent == nullptr)) {
  		root = newNode;
  	}
    else if (oldNode->parent->right == oldNode) {
  		oldNode->parent->right = newNode;
  	}
    else {
  		oldNode->parent->left = newNode;
  	}

  	if (newNode != nullptr) {
  		newNode->parent = oldNode->parent;
  	}
}

//searches for the key
Node* BST :: searchNode(int k){
  if (root == nullptr){
    return root;
  }
  Node *ptr = root;
  while(ptr)
  {
    if(ptr->data == k){
      return ptr;
    }
    else if (k < ptr->data){
      ptr = ptr->left;
    }
    else
    ptr = ptr->right;
  }
return nullptr;
}

int BST :: success(Node*x){
  if (x-> right != NULL)
  {
    return min(x->right);
  }
  else
  {
    Node* y = x->parent;

    while((y != NULL)&&(x == y->right)){
      x = y;
      y = y->parent;
    }
  return y->data;
  }

}


void BST :: insert(int key){

Node* newNode = new Node;
newNode->left = nullptr;
newNode->right = nullptr;
newNode->parent = nullptr;
newNode->data = key;

Node* curr = root;
Node* prev = root;

  while (curr){
    prev = curr;

    if (newNode->data < curr->data){
      curr = curr->left;
    }
    else{
      curr = curr->right;
    }
  }

  newNode->parent = prev;

  if (prev == nullptr){
    root = newNode;
  }

  else if (newNode->data < prev->data){
    prev->left = newNode;
  }
  else{
    prev->right = newNode;
  }
}

void BST :: deleteNode(int num){
Node *temp = searchNode(num);

  if (temp == NULL){
    cout<<"cannot delete node!"<<endl;
  }
  else{
    if (temp->left == NULL){
      transplant(temp,temp->right);
    }
    else if (temp->right == NULL) {
		    transplant(temp, temp->left);
	  }
    else {
        Node* curr = temp->right;

    //min
		while (curr->left) {
			curr = curr->left;
		}

		Node* newNode = curr;

		if (newNode != temp->right) {
			transplant(newNode, newNode->right);
			newNode->right = temp->right;
			newNode->right->parent = newNode;
		}

		transplant(temp, newNode);
		newNode->left = temp->left;
		newNode->left->parent = newNode;
		delete temp;
	  }
  }

}

void BST :: destroyTree(Node *ptr){
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

void BST :: inOrder(Node *ptr){
  if (ptr){
    inOrder(ptr->left);
    cout<<ptr->data<<" ";
    inOrder(ptr->right);
  }
}

void BST :: preOrder(Node *ptr){
  if (ptr){
    cout<<ptr->data<<" ";
    preOrder(ptr->left);
    preOrder(ptr->right);
  }
}

void BST :: postOrder(Node *ptr){
  if (ptr){
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout<<ptr->data<<" ";
  }
}

Node* BST :: getRoot(){
  if(root){
  return root;
  }
  return nullptr;
}
