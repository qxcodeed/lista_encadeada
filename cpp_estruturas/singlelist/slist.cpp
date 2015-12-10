#include "slist.h"

//#############################################33
//Funcoes auxiliares
void _insert_after(snode * node, int value);

void _remove_after(snode * node);

//retorna o no antes do elemento procurado
//nao testa o node before
//se nao achar retorna nullptr
snode * _find_before(snode * before, int value);

//remove e retorna um antes do removido ou nullptr
//se nao conseguiu remover
snode * _remove(snode * before, int value);


void _insert_after(snode *node, int value){
    snode * new_node = new snode(value);
    new_node->next = node->next;
    node->next = new_node;
}

void _remove_after(snode *node){
    snode * dead = node->next;
    node->next = node->next->next;
    delete(dead);
}

snode *_find_before(snode *before, int value){
    for(snode * n = before; n->next != nullptr; n = n->next)
        if(n->next->value == value)
            return n;
    return nullptr;
}

snode *_remove(snode *before, int value){
    snode * n = _find_before(before, value);
    if(n != nullptr){
        _remove_after(n);
        return n;
    }
    return nullptr;
}

//###############################################
//METODOS DA CLASSE

void slist::print(){
    std::cout << "[ ";
    for(snode * n = head->next; n != nullptr; n = n->next){
        std::cout << n->value << " ";
    }
    std::cout << "]" << std::endl;
}

int slist::size(){
    int qtd = 0;
    for(snode * n = head; n->next != nullptr; n = n->next)
        qtd++;
    return qtd;
}

snode *slist::front(){
    return this->head->next;
}

snode *slist::back(){
    snode * n;
    for(n = head; n->next != nullptr; n = n->next);
    if(n != head)
        return n;
    return nullptr;
}



void slist::push_front(int value){
    _insert_after(head, value);
}

void slist::push_back(int value){
    snode * n;
    for(n = head; n->next != nullptr; n = n->next);
    _insert_after(n, value);
}

void slist::push_back_all(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        this->push_back(vet[i]);
    }
}

void slist::pop_front(){
    _remove_after(head);
}

void slist::pop_back(){
    if(head->next == nullptr)//empty
        return;
    snode * n;
    for(n = head; n->next->next != nullptr; n = n->next);
    delete(n->next);
    n->next = nullptr;
}

snode *slist::get(int indice){
    snode * n = head;
    for(int i = 0; i <= indice; i++){
        if(n->next == nullptr)
            return nullptr;
        else if(i == indice)
            return n->next;
        else
            n = n->next;
    }
    return n;
}

snode *slist::find(int value){
    snode * n = _find_before(head, value);
    if(n != nullptr)
        return n->next;
    return nullptr;
}

snode *slist::remove(int value){
    return _remove(head, value);
}

void slist::remove_all(int value){
    snode * before = head;
    while(before != nullptr)
        before = _remove(before, value);
}

snode *slist::remove_pos(int ind){
    snode * n = get(ind - 1);
    if(n->next != nullptr){
        _remove_after(n);
        return n;
    }
    return nullptr;
}



void slist::remove_all_pos(int posicoes[], int qtd){
    for(int i = 0; i < qtd; i++){
        remove_pos(posicoes[i] - i);
    }
}

void slist::clear(){
    for(snode * n = head->next; n != nullptr;){
        snode * back = n->next;
        delete(n);
        n = back;
    }
    head->next = nullptr;
}


bool slist::equals(slist *other){
    snode * one = this->head;
    snode * two = other->head;

    while(true){
        if((one->next == nullptr) and (two->next != nullptr))
            return false;
        if((two->next == nullptr) and (one->next != nullptr))
            return false;
        if((two->next == nullptr) and (one->next == nullptr))
            break;
        if(two->value != one->value)
            return false;
        one = one->next;
        two = two->next;
    }
    //so chega aqui se forem iguais
    return true;
}

//########################################
