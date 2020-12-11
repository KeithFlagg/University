// instantiation.cpp
//links templated .cpp files
#include "Students.cpp"
#include "Lab5.cpp"
#include "Stack.cpp"

template class Stack<Students*>;
template class StackNode<Students*>;

template class Stack<int>;
template class StackNode<int>;
