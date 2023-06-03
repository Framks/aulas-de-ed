#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node
{
    T value;
    Node *next;
    Node(const T value, Node *next){
        this->value = value;
        this->next = next;
    }

    ~Node(){
        delete next;
    }
};


#endif