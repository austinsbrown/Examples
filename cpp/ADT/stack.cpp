#include "stack.h"

Stack::Stack()
{
    top = -1;
}

bool Stack::IsEmpty() const
{
    return {top == -1};
}

bool Stack::IsFull() const
{
    return {top == MAX};
}

void Stack::Pop()
{
    top--;
}

void Stack::Push(int item)
{
    top++;
    data[top] = item;
}

int Stack::Top() const
{
    return data[top];
}

void Stack::MakeEmpty()
{
    top = -1;
}