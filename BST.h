#ifndef BST_H
#define BST_H
#include "TNode.h"

class BST{
private:
  TNode* root;
  int max(TNode*);
  int min(TNode*);
  int success(TNode*&,TNode*&);
  void makeDeletion(TNode*&);
  void destroyTree(TNode *);
  void insert(TNode*&,TNode*&);
public:
  BST();
  ~BST();

  void delet(int, TNode*&);
  void inOrder(TNode*);
  void preOrder(TNode*);
  void postOrder(TNode*);
  bool searchNode(int);
  TNode* getRoot();
  void remove(int);
  void createNode(int);
};
#endif
