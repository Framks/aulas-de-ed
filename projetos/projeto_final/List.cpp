/**
 *  @file List.cpp
 *  @author Francisco Gabriel Alves Nunes
 *  @brief Implementação de lista encadeada
 *  @version 0.1
 *  @date 2023-07-08
 *  
 * @copyright Copyright (c) 2023
*/
#include <iostream>
#include "List.h"

// este sera o nó que sera usado na lista
struct Node 
{
    int value;
    Node* next;
    Node* prev;

    Node(const int& val, Node* prev, Node *nextPtr) 
    {
        value = val;
        this->next = nextPtr;
        this->prev = prev;
    }
};

List::List(){
    m_head = new Node(0,nullptr,nullptr);
    m_head->next = m_head;
    m_size = 0;
}

List::~List(){
    this->clear();
    delete m_head;
}

void List::clear(){
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

bool List::empty() const{
    return m_head->next == m_head;
}

void List::push_back(const int& val){
    Node *viajante = this->m_head;
    while (viajante->next != this->m_head)
    {
        viajante = viajante->next;
    }
    viajante->next = new Node(val,viajante,this->m_head);
    m_head->prev = viajante->next;
    this->m_size++;
}

void List::pop_back(){
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

void List::print(){
    Node *viajante = m_head->next;
    while (viajante != m_head)
    {
        std::cout << viajante->value << " ";
        viajante = viajante->next;
    }
    std::cout << std::endl;
}

void List::bubbleSort(){ // olhar se ta certo
    if (empty()) {
        return;
    }

    bool swapped;
    do {
        swapped = false;
        Node* current = m_head;

        while (current->next != m_head) {
            if (current->value > current->next->value) {
                // Realiza a troca de valores
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void List::insertionSort(){ // todo
    for (Node* j = m_head->next->next; j != m_head; j = j->next)
    {
        int key = j->value;

        Node* i = j->prev;
        while(i != m_head && i->value > key)
        {
            i->next->value = i->value;
            i = i->prev;
        }
        i->next->value = key;
    }
}

void List::selectionSort(){
    for(Node* i = m_head->next; i->next != m_head; i = i->next){
        Node* min = i;
        for(Node* j = i->next; j != m_head; j = j->next){
            if(j->value > min->value)
                min = j;
            int aux = j->value;
            j->value = min->value;
            min->value = aux;
        }
    }
}


void List::quickSort(){ // todo
    this->quick(m_head, m_head->next, m_head->prev);
}

void List::quick(Node* list, Node* comeco, Node* fim){
    if(!(comeco->prev == fim) && !(comeco == fim)){
        Node* pivot = partition(list, comeco, fim);
        quick(list, comeco, pivot->prev);
        quick(list, pivot->next, fim);
    }
}

Node* List::partition(Node* pivot, Node* comeco, Node* fim){
    int pivo = fim->value;
    Node* j = comeco;
    for(Node* k = comeco; k != fim; k = k->next){
        if(k->value <= pivo){
            int aux = k->value;
            k->value = j->value;
            j->value = aux;
            j = j->next;
        }
    }
    fim->value = j->value;
    j->value = pivo;
    return j;
}

void List::mergeSort(){ // todo
    merge(0, m_size-1);
}

void List::merge(int p, int r){
    if(p < r){
        int q = (p+r)/2;    
        Node* comeco = m_head->next;
        Node* fim = m_head->next;
        Node* pivo = m_head->next;
        for (int i = 0; i < r || i < q || i < p; i++)
        {
            if(i < r)
            {
                fim = fim->next;
            }
            if(i < q)
            {
                pivo = pivo->next;
            }
            if(i < p)
            {
                comeco = comeco->next;
            }
        }
        merge(p, q);
        merge(q+1, r);
        int w = (r-p)+1;
        intercalar(comeco, pivo, fim, w);
    }
}

void List::intercalar(Node* comeco, Node* pivo, Node* fim, int w){
    int vetor_aux[w];
    Node* sent_comeco = comeco;
    Node* sent_pivo = pivo;
    int k = 0;
    pivo = pivo->next;
    while (comeco->prev != sent_pivo && pivo->prev != fim){
        if(comeco->value <= pivo->value){
            vetor_aux[k++] = comeco->value;
            comeco = comeco->next;
        }
        else{
            vetor_aux[k++] = pivo->value;
            pivo = pivo->next;
        }
    }
    
    while (comeco->prev != sent_pivo && comeco->prev->prev != sent_pivo){
        vetor_aux[k++] = comeco->value;
        comeco = comeco->next;
    }
    while (pivo->prev != fim && pivo->prev->prev != fim){
        vetor_aux[k++] = pivo->value;
        pivo = pivo->next;
    }
    
    for (int i = 0; i < w; i++){
        sent_comeco->value = vetor_aux[i];
        sent_comeco = sent_comeco->next;        
    }
}

void List::radixSort(){
    int maior = getmax();
    
    for (int i = 1; maior / i > 0 ; i*=10)
        countingSort(m_size-1, i); 
}

int List::getmax(){
    int max = m_head->next->value;
    for(Node* i = m_head->next; i != m_head; i = i->next){
        if(i->value > max)
            max = i->value;
    }
    return max;
}

void List::countingSort(int n, int exp){
    int out[n];
    int count[10] = {0};

    for (Node* i = m_head->next; i != m_head; i = i->next){
        count[(i->value/exp)%10]++;
    }

    for (int i = 1; i < 10; i++){
        count[i] += count[i-1];
    }

    for (Node* i = m_head->prev; i != m_head; i = i->prev){
        int w = (i->value/exp)%10;
        out[count[w]-1] = i->value;
        count[w]--;
    }

    int a = 0;
    for (Node* i = m_head->next; i != m_head; i = i->next){
        i->value = out[a];
        a++;
    }
}