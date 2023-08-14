/**
 * @file List.h
 * @author Francisco Gabriel ALves Nunes
 * @brief Projeto Final - ED --- Arquivo de cabeçalho
 * @version 0.1
 * @date 2023-07-08
 * 
 * @copyright Copyright (c) 2023
*/
#ifndef LIST_H
#define LIST_H

struct Node;

// aqui fica a definição de cada uma das funções
class List {
private:
    Node* m_head;
    int m_size;
public:
    // construtor e destrutor.
    List();
    ~List();

    // retorna true caso esteja vazia, ou false se estiver vazia
    bool empty()const;

    // retorna o tamanho da lista
    int size() const { return m_size; }

    // adiciona um elemento ao final da lista
    void push_back(const int& val);

    // remove um elemento do final da lista, se ele existir
    // caso contrario, nao faz nada
    void pop_back();

    // deixa a lista vazia, liberando todos os nos
    void clear();

    // adiciona um elemento no inicio da lista
    void push_front(const int& val); 

    // remove um elemento do inicio da lista, se ele existir
    // caso contrario, nao faz nada
    void pop_front();

    // função para ordenar a lista em ordem crescente
    void bubbleSort();
    void insertionSort();
    void selectionSort();
    void mergeSort();
    void quickSort();
    void radixSort();
    void print();

private:
    void insert(Node** aux1, Node* aux2);  // vai ser usado no insertionSort
    void heap();       // vai ser usado no heap
    void merge(int n, int m);      // vai ser usado no mergeSort
    void intercalar(Node* comeco, Node* pivo, Node* fim, int w);  // vai ser usado no merge

    Node* partition(Node* pivot, Node* aux1, Node* aux2);  // vai ser usado no quicksort
    void quick(Node* pivot, Node* aux1, Node* aux2);      // vai ser usado no quickSort

    int getmax();
    void countingSort(int n, int exp);
};
#endif