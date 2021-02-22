#include "linkedList.h"

linkedList::linkedList()
{
    head = NULL;                                    // front of the list
    tail = NULL;                                    // rear of the list
}

linkedList::~linkedList()
{
    node *temp;

    for (temp = head; head; temp = head)
    {
        head = head->next;
        delete temp;
    }
}

void linkedList::append(int item)
{
    node *temp = new node;                          // allocate memory for new node
    temp->data = item;                              // set data equal to item
    temp->next = NULL;                              // it is on the end so set the next pointer to NULL

    if(head == NULL)                                // cheack to see if list is empty
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }

    else                                            // if there is something in the list
    {
        tail->next = temp;
        tail = temp;
    }

    
}

void linkedList::display() const
{
    node *temp = new node;
    temp = head;
    int num = 0;

    while(temp != NULL)
    {
        cout << num << " : ";
        cout << temp->data << endl;
        temp = temp->next;
        num++;
    }
}

void linkedList::insertHead(int item)
{
    node *temp = new node;
    temp->data = item;
    
    temp->next = head;
    head = temp;
}

int linkedList::get(int pos)
{
    node *temp = new node;
    temp = head;

    for(int i=0; i < pos; i++)
    {
        temp = temp->next;
    }
    
    return temp->data;
}
