#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node{
    T value;       // valor do tipo generico
    Node *next;    // ponteiro para o proximo nó
    Node(const T& value, Node* ptr){
        this->value = value;
        this->next = ptr;
    }

    ~Node(){
        delete next;
    }
};

#endif