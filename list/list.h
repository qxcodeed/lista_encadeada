#ifndef LIST_H
#define LIST_H


class List
{
    struct Node
    {
        int key;
        Node *next;
        Node(int key): key(key)
        {}
    };

    Node *root;
    Node *_end;
    int _size;

public:

	class it
    {
        Node* posicao;
    public:

        it (Node *posicao = 0){this->posicao = posicao;}

        it & operator= (const it & other)
        {
            posicao = other.posicao;
            return *this;
        }
        int operator* (){return posicao->key;}
        void operator++ (){posicao = posicao->next;}
        bool operator== (const it & other){return this->posicao == other.posicao;}
        bool operator!= (const it & other){return this->posicao != other.posicao;}
    };

    // **** CONSTRUCTORS **** //
    List();

    // ****** CAPACITY ****** //
    bool empty();
    int size();

    // *** ELEMENT ACCESS *** //
    int front();
    it begin(){return it(root);}
	it end(){return it(_end);}

    // ***** MODIFIERS ***** //
    void push_front(int key);
    void pop_front();

    // **** CONSTRUCTORS **** //
    ~List();
};

#endif // LIST_H
