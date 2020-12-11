#ifndef STACK_H
#define STACK_H

template <class DataType>
struct StackNode {
    DataType data;   //allows any data type
    StackNode<DataType> *next;  //pointer to the next Node
};

template <class DataType>
class  Stack {
private:
      StackNode<DataType> *top;
      int maxSize; //maximum stack size
      int numNode; //number of nodes in stack
public:
      Stack (int=10); //constructor makes a stack with size x, default 10.
      ~Stack();       //destructor
      bool isEmpty() const;   //check if stack is empty.
      bool isFull() const;    //check if stack is full.
      void push(const DataType); //push a node onto top of stack.
      void pop();         // pop a node from the top of the stack.
      DataType topStack() const;  //return the top of the stack.
};

#endif
