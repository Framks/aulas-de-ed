#ifndef NODE_H
#define NODE_H
#include <iostream>
struct Node 
{
    int value;
    Node* next;

    Node(const int& val, Node *nextPtr) 
    {
        value = val;
        next = nextPtr;
    }

    ~Node(){
        std::cout << "removido: " << value <<std::endl;
    }
};

#endif