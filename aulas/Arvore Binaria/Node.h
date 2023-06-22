#ifndef NODE_H
#define NODE_H

// Nó da arvore binária
template <typename T>
struct Node
{
    T data;
    Node *left;
    Node *right;

    Node(T key, Node *left, Node *right)
    {
        this->data = key;
        this->left = left;
        this->right = right;
    }

    ~Node(){
        delete left;
        delete right;
    }
};

#endif // NODE_H