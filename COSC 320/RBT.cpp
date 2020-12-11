#include "RBT.h"
#include <iostream>
using namespace std;

//fancy colors
const std::string cyan("\033[0;36m");
const std::string reset("\033[0m");
const std::string magenta("\033[0;35m");
const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string yellow("\033[1;33m");

RBT :: Tnode* const RBT :: nil = new Tnode({0,BLACK,NULL,NULL,NULL});

//frees nil nodes
void RBT :: deleteNil(){
  delete nil;
}

//constructor
RBT :: RBT(){
  root = nil;
  root->parent = nil;
  size = 0;
}

//destructor
RBT :: ~RBT(){
  destroyTree(root);
}

void RBT :: destroyTree(Tnode* node){
  if(node != nil){
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
  }
}

int RBT :: search(int k) {
	Tnode* found = _search(k);
	if (found == NULL) {
		cout << "Key not found!" << endl;
		return -1;
	}
	return found->key;
}

RBT :: Tnode* RBT :: _search(int k) {
	if (root == nil) {
		return NULL;
	}
	Tnode* curr = root;
	while (curr != nil) {
		if (curr->key == k) {
			return curr;
		}
    else if (curr->key > k) {
			curr = curr->left;
		}
    else {
			curr = curr->right;
		}
	}
	return NULL;
}

int RBT :: success(int k) {
	Tnode* node = _success(k);

	if (node == NULL) {
		cout << "key was not found!"<<endl;
		return -1;
	}
	return node->key;
}

RBT :: Tnode* RBT :: _success(int key) {
	Tnode* newNode = _search(key);
	if (newNode == NULL) {
		return NULL;
	}

	if (newNode->right == nil) {
		Tnode* curr = newNode;
		Tnode* old = newNode;
		while (curr->parent != nil) {
			if (curr->parent->left == curr) {
				return curr->parent;
			}
			curr = curr->parent;
		}
		return old;
	}

	Tnode* cursor = newNode->right;
	while (cursor->left != nil) {
		cursor = cursor->left;
	}
	return cursor;
}

void RBT :: insert(int n){
Tnode* z = new Tnode();
z->key = n;

if(root == nil){
  root = z;
  z->parent = nil;
}
else{
  Tnode* x = root;
  Tnode* y = nil;
  while(x != nil){
    y = x;
    if(z->key < x->key){
      x = x->left;
    }
    else{
      x = x->right;
    }
  }
if(z->key < y->key){
  y->left = z;
}
else{
  y->right = z;
}
z->parent = y;

}
  z->left = nil;
  z->right = nil;
  z->color = RED;
  insertFixUp(z);
  size++;
}

