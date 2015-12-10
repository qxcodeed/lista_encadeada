#ifndef DLIST_H
#define DLIST_H

#include <iostream>

struct dnode{
    int value;
    dnode * next{nullptr};
    dnode * prev{nullptr};

    dnode(int value = 0){
        this->value = value;
    }
};

//Essa é uma lista dupla com cabeça e calda.
//A cabeça é um nó fixo de marcação que nunca é alterado.
//A calda fica no final da lista.
//O primeiro elemento válido da lista é head->next
//O ultimo elemento válido da lista é tail->prev
class dlist{
protected:
    dnode * head;//no antes do inicio da lista
    dnode * tail;

public:
    //inicia a lista
    dlist(){
        head = new dnode(0);
        tail = new dnode(0);
        head->next = tail;
        tail->prev = head;
    }

    //remove os elementos e depois remove a cabeça
    ~dlist(){
        clear();
        delete(head);
        delete(tail);
    }

    //imprime os elementos
    void print();

    //retorna o tamanho da lista
    int size();

    //retorna o primeiro valido ou nullptr se vazio
    dnode * front();

    //retorna o ultimo valido ou nullptr se vazio
    dnode * back();

    dnode * end(){
        return tail;
    }

    dnode * rend(){
        return head;
    }

    void push_front(int value);

    void push_back(int value);

    //insere todos os elementos do vetor na fila
    void push_back_all(int vet[], int tam);

    void pop_front();

    void pop_back();

    //verifica e retorna se dois vetores sao iguais
    bool equals(dlist * other);

    //retorna o enesimo no ou nullptr se fora dos limites
    dnode * get(int indice);

    //retorna a primeira ocorrencia do valor
    dnode * find(int value);

    //retorna o no anterior ao removido ou nullptr se nao encontrou
    dnode * remove(int value);

    //remove todos os nós com esse valor
    void remove_all(int value);

    //remove o no indice ind, onde 0 é o primeiro valido.
    //retorna o nó antes do no removido ou nullptr
    dnode * remove_pos(int ind);

    //remove os elementos das seguintes posicoes
    void remove_all_pos(int posicoes[], int qtd);

    //remove todos os elementos menos a cabeça
    void clear();

};

#endif // DLIST_H
