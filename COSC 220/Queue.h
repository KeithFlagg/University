#ifndef QUEUE_H
#define QUEUE_H

template <class DataType>
struct QueNode
{
DataType data;
QueNode<DataType> *next;
};

template <class DataType>
class Queue
{
private:
    QueNode<DataType> *front;
    QueNode<DataType> *back;
    int queueSize;//size of queue
    int QueueCnt;//element count
public:
    Queue (int=10); //class constructor
    ~Queue(); //destructor
    void enQueue(const DataType);
    void deQueue();
    DataType topQueue() const; //returns value of first queue item
    bool isEmpty() const; //return true if empty
    bool isFull() const; //return true if full
};
#endif
