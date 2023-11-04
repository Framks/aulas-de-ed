#include <iostream>
#include <string>
#include <sstream>
#include "node.h"
#include "CircularList.h"

CircularList::CircularList(){
    m_head = new Node(0,nullptr);
    m_head->next = m_head;
    m_size = 0;
}

bool CircularList::empty() const{
    /*
    if (m_head->next == m_head)
    {
        return true;
    }
    return false;
    */
   return m_head->next == m_head;
}

void CircularList::push_back(const int& val){
    Node *viajante = m_head;
    while (viajante->next != m_head)
    {
        viajante = viajante->next;
    }
    viajante->next = new Node(val,m_head);
    m_size++;
}

void CircularList::pop_back(){
    if (m_head->next != m_head)
    {
        Node *viajante = m_head;
        while (viajante->next->next != m_head)
        {
            viajante = viajante->next;
        }
        Node *morto = viajante->next;
        viajante->next = m_head;
        delete morto;
        m_size--;
    }
}

int& CircularList::operator[](int index){
    if(index >=0 && index <m_size){
        int count = 0;
        Node *aux = m_head;
        while (count  <= index)
        {
            aux = aux->next;
            count++;
        }
        return aux->value;        
    }else{
        throw std::out_of_range("index fora da lista");
    }
}

const int& CircularList::operator[](int index) const{
    if(index >=0 && index <m_size){
        int count = 0;
        Node *aux = m_head;
        while (count  <= index)
        {
            aux = aux->next;
            count++;
        }
        return aux->value;        
    }else{
        throw std::out_of_range("index fora da lista");
    }
}

CircularList::~CircularList(){
    clear();
    delete m_head;
}

void CircularList::clear(){
    if (m_head->next != m_head)
    {
        Node *aux = m_head->next;
        while (aux != m_head)
        {
            Node *del = aux;
            aux = aux->next;
            delete del;
        }
        m_head->next = m_head;
        m_size = 0;
    }
}

std::string CircularList::toString()const{
    /* minha solução para o problema
        std::string saida = "";
        if (m_size != 0)
        {
            Node *aux = m_head->next;
            while (aux != m_head)
            {
                saida.append(std::to_string(aux->value) + " ");
                aux = aux->next;
            }
        }
        return saida;
    */

   // solução do professor 
    std::stringstream ss;
    Node *aux = m_head->next;
    while (aux != m_head){
        ss << aux->value << " ";
        aux = aux->next;
    }
    std::string str = ss.str();
    str.pop_back();
    return str;
}

std::ostream& operator<<(std::ostream& out, CircularList& lst){
    Node *aux = lst.m_head->next;
    while (aux != lst.m_head){
        out << aux->value << " ";
        aux = aux->next;
    }
    return out;
}
