#ifndef Queue_H
#define Queue_H
#include "Node.h"
#include <iostream>
#include <stdexcept>

template<typename T>
class Queue{
private:
    int size;
    Node<T> *first;
    Node<T> *last;

public:
    // construtor e destrutor
    Queue();
    Queue(const Queue& q);
    ~Queue();

    // função que retorna o tamanho da fila
    int size();

    // insere elementos na fila
    void push(const T& v);

    // retira elementos da fila
    void pop();

    // acessar o primeiro elemento da fila
    // se a fila estiver vazia lança uma out_of_range exception
    T& front();

    // Acessa o ultimo elemento da fila.
    // se a fila estiver vazia, lanca uma out_of_range exception
    T& back();

    // saber se uma fila esta fazia
    bool empty();

    // sobrecarga do operador de atribuicao
    Queue& operator=(const Queue& q);

    // saber se duas filas são iguais
    bool operator==(const Queue& q) const;
};

template <typename T>
Queue<T>::Queue()
{
    this->size = 0;
    this->first = this->back = nullptr;
}

template <typename T>
void Queue<T>::push(const T& v){
    Node<T> *aux= new Node<T>(v,nullptr);
    if (this->size == 0)
    {
        this->first = this->last = aux;
    }else{
        this->last = this->last->next = aux;
    }
    this->size++;
}

template <typename T>
int Queue<T>::size(){
    return this->size;
}

template <typename T>
void Queue<T>::pop(){
    if (this->size != 0)
    {
        Node<T> *aux= this->first;
        this->first->next = aux->next;
        aux->next = nullptr;
        delete aux;
        this->size--;
        if (this->first == nullptr)
        {
            this->last = nullptr;
        }
        
    }   
}

template <typename T>
bool Queue<T>::empty(){
    return this->size==0;
}

template <typename T>
T& Queue<T>::front(){
    if (this->size == 0)
    {
        throw std::out_of_range("lista vazia");
    }else{
        return this->first->value;
    }
    
}

template<typename T>
Queue<T>::Queue(const Queue& q){
    first = last = nullptr;
    size = 0;
    Node<T> *aux = q.first;
    while (aux != nullptr)
    {
        push(aux->value);
        aux = aux->next;
    }
}

template <typename T>
Queue<T>::~Queue()
{
    delete first;
}

template<typename T>
bool Queue<T>::operator==(const Queue& q) const {
    if (size != q.size)
    {
        return false;
    }
    Node<T> *aux1 = first;
    Node<T> *aux2 = q.first;

    while (aux1 != nullptr)
    {
        if (aux1->value != aux2->value)
        {
            return false;
        }
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    return true;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& q){
    if (this != &q)
    {
        delete first;
        first = last = nullptr;
        size = 0;
        Node<T> *aux = q.first;
        while (aux != nullptr)
        {
            push(aux->value);
            aux = aux->next;
        }
    }
    return *this;
}

#endif