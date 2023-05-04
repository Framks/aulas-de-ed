#include <iostream>
#include <stdexcept>
#include "Vector.h"
using namespace std;

// Construtor default: aloca uam lista com
// capacidade inicial igual a 16 e size = 0 // O(1)
Vector::Vector()
{
    m_list = new int[16];
    m_capacity = 16;
}

// Copy constructor: cria uma nova lista com os
// mesmos elementos da lista passada como argumento
Vector::Vector(const Vector &vector)
{ // O(n)
    m_capacity = vector.m_capacity;
    m_size = vector.m_size;
    m_list = new int[m_capacity];
    for (int i = 0; i < m_size; i++)
    {
        m_list[i] = vector.m_list[i];
    }
}

// Destrutor: libera memoria alocada
Vector::~Vector()
{ // O(1)
    delete[] m_list;
}

// Retorna a capacidade atual da lista
int Vector::capacity() const
{ // O(1)
    return m_capacity;
}

// Retorna o numero de elementos na lista
int Vector::size() const
{ // O(1)
    return m_size;
}

// Retorna true se e somente se a lista estiver vazia
bool Vector::empty() const
{ // O(1)
    return m_list == nullptr;
}

// Retorna uma referencia para o elemento na posicao k.
// Essas funcoes nao verificam se o indice eh valido.
int &Vector::operator[](int index)
{ // O(1)
    return m_list[index];
}

// Retorna uma referencia para o elemento na posicao k.
// A funcao verifica automaticamente se n esta dentro dos
// limites de elementos validos no vetor, lancando uma
// excecao 'out_of_range' se nao estiver.
int &Vector::at(int k)
{ // O(1)
    if (k >= 0 && k <= size())
        return m_list[k];
    else
        throw out_of_range("erro: indice invalido");
}

// Recebe um inteiro como argumento e o adiciona
// logo apos o ultimo elemento da lista.
void Vector::push_back(const int &value)
{ // tempo medio O(1)
    if (m_size < m_capacity)
    {
        m_list[m_size] = value;
        m_size++;
    }
}

// Solicita que a capacidade do vetor seja >= n.
// Se n for maior que a capacidade atual do vetor, a
// funcao faz com que a lista aumente sua capacidade
// realocando os elementos para o novo vetor. Em todos
// os outros casos, a chamada da funcao nao causa uma
// realocacao e a capacidade do vetor nao eh afetada.
void Vector::reserve(int n)
{ // O(n)
    if (n > m_capacity)
    {
        int *m_list2 = new int[n];
        m_capacity = n;
        for (int i = 0; i < m_size; i++)
        {
            m_list2[i] = m_list[i];
        }
        delete[] m_list;
        m_list = m_list2;
    }
}

// Remove o ultimo elemento da lista se a lista nao
// estiver vazia. Caso contrario, faz nada
void Vector::pop_back()
{ // O(1)
    if (m_size > 0)
    {
        m_list[m_size] = NULL;
    }
}
