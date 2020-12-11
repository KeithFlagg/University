//Keith Flagg
#include "Node.h"
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Linkedlist{
private:
Node *head;
Node *createNode();
Node *searchLocation(int);

public:
Linkedlist();
~Linkedlist();
//destructor

void insertNode();
void deleteNode(int);
void printList();
void searchNode();
};
#endif