//fixup for insert
void RBT :: insertFixUp(Tnode* z){
while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			Tnode* y =  z->parent->parent->right;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
      else {
				if (z == z->parent->right) {
					z = z->parent;
					leftRotate(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				rightRotate(z->parent->parent);
			}
		}
    else {
			Tnode* y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			}
      else {
				if (z == z->parent->left) {
          z = z->parent;
				  rightRotate(z);
				}

				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				leftRotate(z->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

//deletes node
void RBT :: deleteNode(int n){
  Tnode* z = _search(n);

  if (z == NULL){
    cerr << "No node found!" << endl;
    return;
  }
  Tnode* y = z;
  Tnode* x;
  color_t y_orig_color = y->color;
  if(z->left == nil){
    x = z->right;
    transplant(z, z->right);
  }
  else if(z->right == nil){
    x = z->left;
    transplant(z, z->left);
  }
  else{
    Tnode* curr = z->right;
    while(curr->left != nil){
      curr = curr->left;
    }
    y = curr;
    y_orig_color = y->color;
    x = y->right;
    if(y->parent ==z){
      x->parent = y;
    }
    else{
      transplant(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    transplant(z, y);
    y->left = z ->left;
    y->left->parent = y;
    y->color = z->color;
  }
delete z;
  if(y_orig_color == BLACK){
    deleteFixUp(x);
  }
  size--;
}

//fixup for delete
void RBT :: deleteFixUp(Tnode* x){
  while((x != root) && (x->color == BLACK)){
    if(x == x->parent->left){
      Tnode* w = x->parent->right;
      if(w->color){
        w->color = BLACK;
        x->parent->color = RED;
        leftRotate(x->parent);
        w = x->parent->right;
      }
      if ((w->left->color == BLACK) && (w->right->color == BLACK)) {
				w->color = RED;
				x = x->parent;
			}
      else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(x->parent);
				x = root;
			}
		}
    else {
			Tnode* w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				rightRotate(x->parent);
				w = x->parent->left;
			}
			if ((w->right->color == BLACK) && (w->left->color == BLACK)) {
				w->color = RED;
				x = x->parent;
			}
      else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

void RBT :: transplant(Tnode* old, Tnode* newNode) {
	if (old->parent == nil) {
		root = newNode;
	}
  else if (old->parent->right == old) {
		old->parent->right = newNode;
	}
  else {
		old->parent->left = newNode;
	}
	newNode->parent = old->parent;
}

void RBT :: leftRotate(Tnode* x) {
	Tnode* y = x->right;

	x->right = y->left;
	if (y->left != nil) {
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil) {
		root = y;
	}
  else if (x == x->parent->left) {
		x->parent->left = y;
	}
  else {
		x->parent->right = y;
	}
		y->left = x;
		x->parent = y;
}

void RBT :: rightRotate(Tnode* x) {
	Tnode* y = x->left;

	x->left = y->right;
	if (y->right != nil) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == nil) {
		root = y;
	}
  else if (x == x->parent->right) {
		x->parent->right = y;
	}
  else {
		x->parent->left = y;
	}
		y->right = x;
		x->parent = y;
}

void RBT :: _printInOrder(Tnode* head) {
	if (head != nil) {
		_printInOrder(head->left);
    if (head->color == BLACK){
    cout << head->key << " [" << head->color << "]"  << ", ";
  }
  else{
    cout << head->key << " [" << red << head->color << reset << "]"  << ", ";
  }
		_printInOrder(head->right);
	}
}

void RBT :: _printPreOrder(Tnode* head) {
	if (head != nil) {
    if (head->color == BLACK){
    cout << head->key << " [" << head->color << "]"  << ", ";
  }
  else{
    cout << head->key << " [" << red << head->color << reset << "]"  << ", ";
  }
		_printPreOrder(head->left);
		_printPreOrder(head->right);
	}
}

void RBT :: _printPostOrder(Tnode* head) {
	if (head != nil) {
		_printPreOrder(head->left);
    _printPreOrder(head->right);
    if (head->color == BLACK){
    cout << head->key << " [" << head->color << "]"  << ", ";
  }
  else{
    cout << head->key << " [" << red << head->color << reset <<"]"  << ", ";
  }
	}
}

RBT :: Tnode* RBT :: _max() {
	Tnode* curr = root;
	if (curr == nil) {
		return nullptr;
	}
  //all the way right
	while (curr->right != nil) {
		curr = curr->right;
	}
	return curr;
}

int RBT :: max() {
	Tnode* max = _max();
	if (max == nullptr) {
		cout << "Tree is empty!" << endl;
		return -1;
	}
	return max->key;
}

int RBT :: min() {
	Tnode* min = _min();
	if (min == nullptr) {
		cout << "Tree is empty!" << endl;
		return -1;
	}
	return min->key;
}

RBT :: Tnode* RBT :: _min() {
	Tnode* curr = root;
	if (curr == nil) {
		return NULL;
	}
	while (curr->left != nil) {
		curr = curr->left;
	}
	return curr;
}

void RBT :: printInOrder() {
	_printInOrder(root);
	cout << endl;
}

void RBT :: printPreOrder() {
	_printPreOrder(root);
	cout << endl;
}

void RBT :: printPostOrder() {
	_printPostOrder(root);
	cout << endl;
}
