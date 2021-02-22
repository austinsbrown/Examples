#include <iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H

const int MAX = 1000;

class Stack
{
    private:
        int top;                                    // size of the stack
        int data[MAX];                              // linked list for the stack

    public:
        Stack();                                    // default construcor
        bool IsEmpty() const;                       // checks to see if empty
        bool IsFull() const;                        // checks to see if full
        void Pop();                                 // takes an item off of the stack
        void Push(int item);                        // adds item to top of the stack
        int Top() const;                            // returns the top item
        void MakeEmpty();                           // deletes everything in the stack
};

#endif
