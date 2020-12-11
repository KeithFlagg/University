#ifndef TNODE_H
#define TNODE_H

class TNode{
private:
  TNode *parent;
  TNode *left;
  TNode *right;
  int data;

public:
  TNode();
  void printNode();
  friend class BST;
};
#endif
