#include "vector.h"


ed::vector::vector(int _capacity) : _capacity(_capacity), _size(0)
{
    data = new int[_capacity];
}

ed::vector::vector() : data(NULL), _capacity(0), _size(0)
{
}


int ed::vector::size()
{
    return _size;
}

int ed::vector::capacity()
{
    return _capacity;
}

bool ed::vector::empty()
{
    return (_size == 0 ? true : false);
}

int &ed::vector::at(int position)
{
    return data[position];
}

int ed::vector::front()
{
    return (!empty() ? data[0] : -1);
}

int ed::vector::back()
{
    return (!empty() ? data[0] : -1);
}

void ed::vector::push_back(int elem)
{
    if (_size < _capacity)
    {
        data[_size++] = elem;
    }
    else
    {
        if (_capacity == 0)
        {
            data = new int;
            _capacity++;
        }
        else
        {
            int *temp = data;
            data = new int[2*_capacity];
            _capacity = 2*_capacity;
            for (int i = 0; i < _size; ++i)
                data[i] = temp[i];
            delete [] temp;
        }

        data[_size++] = elem;
    }
}

void ed::vector::pop_back()
{
    if (!empty())
    {
        _size--;
    }
}

void ed::vector::erase(int posicao)
{
    _size--;
    for (int i = posicao; i < _size; ++i)
    {
        data[i] = data[i+1];
    }
}

void ed::vector::clear()
{
    _size = 0;
}

ed::vector::~vector()
{
    delete [] data;
}


