#ifndef RBT_H
#define RBT_H

enum color_t{
  RED, BLACK
};

class RBT{
  private:

    struct Tnode{
      int key;
      color_t color;
      Tnode* left;
      Tnode* right;
      Tnode* parent;
    };

    Tnode* root;
    static Tnode* const nil;
    int size = 0;

    //deletes rbt
    void destroyTree(Tnode*);

    //rbt utilities
    void transplant(Tnode*, Tnode*);
    void rightRotate(Tnode*);
    void leftRotate(Tnode*);
    void insertFixUp(Tnode*);
    void deleteFixUp(Tnode*);

    void _printInOrder(Tnode*);
    void _printPreOrder(Tnode*);
    void _printPostOrder(Tnode*);
    //searches for key
    Tnode* _search(int);
    //find successor
    Tnode* _success(int);
    Tnode* _min();
    Tnode* _max();


public:
  RBT();
  ~RBT();

  //inserts to RBT
  void insert(int);
  //deletes node from RBT
  void deleteNode(int);
  //deletes nil nodes
  void deleteNil();
  void printInOrder();
  void printPreOrder();
  void printPostOrder();
  int search(int);
  //finds minimum
  int min();
  //finds maximum
  int max();
  //finds successor
  int success(int);
};
#endif
