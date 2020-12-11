#ifndef BST_H
#define BST_H

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* parent;
};

class BST{
private:

  Node* root;

  void transplant(Node*, Node*);

public:
  BST();
  ~BST();

  Node* getRoot();
  int max(Node*);
  int min(Node*);
  int success(Node*);
  void insert(int);
  void printNode(Node*);
  void destroyTree(Node*);
  void deleteNode(int);
  void inOrder(Node*);
  void preOrder(Node*);
  void postOrder(Node*);
  Node* searchNode(int);
};
#endif
