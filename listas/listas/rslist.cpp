#include "rslist.h"

snode *rslist::_clone(snode *other){
    if(other == nullptr){
        return nullptr;
    }
    snode * node = new snode(other->value);
    node->next = _clone(other->next);
    return node;
}

rslist::rslist(const rslist &other){
    head = _clone(other.head);
}

void rslist::_print(snode *node){
    if(node == nullptr)
        return;
    cout << node->value << " ";
    _print(node->next);
}

void rslist::print(){
    std::cout << "[ ";
    _print(this->head->next);
    std::cout << "]" << std::endl;
}

int rslist::_size(snode *n){
    if(n == nullptr)
        return 0;
    return 1 + _size(n->next);
}

int rslist::size(){
    return _size(head->next);
}

snode *rslist::front(){
    return this->head->next;
}

snode *rslist::_back(snode *n){
    if(n->next == nullptr)
        return n;
    return _back(n->next);
}

snode *rslist::back(){
    snode * n = _back(head);
    if(n != head)
        return n;
    return nullptr;
}

void rslist::push_front(int value){
    auto n = new snode(value);
    n->next = head->next;
    head->next = n;
}

snode *rslist::_push_back(snode *n, int value){
    if(n == nullptr)
        return new snode(value);
    n->next = _push_back(n->next, value);
    return n;
}

void rslist::push_back(int value){
    _push_back(head, value);
}

void rslist::push_back_all(int vet[], int tam){
    for(int i = 0; i < tam; i++){
        this->push_back(vet[i]);
    }
}

void rslist::pop_front(){
    auto x = head->next;
    if(x != nullptr){
        head->next = x->next;
        delete(x);
    }
}

void rslist::_pop_back(snode *n){
    if(n->next->next == nullptr){
        delete(n->next);
        n->next = nullptr;
        return;
    }
    _pop_back(n->next);
}

void rslist::pop_back(){
    _pop_back(head);
}

bool rslist::_equals(snode *one, snode *two){
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

bool rslist::equals(rslist *other){
    return _equals(head->next, other->head->next);
}

snode *rslist::_get(snode *n, int indice){
    if(n == nullptr)
        return nullptr;
    if(indice == 0)
        return n;
    return _get(n->next, indice - 1);
}

snode *rslist::get(int indice){
    return _get(head->next, indice);
}

snode *rslist::_find(snode *n, int value){
    if(n == nullptr)
        return nullptr;
    if(n->value == value)
        return n;
    return _find(n->next, value);
}

snode *rslist::find(int value){
    return _find(head, value);
}

snode *rslist::_remove(snode *n, int value){
    if(n->next == nullptr)
        return nullptr;
    if(n->next->value == value){
        auto x = n->next;
        n->next = x->next;
        delete(x);
        return n;
    }
    return _remove(n->next, value);
}

snode *rslist::remove(int value){
    return _remove(head, value);
}

void rslist::remove_all(int value){
    auto x = head;
    while(x != nullptr)
        x = _remove(x, value);
}

snode *rslist::remove_pos(int ind){
    auto antes = _get(head->next, ind - 1);
    if(antes != nullptr){
        auto x = antes->next;
        if(x != nullptr){
            antes->next = x->next;
            delete(x);
        }
    }
    return antes;
}

void rslist::remove_all_pos(int posicoes[], int qtd){
    for(int i = 0; i < qtd; i++){
        remove_pos(posicoes[i] - i);
    }
}

void rslist::_clear(snode *n){
    if(n == nullptr)
        return;
    auto x = n->next;
    delete(n);
    _clear(x);
}

void rslist::clear(){
    _clear(head->next);
    head->next = nullptr;
}

snode *rslist::end(){
    return nullptr;
}


