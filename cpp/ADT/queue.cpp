#include "queue.h"

queue::queue()
{
    max = 50;
    front = 0;              
    rear = -1;
    count = 0;
    items = new int[max];           
};


queue::queue(int max)
{
    items = new int[max];
    front = 0;
    rear = -1;
    count = 0;
}


void queue::makeEmpty()
{
    front = 0;
    rear = -1;
}


bool queue::isEmpty() const
{
    return {front == rear};
}


bool queue::isFull() const
{
    if((rear+1) % max == front)
    {
        return true;
    }
}


int queue::size() const
{
    return count;
}

int queue::peek() const
{
    return items[front];
}


void queue::enqueue(int item)
{
    rear = (rear+1) % max;
    items[rear] = item;
    count++;
}


void queue::dequeue()
{
    front = (front+1) % max;
    count--;
}


queue::~queue()
{
    delete [] items;
}

