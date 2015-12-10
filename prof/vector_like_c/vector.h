#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>

namespace ed
{

class vector
{

    int *_data;
    int _size;
    int _capacity;

public:
    // Constructors:

    vector (int _capacity) : _capacity(_capacity), _size(0)
    {
        _data = new int[_capacity];
    }

    //Contrutor padrão
    vector () : _data(NULL), _capacity(0), _size(0)
    {}

    ~vector ()
    {
        delete [] _data;
    }

    int size ()
    {
        return _size;
    }

    int capacity ()
    {
        return _capacity;
    }

    void reserve(int capacity){
        int * new_data = new int[capacity];

        _capacity = capacity;

        //se nova capacidade for menor
        if(capacity < _size)
            _size = capacity;

        for(int i = 0; i < _size; i++){
            new_data[i] = _data[i];
        }
        free(_data);
        _data = new_data;

    }

    bool empty ()
    {
        return _size == 0;
    }

    int* front ()
    {
        return _data;
    }

    int* back ()
    {
        return &_data[_size - 1];
    }

    int* end ()
    {
        return &_data[_size];
    }

    int* at(int position)
    {
        return &_data[position];
    }

    // Modifiers:


    void push_back (int elem)
    {

        if (_size == _capacity)
            reserve(2 * _capacity);
        _data[_size++] = elem;
    }

    // Deve ser removido o ultimo elemneto do vector
    // se ele nao estiver vazio.
    void pop_back ()
    {
        if (!empty())
        {
            _size--;
        }
    }

    // Remove do vector o elemento correspondente a
    // posicao recebida como argumento.
    void erase (int posicao)
    {
        _size--;
        for (int i = posicao; i < _size; ++i)
        {
            _data[i] = _data[i+1];
        }
    }

    // esvazia o vector
    void clear ()
    {
        _size = 0;
    }




    /*
    Encontra e retorna da próxima ocorrência de value no vetor.
    A busca é iniciada a partir da posicao de it, sendo it uma posição de
    busca válida.
    Se it == NULL, a busca deve ser iniciada no primeiro elemento do vetor.
    Se value não for encontrado no vetor, então retorne NULL.
    Se for encontrado, retorne o endereço da posição onde ele foi encontrado.
    */
    int * vector_find(Vector * vector, int * it, int value);

    /*
    Encontra e REMOVE a próxima ocorrência de value no vetor.
    A busca é iniciada a partir da posicao de it, sendo it uma posição de
    busca válida.
    Se it == NULL, a busca deve ser iniciada no primeiro elemento do vetor.
    Se value não for encontrado no vetor, então retorne NULL.
    Se for encontrado, retorne o endereço da posição onde ele foi removido.
    */
    int * vector_remove   (Vector * vector, int * it, int value);


    /*
    Remove todos os elementos de valor value no vetor mantendo a ordem dos
    elementos.
    */
    void vector_remove_all(Vector * vector, int value);

    //if it == NULL entao começa do primeiro elemento do vetor
    //insere chave na posicao atual deslocando tudo pra frente

    /*
    A chave value deve ser inserida na posição it deslocando o elemento que
    estava em it e todos os elementos adiante uma posição pra frente.
    Se it == NULL, a inserção deve ser realizada na primeira posição.
    */
    void vector_insert(Vector * vector, int * it, int value);



    int * vector_find(Vector * vector, int * it, int value){
        if(it == NULL)
            it = &vector->data[0];

        int * end = &vector->data[vector->size];
        for(;it != end; it++){
            if(*it == value)
                return it;
        }
        return NULL;
    }

    void vector_remove_it(Vector * vector, int * it){
        int * end = &vector->data[vector->size];
        for(;it + 1 < end; it++){
            *it = *(it + 1);
        }
        vector->size -= 1;
    }


    int * vector_remove(Vector * vector, int * it, int value){
        if(it == NULL)
            it = &vector->data[0];
        int * end = &vector->data[vector->size];

        for(;it < end; it++){
            if(*it == value){
                vector_remove_it(vector, it);
                return it;
            }
        }
        return NULL;
    }

    void vector_remove_all(Vector * vector, int value){
        int * rend = &vector->data[vector->size] - 1;
        int * rbegin = &vector->data[0] - 1;
        int * it;
        for(it = rend; it > rbegin; it--){
            if(*it == value){
                vector_remove_it(vector, it);
            }
        }
    }

    void vector_insert(Vector * vector, int * it, int value){
        int * end = &vector->data[vector->size];
        vector_push_back(vector, value);

        if(it == NULL)
            it = &vector->data[0];
        int *aux = it;
        for(;it + 1 < end; it++){
            *(it + 1) = *it;
        }
        *aux = value;
    }


};


#endif // VECTOR_H
