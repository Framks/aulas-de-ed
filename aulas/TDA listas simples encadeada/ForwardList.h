#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include "Node.h"
#include <iostream>

class ForwardList
{
private:
    Node* m_head;
    int m_size;

public:
    // construtor default
    ForwardList();

    // destrutor da classe
    ~ForwardList();

    // deixar a lista vazia
    // libera os nós e colcoa o m_size igual a zero
    void clear();

    // insere um valor no inicio da lista
    void push_front(const int& val);

    // inserir valor no final da lista
    void push_back(const int& val);

    // imprimi os valores das chaves na tela
    void print();

    // insere um elemento no indice expecificado
    // se o indice não existir, não insere
    // se existir, insere.
    void insert_at(int index, const int& val);
};

ForwardList::ForwardList()
{
    m_head = new Node(0,nullptr);
    m_size = 0;
}

void ForwardList::push_front(const int& val){
    Node *ptr = new Node(val, nullptr);
    ptr->next = m_head->next;
    m_head->next = ptr;
    m_size++;
}

ForwardList::~ForwardList()
{
    clear();
    delete m_head;
}

void ForwardList::clear(){
    while (m_head->next != nullptr)
    {
        Node* aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

void ForwardList::print(){
    Node *viajante = m_head->next;
    while (viajante != nullptr)
    {
        std::cout << viajante->value << " ";
        viajante = viajante->next;
    }
    std::cout << std::endl;
}

void ForwardList::push_back(const int& val){
    Node *viajante = m_head;
    while (viajante->next != nullptr)
    {
        viajante = viajante->next;
    }
    Node *aux = new Node(val, nullptr);
    viajante->next = aux;
    m_size++;
}

void ForwardList::insert_at(int index, const int& val){
    if (index >=0 && index <= m_size)
    {
        int contador = 0;
        Node *viajante = m_head;
        while (contador < index)
        {
            viajante = viajante->next;
        }
        Node *novo = new Node(val, nullptr);
        novo->next = viajante->next;
        viajante->next = novo;
        m_size++;
    }
}

#endif