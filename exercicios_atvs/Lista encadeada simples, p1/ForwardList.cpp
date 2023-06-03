/************************************************************************
 * Arquivo de implementacao da classe ForwardList
 * No final deste arquivo existem algumas funcoes que estao incompletas 
 * e voce precisa implementa-las para concluir a atividade
 ************************************************************************/
#include <vector>
#include <stdexcept>
#include <string>
#include "Node.h"
#include "ForwardList.h"

/***************************************************
 * Implementacao das funcoes-membro da classe
 ***************************************************/

ForwardList::ForwardList() {
    m_head = new Node(0, nullptr);
    m_size = 0;
}

ForwardList::ForwardList(const ForwardList& lst) {
    m_head = new Node(0, nullptr);
    m_size = lst.m_size;
    Node *lstCurrent = lst.m_head->next;
    Node *thisLast = m_head;
    while(lstCurrent != nullptr) {
        thisLast->next = new Node(lstCurrent->value, nullptr);
        lstCurrent = lstCurrent->next;
        thisLast = thisLast->next;
    }
}

bool ForwardList::empty() const {
    return m_head->next == nullptr;
}

int ForwardList::size() const {
    return m_size;
}

void ForwardList::clear() {
    while(m_head->next != nullptr) {
        Node *aux = m_head->next;
        m_head->next = aux->next;
        delete aux;
    }
    m_size = 0;
}

ForwardList::~ForwardList() {
    clear();
    delete m_head;
}

Item& ForwardList::operator[](int index) {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

const Item& ForwardList::operator[](int index) const {
    int count = 0;
    Node *current = m_head->next;
    while(count < index) {
        current = current->next;
        count++;
    }
    return current->value;
}

void ForwardList::insert_at(int index, const Item& val) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *newNode = new Node(val, current->next);
    current->next = newNode;
    m_size++;
}

void ForwardList::remove_at(int index) {
    int count = 0;
    Node *current = m_head;
    while(count < index) {
        current = current->next;
        count++;
    }
    Node *temp = current->next;
    current->next = temp->next;
    delete temp;
    m_size--;
}

std::string ForwardList::toString() {
    std::string str = "[ ";
    Node *ptr = m_head->next;
    while(ptr != nullptr) {
        str += std::to_string(ptr->value) + " ";
        ptr = ptr->next;
    }
    str += "]";
    return str;
}

/***********************************************************
 * Funcoes adicionais - Parte 1
 ***********************************************************/


Item& ForwardList::front() {
    // fazer
    Node *viajante = m_head->next;
    return viajante->value;
}

const Item& ForwardList::front() const {
    // fazer
    Node *viajante = m_head->next;
    return viajante->value;
}
    
void ForwardList::push_front(const Item& val) {
    // fazer
    Node *ptr = new Node(val, nullptr);
    ptr->next = m_head->next;
    m_head->next = ptr;
    m_size++;
}

void ForwardList::pop_front() {
    // fazer
    Node *aux = m_head->next;
    int value = aux->value;
    m_head->next = aux->next;
    delete aux;
    m_size--;
}

Item& ForwardList::back() {
    // fazer
    Node *viajante = m_head;
    while (viajante->next != nullptr)
    {
        viajante = viajante->next;
    }
    return viajante->value;
}

const Item& ForwardList::back() const {
    // fazer
    Node *viajante = m_head;
    while (viajante->next != nullptr)
    {
        viajante = viajante->next;
    }
    return viajante->value;
}
    
void ForwardList::push_back(const Item& val) {
    // fazer
    Node *viajante = m_head;
    while (viajante->next != nullptr)
    {
        viajante = viajante->next;
    }
    Node *aux = new Node(val, nullptr); 
    viajante->next = aux;
    m_size++;
}

void ForwardList::pop_back() {
    // fazer
    Node *aux = m_head;
    while(aux->next->next != nullptr){
        aux = aux->next;
    }
    int valor = aux->next->value;
    delete aux->next;
    aux->next = nullptr;
    m_size--;
}


/***********************************************************
 * Funcoes adicionais - Parte 2
 ***********************************************************/

void ForwardList::concat(ForwardList& lst) {
    Node *aux2 = lst.m_head->next;
    Node *aux = m_head;
    while (aux->next != nullptr)
    {
        aux = aux->next;
    }
    while (aux2 != nullptr)
    {
        aux->next = new Node(aux2->value, nullptr);
        m_size++;
        aux = aux->next;
        aux2 = aux2->next;
    }
    lst.clear();
}

void ForwardList::remove(const Item& val) {
    if(m_size != 0){
        Node *aux = this->m_head;
        while(aux->next != nullptr){
            if(aux->next->value == val){
                Node *del = aux->next;
                aux->next = aux->next->next;
                delete del;
                m_size--;
            }else{
                aux = aux->next;
            }
        }
    }
}

ForwardList* ForwardList::clone() {
    ForwardList *saida = new ForwardList();
    Node *aux = m_head->next;
    Node *aux_saida = saida->m_head;
    int *auxm_size = &(saida->m_size);
    while (aux != nullptr)
    {
        aux_saida->next = new Node(aux->value, nullptr);
        (*auxm_size)++;
        aux_saida = aux_saida->next;
        aux = aux->next;
    }
    return saida;
}

void ForwardList::appendVector(const std::vector<Item>& vec) {
    Node *novo = new Node(vec[0],nullptr);
    Node *auxM_head = m_head;
    Node *auxNovo = novo;
    for (int i = 1; i < vec.size(); i++)
    {
        auxNovo->next = new Node(vec[i],nullptr);
        auxNovo = auxNovo->next;
    }
    while (auxM_head->next != nullptr)
    {
        auxM_head = auxM_head->next;
    }
    auxM_head->next = novo;
    m_size = m_size + vec.size();
}

void ForwardList::swap(ForwardList& lst) {
    // fazer
}

bool ForwardList::equals(const ForwardList& lst) const {
    if (this->m_size == lst.m_size)
    {
        Node *aux1 = this->m_head->next;
        Node *aux2 = lst.m_head->next;
        while (aux1->next != nullptr)
        {
            if(aux1->value != aux2->value){
                return false;
            }
            aux1 = aux1->next;
            aux2 = aux2->next;
        }
        return true;
    }
    return false;    
}

void ForwardList::reverse() {
    Item val;
    int cont = 0;
    Node *aux = m_head->next;
    while(cont < (m_size/2)){
        Node *viaj = m_head->next;
        int cont2 = 0;

        while(cont2 < (m_size - cont)-1){
            viaj = viaj->next;
            cont2++;
        }

        val = aux->value;
        aux->value = viaj->value;
        viaj->value = val;
        
        aux = aux->next;
        cont++;
    }
}

Item& ForwardList::get(int index) {
    if(index < 0 || index >=m_size){
        throw std::range_error("index out of range");
    }else{
        int count = 0;
        Node *aux = m_head->next;
        while(count < index){
            aux = aux->next;
            count++;
        }
        return aux->value;
    }
}

const Item& ForwardList::get(int index) const {
    if(index < 0 || index >=m_size){
        throw std::range_error("index out of range");
    }else{
        int count = 0;
        Node *aux = m_head->next;
        while(count < index){
            aux = aux->next;
            count++;
        }
        return aux->value;
    }
}
