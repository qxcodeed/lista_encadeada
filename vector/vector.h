#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>

namespace ed
{

class vector
{

    int *data;
    int _size;
    int _capacity;

public:

    class it
    {

        int* posicao;

    public:

        it (int *posicao = NULL){this->posicao = posicao;}

        it & operator= (const it & other)
        {
            posicao = other.posicao;
            return *this;
        }
        int operator* (){return *posicao;}
        void operator++ (){posicao++;}
        void operator-- (){posicao--;}
        bool operator== (const it & other){return this->posicao == other.posicao;}
        bool operator!= (const it & other){return this->posicao != other.posicao;}
    };

    // Constructors:

    // Recebe uma "capacidade" e aloca espaco no vetor
    // de dados correspondente a esse valor recebido.
    // os atributos _capacity e _size devem ser inicializados.
    vector (int _capacity);

    // Inicializa os atributos _capacity e _size com o valor
    // 0 e data com o valor NULL. Nesse caso, mais memoria
    // eh alocada conforme mais elementos vao sendo inseridos.
    vector ();

    // Capacity:

    // Este metodo deve retornar a quantidade atual
    // de elementos no vector.
    int size ();

    // Este metodo deve retornar a quantidade de
    // espaco alocada no vetor de dados.
    int capacity ();

    // Retorna true se o vector estah vazio e false
    // caso contrario.
    bool empty ();

    // Element Access:

    it begin ()
    {
        return it(&data[0]);
    }

    it end ()
    {
        return it(&data[_size]);
    }

    // Recebe uma posicao e retorna uma referencia da casa
    // do vetor de dados correspondente a posicao recebida.
    int& at (int position);

    // Retorna o elemento do inicio do vector caso
    // este nao esteja vazio, se for o caso de estar
    // vazio, o metodo deve retornar -1.
    int front ();

    // Retorna o ultimo elemento do vector caso
    // este nao esteja vazio, se for o caso de estar
    // vazio, o metodo deve retornar -1.
    int back ();

    // Modifiers:

    // Insere um novo elemento no fim do vector.
    // Se essa operacao nao for possivel, ou seja
    // se _size == _capacity, a capacidade deve ser
    // dobrada e o elemento inserido com sucesso.
    void push_back (int elem);

    // Deve ser removido o ultimo elemneto do vector
    // se ele nao estiver vazio.
    void pop_back ();

    // Remove do vector o elemento correspondente a
    // posicao recebida como argumento.
    void erase (int posicao);

    // esvazia o vector
    void clear ();

    // Destructor:

    // Toda memoria alocada no vector de dados deve ser
    // desalocada.
    ~vector ();

};


#endif // VECTOR_H
