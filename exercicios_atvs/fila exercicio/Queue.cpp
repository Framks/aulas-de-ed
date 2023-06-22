#include <iostream>
#include "Queue.h"

Queue::Queue(){
    this->deposito = std::stack<int>();
    this->prateleira = std::stack<int>();
}

Queue::~Queue(){
    
}

void Queue::add(int value){
    this->deposito.push(value);
}

void Queue::remove(){
    if (this->prateleira.empty())
    {
        while(!this->deposito.empty())
        {
            this->prateleira.push(this->deposito.top());
            this->deposito.pop();
        }
    }
    try
    {
        this->prateleira.pop();
    }
    catch(const std::exception& e)
    {
        std::cout << "nao foi posivel remover" << std::endl;
    }
}

int Queue::front(){
    if (this->prateleira.empty())
    {
        while (!this->deposito.empty())
        {
            this->prateleira.push(this->deposito.top());
            this->deposito.pop();
        }
    }
    try
    {
        return this->prateleira.top();
    }
    catch(const std::exception& e)
    {
        std::cout << "lista vazia" << std::endl;
    }
}