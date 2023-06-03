#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "stdexcept"

template<typename T>
class Stack
{
private:
    Node<T> *m_top;
    int m_size;

public:
    Stack(/* args */);
    ~Stack();
    bool empty();
    int size();
    T& top();
    void push(const T& val);
    void pop();
};
template <typename T>
Stack<T>::Stack(/* args */)
{
    m_top = nullptr;
    m_size = 0;
}

template <typename T>
Stack<T>::~Stack()
{
    delete m_top;
}

template <typename T>
bool Stack<T>::empty(){
    return m_top==nullptr;
}

template <typename T>
T& Stack<T>::top(){
    if (m_size == 0)
    {
        throw std::out_of_range("stack underflow");
    }
    return m_top->value;
}

template <typename T>
void Stack<T>::push(const T& val){
    Node<T> *aux = new Node<T>(val, m_top);
    m_top = aux;
    m_size++;
}

template <typename T>
void Stack<T>::pop(){
    if (!empty())
    {   
        Node<T> *aux = m_top;
        m_top = aux->next;
        aux->next = nullptr;
        m_size--;
        delete aux;
    }
}

#endif