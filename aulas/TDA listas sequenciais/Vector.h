#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    int* m_list {nullptr}; // ponteiro para a lista
    int  m_size {0};       // numero de elementos na lista
    int  m_capacity {0};   // capacidade total da lista

public:
    // Construtor default: aloca uma lista com 
    // capacidade inicial igual a 16 e size = 0
    Vector(); // O(1)

    // Copy constructor: cria uma nova lista com os
    // mesmos elementos da lista passada como argumento
    Vector(const Vector& vector); // O(n)
    
    // Destrutor: libera memoria alocada
    ~Vector(); // O(1)

    // Retorna a capacidade atual da lista
    int capacity() const; // O(1)

    // Retorna o numero de elementos na lista
    int size() const; // O(1)
    
    // Retorna true se e somente se a lista estiver vazia
    bool empty() const; // O(1)

    // Retorna uma referencia para o elemento na posicao k.
    // A funcao verifica automaticamente se n esta dentro dos 
    // limites de elementos validos no vetor, lancando uma 
    // excecao 'out_of_range' se nao estiver.
    int& at(int k); // O(1)
    const int& at(int k) const; // O(1)

    // Retorna uma referencia para o elemento na posicao k.
    // Essas funcoes nao verificam se o indice eh valido.
    int& operator[](int index); // O(1)
    const int& operator[](int index) const; // O(1)

    // Solicita que a capacidade do vetor seja >= n. 
    // Se n for maior que a capacidade atual do vetor, a 
    // funcao faz com que a lista aumente sua capacidade 
    // realocando os elementos para o novo vetor. Em todos 
    // os outros casos, a chamada da funcao nao causa uma
    // realocacao e a capacidade do vetor nao eh afetada.
    void reserve(int n); // O(n)
    
    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista. 
    void push_back(const int& value); // tempo medio O(1)
    
    // Remove o ultimo elemento da lista se a lista nao
    // estiver vazia. Caso contrario, faz nada 
    void pop_back(); // O(1)
    
    // Adiciona o elemento value no indice k
    // (somente se 0 <= k <= m_size).
    //  Antes de fazer a inserção, todos os elementos
    // do indice k em diante são deslocados
    // uma posição para a direita.
    void insert(int value, int k); 
};

#endif