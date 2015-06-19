#include "list.h"

// **** CONSTRUCTORS **** //
List::List()
{
    root = new Node(-1);
    _end = root;
    _size = 0;
}

// ****** CAPACITY ****** //

bool List::empty()
{
    return _size == 0;
}

int List::size()
{
    return _size;
}

// *** ELEMENT ACCESS *** //

int List::front()
{
    if(!empty())
        return root->key;
    return 0;
}

// ***** MODIFIERS ***** //

void List::push_front(int key)
{
    Node *temp = new Node(key);
    temp->next = root;
    root = temp;
    this->_size++;
}

void List::pop_front()
{
    if(!empty())
    {
        Node *temp = root;
        root = root->next;
        delete temp;
        this->_size--;
    }
}

List::~List()
{
    while(!empty())
        pop_front();
    delete _end;
}
