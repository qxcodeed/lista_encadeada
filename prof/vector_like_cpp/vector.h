#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>

namespace ed
{


class iterator
{
    int* posicao;

public:

    iterator (int *posicao = NULL){this->posicao = posicao;}

    iterator & operator= (const iterator & other)
    {
        posicao = other.posicao;
        return *this;
    }
    int operator* (){return *posicao;}
    void operator++ (){posicao++;}
    void operator-- (){posicao--;}
    bool operator== (const iterator & other){return this->posicao == other.posicao;}
    bool operator!= (const iterator & other){return this->posicao != other.posicao;}
};


class vector
{

    int *data;
    int _size;
    int _capacity;

public:
    // Constructors:

    // Recebe uma "capacidade" e aloca espaco no vetor
    // de dados correspondente a esse valor recebido.
    // os atributos _capacity e _size devem ser inicializados.
    vector (int _capacity) : _capacity(_capacity), _size(0)
    {
        data = new int[_capacity];
    }

    // Inicializa os atributos _capacity e _size com o valor
    // 0 e data com o valor NULL. Nesse caso, mais memoria
    // eh alocada conforme mais elementos vao sendo inseridos.
    vector () : data(NULL), _capacity(0), _size(0)
    {
    }

    // Capacity:

    // Este metodo deve retornar a quantidade atual
    // de elementos no vector.
    int size ()
    {
        return _size;
    }

    // Este metodo deve retornar a quantidade de
    // espaco alocada no vetor de dados.
    int capacity ()
    {
        return _capacity;
    }

    // Retorna true se o vector estah vazio e false
    // caso contrario.
    bool empty ()
    {
        return (_size == 0);
    }

    // Element Access:

    iterator begin ()
    {
        return iterator(&data[0]);
    }

    iterator end ()
    {
        return iterator(&data[_size]);
    }

    // Recebe uma posicao e retorna uma referencia da casa
    // do vetor de dados correspondente a posicao recebida.
    int& at(int position)
    {
        return data[position];
    }

    // Retorna o elemento do inicio do vector caso
    // este nao esteja vazio, se for o caso de estar
    // vazio, o metodo deve retornar -1.
    int& front (){
        static int error;
        if(size() == 0)
            return error;
        return data[0];
    }

    // Retorna o ultimo elemento do vector caso
    // este nao esteja vazio, se for o caso de estar
    // vazio, o metodo deve retornar -1.
    int& back ()
    {
        static int error;
        if(size() == 0)
            return error;
        return (data[size_ - 1]);
    }

    // Modifiers:

    // Insere um novo elemento no fim do vector.
    // Se essa operacao nao for possivel, ou seja
    // se _size == _capacity, a capacidade deve ser
    // dobrada e o elemento inserido com sucesso.
    void push_back (int elem)
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
    // Desloca todos depois de posicao uma posição
    // para trás.
    // Verifique se a posição é valida
    void erase (int posicao)
    {
        if(posicao >= _size || posicao < 0)
            return;

        _size--;
        for (int i = posicao; i < _size; ++i)
        {
            data[i] = data[i+1];
        }
    }

    // esvazia o vector
    void clear ()
    {
        _size = 0;
    }

    // Destructor:

    // Toda memoria alocada no vector de dados deve ser
    // desalocada.
    ~vector ()
    {
        delete [] data;
    }


    /*
    Encontra e retorna da próxima ocorrência de value no vetor.
    A busca é iniciada a partir da posicao de it, sendo it uma posição de
    busca válida.
    Se value não for encontrado no vetor, entao iterator retornado será vector.end()
    Se for encontrado, retorne o iterador para posição onde foi encontrado.
    Teste se a posição que o iterador contem se situa nos limites do vetor
    */

    iterator find(iterator it, int value){

        if(*it < data || *it >= (data + _size))
            return this->end();
            it = iterator(&vector->data[0]);

        int * end = &vector->data[vector->size];
        for(;it != end; it++){
            if(*it == value)
                return it;
        }
        return NULL;

    }

    /*
    Encontra e REMOVE a próxima ocorrência de value no vetor.
    A busca é iniciada a partir da posicao de it, sendo it uma posição de
    busca válida.
    Se it == NULL, a busca deve ser iniciada no primeiro elemento do vetor.
    Se value não for encontrado no vetor, então retorne NULL.
    Se for encontrado, retorne o endereço da posição onde ele foi removido.
    */
    int * vector_remove   (int iterator, int value);


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
    void vector_insert(Vector * vector, int * iterator, int value);



    int * vector_find(Vector * vector, int * iterator, int value);

    void vector_remove_it(Vector * vector, int * it){
        int * end = &vector->data[vector->size];
        for(;it + 1 < end; it++){
            *it = *(it + 1);
        }
        vector->size -= 1;
    }


    int * vector_remove(int it, int value){
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

    int *vector_find(Vector *vector, int *iterator, int value);




};


#endif // VECTOR_H
