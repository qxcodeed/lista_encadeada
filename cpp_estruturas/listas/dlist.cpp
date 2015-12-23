#include "dlist.h"

#include <iostream>
using namespace std;

void dlist::_print(dnode *node){
    if(node == tail)
        return;
    cout << node->value << " ";
    _print(node->next);
}

void dlist::print(){
    std::cout << "[ ";
    _print(this->head->next);
    std::cout << "]" << std::endl;
}

int dlist::_size(dnode *n){
    if(n == tail)
        return 0;
    return 1 + _size(n->next);
}

int dlist::size(){
    return _size(head->next);
}

dnode *dlist::front(){
    if(head->next == tail)
        return nullptr;
    return head->next;
}

dnode *dlist::back(){
    if(this->tail->prev == head)
        return nullptr;
    return tail->prev;
}

void dlist::push_front(int value){
    auto n = new dnode(value, head, head->next);
    head->next = n;
    n->next->prev = n;
}

void dlist::push_back(int value){
    auto n = new dnode(value, tail->prev, tail);
    tail->prev = n;
    n->prev->next = n;
}

void dlist::push_back_all(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        this->push_back(vet[i]);
    }
}

void dlist::pop_front(){
    if(head->next == tail)
        return;
    auto x = head->next;
    head->next = x->next;
    x->next->prev = x->prev;
    delete(x);
}

void dlist::pop_back(){
    if(head->next == tail)
        return;
    auto x = tail->prev;
    tail->prev = x->prev;
    x->prev->next = x->next;
    delete(x);
}

bool dlist::_equals(dnode *one, dnode *two){
    if(one == nullptr and two != nullptr)
        return false;
    if(one != nullptr and two == nullptr)
        return false;
    if(one == nullptr and two == nullptr)
        return true;
    if(one->value != two->value)
        return false;
    return _equals(one->next, two->next);
}




bool dlist::equals(dlist *other){
    return _equals(head->next, other->head->next);
}

dnode *dlist::_get(dnode *n, int indice){
    if(n == tail)
        return tail;
    if(indice == 0)
        return n;
    return _get(n->next, indice - 1);
}

dnode *dlist::get(int indice){
    return _get(head->next, indice);
}

dnode *dlist::_find(dnode *n, int value){
    if(n == tail)
        return tail;
    if(n->value == value)
        return n;
    return _find(n->next, value);
}

dnode *dlist::find(int value){
    return _find(head->next, value);
}

dnode *dlist::_remove(dnode *n, int value){
    if(n == tail)
        return tail;
    if(n->value == value){
        n->next->prev = n->prev;
        n->prev->next = n->next;
        auto x = n->next;
        delete(n);
        return x;
    }
    return _remove(n->next, value);
}

dnode *dlist::remove(int value){
    return _remove(head->next, value);
}

void dlist::remove_all(int value){
    auto x = head->next;
    while(x != tail)
        x = _remove(x, value);
}

dnode *dlist::remove_pos(int ind){
    auto n = get(ind);
    if(n != tail){
        n->next->prev = n->prev;
        n->prev->next = n->next;
        auto x = n->next;
        delete(n);
        return x;
    }
    return n;
}

void dlist::remove_all_pos(int posicoes[], int qtd){
    for(int i = 0; i < qtd; i++){
        remove_pos(posicoes[i] - i);
    }
}

void dlist::_clear(dnode *n){
    if(n == tail)
        return;
    auto x = n->next;
    delete(n);
    _clear(x);
}

void dlist::clear(){
    _clear(head->next);
    head->next = tail;
    tail->prev = head;
}
