#include <iostream>
using namespace std;
  
#ifndef MINISTACK_H
#define MINISTACK_H

class queue
{
    private:
    int *items;                     // pointer to items in queue
    int max;                        // number of elements + 1
    int front;                      // index at front of queue
    int rear;                       // index at back of queue
    int count;                      // number of items in the array

    public:
    queue();                        // default counstructor
    queue(int max);                 // par. constructor
    ~queue();                       // deconstructor

    void makeEmpty();               // resets the queue
    bool isEmpty() const;           // checks to see if queue is empty
    bool isFull() const;            // checks to see if queue is full
    int size() const;               // returns the size of queue
    int peek() const;               // returns value at begining of queue
    
    void enqueue(int item);         // adds item to back of queue
    void dequeue();                 // removes item from front of queue
};

#endif