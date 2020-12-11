//instantiation.cpp
//links templated .cpp files

#include "students.cpp"
#include "Lab6.cpp"
#include "Queue.cpp"

template class Queue<int>;
template class QueNode<int>;

template class Queue<Students*>;
template class QueNode<Students*>;
