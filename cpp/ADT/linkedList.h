#include <iostream>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
    int data;
    node *next;
};

class linkedList
{
    private:
    node *head;
    node *tail;

    public:
    linkedList();                                   // default constructor
    ~linkedList();                                  // deconstructor
    void append(int item);                          // addes new node
    void display() const;                           // displays all items
    void insertHead(int item);                      // adds item to beggining 
    int get(int pos);                               // get item at input position
};

#endif