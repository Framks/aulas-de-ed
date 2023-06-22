#ifndef TREE_H
#define TREE_H
#include "Node.h"
#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class Tree{
    private:
        Node<T> *m_root;    // ponteiro para o nó raiz
    public:
        // construtor da arvore
        Tree();
        // Construtor 2: cria uma arvore a partir de uma outras duas arvores
        // e transfere as raizes das subarvores passadas como parâmetro para si
        Tree(const T& val,Tree& a,Tree& b);

        Tree(std::string serial);

        // print
        void print();

        // saber se a arvore esta vazia
        bool Empty();

        // saber se a arvore tem certa chave 
        bool Contains(const T& key);

        // calcular o números de nó na arvore
        int Size();

        // remover todos os nós e deixar a arvore vazia 
        Node<T>* Clear(Node<T> *node);

        // destrutor da arvore
        ~Tree();

        // monta uma string da arvore em preordem
        std::string serialize();

        Node<T>* deserializar(std::stringstream &ss);
};

template <typename T>
Tree<T>::Tree(std::string serial){
    std::stringstream ss{serial};
    this->m_root = deserializar(ss);
}

template <typename T>
int Tree<T>::Size(){
    return size(m_root);
}

template <typename T>
int size(Node<T> *node){
    if(node == nullptr)
        return 0;
    return 1 + size(node->left) + size(node->right);
}

template <typename T>
bool Tree<T>::Contains(const T& key){
    return contains(m_root,key);
}
template <typename T>
bool contains(Node<T> *node, const T& key){
    if(node == nullptr)
        return false;
    return key == node->data || contains(node->left,key) || contains(node->right,key);
}

template <typename T>
Tree<T>::Tree(){
    m_root = nullptr;
}

template <typename T>
Tree<T>::Tree(const T& val, Tree& tleft, Tree& tright){
    m_root = new Node<T>(val,tleft.m_root,tright.m_root);
    tleft.m_root = nullptr;
    tright.m_root = nullptr;
}

template <typename T>
Tree<T>::~Tree(){
    m_root = Clear(m_root);
}

template<typename T>
bool Tree<T>::Empty(){
    return m_root == nullptr;
}

template<typename T>
Node<T>* Tree<T>::Clear(Node<T> *node){
    if (node != nullptr)
    {
        node->left = Clear(node->left);
        node->right = Clear(node->right);
        delete node;
    }
    return nullptr;
}

template <typename T>
void Tree<T>::print(){
    printf(m_root);
}

template <typename T>
std::string Tree<T>::serialize(){
    std::string s = "";
    serial(m_root,s);
    return s;
}

template <typename T>
void serial(Node<T> *node, std::string &ss){
    if(node == nullptr){
        ss += "# ";
    }else{
        ss = ss + std::to_string(node->data) + " ";
        serial(node->left,ss);
        serial(node->right,ss);
    }
}

template <typename T>
Node<T>* Tree<T>::deserializar(std::stringstream &ss){
    std::string token;
    ss >> token;
    if(token == "#")
    {
        return nullptr;
    }else{
        Node<T> *aux = new Node<T>(std::stoi(token),nullptr,nullptr);
        aux->left = deserializar(ss);
        aux->right = deserializar(ss);
        return aux;
    }
}

template <typename T>
void printf(Node<T>* raiz){
    // tecnica de preorder imprime o nó antes de entrar no nó a esquerda e depois o nó a direita
    if (raiz != nullptr)
    {
        std::cout << raiz->data << std::endl;
        printf(raiz->left);
        printf(raiz->right);
    }
    /**  posorder imprime o nó só depois de ter visitado o nó a esquerda e depois o nó a direita
     * if(raiz != nullptr)
     * {
     *    printf(raiz->left);
     *    printf(raiz->right);
     *    std::cout << raiz->data << std::endl;
     * }
     * 
     * e tem a ordem simétrica que entra primeiro no nó da esquerda depois imprime o nó e entra no da direita
     * if(raiz != nullptr)
     * {
     *    printf(raiz->left);
     *    std::cout << raiz->data << std::endl;
     *    printf(raiz->right);
     * }
    */
}

#endif