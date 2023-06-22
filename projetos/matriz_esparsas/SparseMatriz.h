/**
 *                                   TRABALHO DE ESTRUTURA DE DADDOS
 *                     Nome: Francisco Gabriel Alves Nunes       Matricula: 497357
 *                     Nome: Fernando Paulino de castro junior   Matricula: 505499
 * 
 * 
*/
#ifndef MATRIZ_H
#define MATRIZ_H
#include "Node.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class SparseMatriz
{
public:
    Node<T> *m_matriz;
    int linhas;
    int colunas;

    // construtor e destrutor
    SparseMatriz(int linha, int coluna);
    ~SparseMatriz();

    // insere um valor na matriz na posição (linha, coluna)
    void insert(int linha, int coluna, T value);

    // retorna o valor da matriz na posição (linha, coluna)
    T get(int linha, int coluna);

    //função que imprime a matriz na tela inclusive o os elementos iguais a zero
    void print();

    void remove(int linha, int coluna);
};


// construtor da matriz que cria uma os nós que vão servir de header para andar na matriz
// ordem de complexidade dessa função é O(N) pois ele cria uma dimenção depois cria a segunda dimenção
template <typename T>
SparseMatriz<T>::SparseMatriz(int linha, int coluna){
    if((linha > 0 && coluna > 0) && (linha <= 30000 && coluna <= 30000)){
        this->linhas = linha;
        this->colunas = coluna;
        double insert = -1;
        this->m_matriz = new Node<T>(0,0,insert,nullptr,nullptr);

        Node<T> *aux = this->m_matriz;
        
        for (int i = 1; i <= coluna; i++)
        {
            aux->right = new Node<T>(i,0,insert,nullptr,m_matriz);
            aux = aux->right;
            aux->down = aux;
        }

        Node<T> *aux2 = m_matriz;

        for (int i = 1; i <= linha; i++)
        {
            aux2->down = new Node<T>(0,i,insert,m_matriz,nullptr);
            aux2 = aux2->down;
            aux2->right = aux2;
        }
    }else{
        throw std::out_of_range("Tamanho invalido");
    }
}

// destrutor da matriz 
template <typename T>
SparseMatriz<T>::~SparseMatriz(){
    Node<T> *aux = m_matriz->right;
    for (int i = 0; i < linhas; i++)
    {
        for (int i = 0; i < colunas; i++)
        {
            Node<T> *del = aux;
            aux = aux->right;
            delete del;
        }           
    }
    delete m_matriz;
}

// vai retornar o valor da matriz na posição (linha, coluna), e não existir um nó no lugar ele vai retornar 0
// se a coluna e linha forem diferentes de 0 se não vai abrir uma excecao
// ordem de complexidade dessa função é O(N) visto que a matriz tem duas dimenções.
template <typename T>
T SparseMatriz<T>::get(int linha, int coluna){
    if(linha > 0 && coluna > 0 && linha <= this->linhas && coluna <= this->colunas){
        Node<T> *sentinela;
        Node<T> *aux = this->m_matriz; 
        for (int i = 0; i < coluna; i++){
            aux = aux->right;
        }
        sentinela = aux;
        while (aux->line < linha && aux->down != sentinela){
            aux = aux->down;
        }
        if (aux->line == linha){
            return aux->value;
        }
        return 0;
    }else{
        std::cout << "Tamanho invalido linha e coluna: " << linha << " " << coluna << std::endl;
        throw std::out_of_range("local invalido");
    }
}

// vai inserir um valor na matriz na posição (linha, coluna)
// se o valor da coluna e linha forem diferentes de 0 se não 
// vai abrir uma excecao 
// como nós utilizamos a função get para sabermos se ja existe um nó 
// no lugar que sera inserido o valor, a ordem de complexidade dessa função é O(N²)
template <typename T>
void SparseMatriz<T>::insert(int linha, int coluna, T value){
    if((linha > 0 && coluna > 0)){
        if (value != 0)
        {
            Node<T> *aux_c = m_matriz;
            Node<T> *aux_l = m_matriz;
            while (aux_c->col < coluna)
            {
                aux_c = aux_c->right;
            }
            while (aux_l->line < linha)
            {
                aux_l = aux_l->down;
            }
            Node<T> *sentinela_li = aux_l;
            Node<T> *sentinela_co = aux_c;
            while (aux_c->down->line < linha && aux_c->down != sentinela_co)
            {
                aux_c = aux_c->down;
            }
            while (aux_l->down->col < coluna && aux_l->right != sentinela_li)
            {
                aux_l = aux_l->right;
            }
            if (get(coluna,linha))
            {
                aux_c->down->value = value;
            }else{
                Node<T> *novo = new Node<T>(coluna, linha, value, aux_c->down, aux_l->right);
                aux_c->down = novo;
                aux_l->right = novo; 
            }
        }
    }else{
        throw std::out_of_range("Tamanho invalido");
    }
}

// remove um nó da matriz e muda os valores dos ponteiros dos nós anteriores
// ordem de complexidade dessa função é O(N), pois 
template <typename T>
void SparseMatriz<T>::remove(int linha, int coluna){
    if((linha > 0 && coluna > 0) && (linha <= this->linhas && coluna <= this->colunas)){
        if (get(coluna,linha))
        {
            Node<T> *aux_c = m_matriz;
            Node<T> *aux_l = m_matriz;
            while (aux_c->col < coluna)
            {
                aux_c = aux_c->right;
            }
            while (aux_l->line < linha)
            {
                aux_l = aux_l->down;
            }
            Node<T> *sentinela_li = aux_l;
            Node<T> *sentinela_co = aux_c;
            while(aux_c->down->line < linha && aux_c->down != sentinela_co){
                aux_c = aux_c->down;
            }
            while(aux_l->right->col < coluna && aux_l->right != sentinela_li){
                aux_l = aux_l->right;
            }
            if (aux_c->down->line == aux_l->right->line && aux_c->down->col == aux_l->right->col){
                Node<T> *del = aux_c->down;
                aux_c->down = del->down;
                aux_l->right = del->right;
                delete del;
            }else{
                std::cout << "inutilizado" << std::endl;
            }        
        }
    }else{
        throw std::out_of_range("local invalido");
    }
}

// vai impremir a matriz na tela
// ordem de complexidade dessa função é O(N²), pois
template <typename T>
void SparseMatriz<T>::print(){
    for (int i = 1; i <= linhas; i++)
    {
        for (int j = 1; j <= colunas; j++)
        {
            std::cout << get(i,j) << " ";
        }
        std::cout << std::endl;
    }
}

#endif