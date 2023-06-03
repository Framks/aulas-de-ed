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

    ForwardList(const ForwardList& other);

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

    // remove um elemento de dentro da lista na posicao indice
    int at(int index);

    int pop_back();

    int  pop_front();

    // Substitui o elemento no índice k pelo elemento value (somente se 0 <= k <= m_size -1)
    // Apenas o valor, não precisa substitui o nó
    void replace_at(int value, int k);
    
    //Determina se a lista lst, passada por parâmetro, é igual a lista do objeto.
    //Duas listas são iguais se têm o mesmo tamanho e o valor do k-ésimo elemento da primeira lista é igual ao k-ésimo valor da segunda.
    bool equals(ForwardList& lst);

    // Remove todas as ocorrências do elemento value na lista. A ordem dos demais elementos da lista entre se devem se manter
    void removeAll(int value);

    //Concatena a lista do objeto com a lista lst, passada por parâmetro. A lista lst não é modificada nessa operação.
    //Os elementos de lst serão adicionados na ordem no final da lista do objeto da função.
    void concat(ForwardList& lst);

    // remove o elemento no indice especificado
    void removeAt(int k);
};

void ForwardList::removeAt(int k){
    if(k >= 0 && k < m_size){
        Node *aux = m_head;
        int cont = 0;
        while(cont < k-1){
            aux = aux->next;
            cont++;
        }
        Node *morto = aux->next;
        aux->next = aux->next->next;
        delete morto;
        m_size--;
    }
}

void ForwardList::concat(ForwardList& lst){
    Node* aux = lst.m_head->next;
    while(aux != nullptr){
        push_back(aux->value);
        aux = aux->next;
    }
}

bool ForwardList::equals(ForwardList& lst){
    if(m_size == lst.m_size){
        for (int i = 0; i < m_size; i++)
        {
            if(at(i) != lst.at(i)){
                return false;
            }
        }
    }else{
        return false;
    }
    return true;
}

void ForwardList::removeAll(int value){
    Node *aux = m_head;
    Node *morto;
    while (aux->next!= nullptr)
    {
        if(aux->next->value == value){
            morto = aux->next;
            aux->next = aux->next->next;
            delete morto;
            m_size--;
        }
        aux = aux->next;
    }
}

ForwardList::ForwardList()
{
    m_head = new Node(0,nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& other){
    m_head = new Node(0,nullptr);
    m_size = 0;
    while (other.m_head->next != nullptr)
    {
        push_back(other.m_head->next->value);
    }
    
}

void ForwardList::push_front(const int& val){
    Node *ptr = new Node(val, nullptr);
    ptr->next = m_head->next;
    m_head->next = ptr;
    m_size++;
}

int ForwardList::pop_front(){
    Node *aux = m_head->next;
    int value = aux->value;
    m_head->next = aux->next;
    delete aux;
    m_size--;
    return value;
}

void ForwardList::replace_at(int value, int k){
    Node *aux = m_head;
    int cont = 0;
    while(cont < k){
        aux = aux->next;
        cont++;
    }
    aux->value = value;
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
            contador++;
        }
        Node *novo = new Node(val, nullptr);
        novo->next = viajante->next;
        viajante->next = novo;
        m_size++;

    }
}

int ForwardList::at(int indice){
    if(indice >= 0 && indice <= m_size)
    {
        int cont = 0;
        Node *viajante = m_head;
        while (cont <= indice)
        {
            viajante = viajante->next;
            cont++;
        }
        return viajante->value;
    }
    return -1;
}

int ForwardList::pop_back(){
    if(m_size > 0)
    {
        Node *aux = m_head;
        while(aux->next->next != nullptr){
            aux = aux->next;
        }
        int valor = aux->next->value;
        delete aux->next;
        aux->next = nullptr;
        m_size--;
        return valor;
    }
    return -1;
}

#endif