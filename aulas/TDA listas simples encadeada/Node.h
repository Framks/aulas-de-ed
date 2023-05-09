#ifndef NODE_H
#define NODE_H

struct Node
{
    int value;
    Node *next;

    Node(const int& val, Node *nextptr){
        value = val;
        next = nextptr;
    }
};

#endif