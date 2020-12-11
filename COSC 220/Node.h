//Keith Flagg
#ifndef NODE_H
#define NODE_H
class Node{
public:
  char firstName[20];
  char lastName[20];
  int idNumber=0;
  Node *next;

Node();
//node constructor
void printNode();
//prototype
};
#endif
