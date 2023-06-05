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

class SparseMatriz
{
private:
    Node *m_matriz;
    int linhas;
    int colunas;
public:
    // construtor e destrutor
    SparseMatriz(int coluna, int linha);
    ~SparseMatriz();

    // insere um valor na matriz na posição (linha, coluna)
    void insert(int coluna, int linha, double value);

    // retorna o valor da matriz na posição (linha, coluna)
    double get(int coluna, int linha);

    //função que imprime a matriz na tela inclusive o os elementos iguais a zero
    void print();

    void remove(int coluna, int linha);

    //retorna o valor do tamanho da matriz
    int size();
};


// definição do construtor que cria um nó sentinela e a matriz vazia
SparseMatriz::SparseMatriz(int coluna, int linha){
    if(linha > 0 && coluna > 0){
        this->linhas = linha;
        this->colunas = coluna;
        this->m_matriz = new Node(0,0,-1,nullptr,nullptr);

        Node *aux = this->m_matriz;
        
        for (int i = 1; i <= coluna; i++)
        {
            aux->right = new Node(i,0,-1,nullptr,m_matriz);
            aux = aux->right;
            aux->down = aux;
        }

        Node *aux2 = m_matriz;

        for (int i = 1; i <= linha; i++)
        {
            aux2->down = new Node(0,i,-1,m_matriz,nullptr);
            aux2 = aux2->down;
            aux2->right = aux2;
        }
    }else{
        throw std::out_of_range("Tamanho invalido");
    }
}

// destrutor da matriz 
SparseMatriz::~SparseMatriz(){
    Node *aux = m_matriz->right;
    for (int i = 0; i < linhas; i++)
    {
        for (int i = 0; i < colunas; i++)
        {
            Node *del = aux;
            aux = aux->right;
            delete del;
        }           
    }
    delete m_matriz;
}


double SparseMatriz::get(int coluna, int linha){
    if(linha > 0 && coluna > 0 && linha <= this->linhas && coluna <= this->colunas){
        Node *sentinela;
        Node *aux = this->m_matriz; 
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
        throw std::out_of_range("local invalido");
    }
}

void SparseMatriz::insert(int coluna, int linha, double value){
    if((linha > 0 && coluna > 0) && value != 0){
        Node *aux_c = m_matriz;
        Node *aux_l = m_matriz;
        while (aux_c->col < coluna)
        {
            aux_c = aux_c->right;
        }
        while (aux_l->line < linha)
        {
            aux_l = aux_l->down;
        }
        Node *sentinela_li = aux_l;
        Node *sentinela_co = aux_c;

        while (aux_c->down->line < linha && aux_c->down != sentinela_co)
        {
            aux_c = aux_c->down;
        }

        while (aux_l->down->col < coluna && aux_l->right != sentinela_li)
        {
            aux_l = aux_l->right;
        }
        if (get(coluna,linha) != 0)
        {
            aux_c->value = value;
        }else{
            Node *novo = new Node(coluna, linha, value, aux_c->down, aux_l->right);
            aux_c->down = novo;
            aux_l->right = novo; 
        }
    }else{
        throw std::out_of_range("Tamanho invalido");
    }
}

// remove um nó da matriz e muda os valores dos ponteiros dos nós anteriores
void SparseMatriz::remove(int coluna, int linha){
    if((linha > 0 && coluna > 0) && (linha <= this->linhas && coluna <= this->colunas)){
        if (get(coluna,linha) != 0)
        {
            Node *aux_c = m_matriz;
            Node *aux_l = m_matriz;
            while (aux_c->col < coluna)
            {
                aux_c = aux_c->right;
            }
            while (aux_l->line < linha)
            {
                aux_l = aux_l->down;
            }
            Node *sentinela_li = aux_l;
            Node *sentinela_co = aux_c;
            while(true){
                if(aux_c->down->line < linha && aux_c->down != sentinela_co){
                    aux_c = aux_c->down;
                }else{
                    break;
                }
            }
            while(true){
                if(aux_l->down->col < coluna && aux_l->right != sentinela_li){
                    aux_l = aux_l->right;
                }else{
                    break;
                }
            }
            if (aux_c->down == aux_l->right){
                Node *del = aux_c->down;
                aux_c->down = del->down;
                aux_l->right = del->right;
                delete del;
            }            
        }
    }else{
        throw std::out_of_range("local invalido");
    }
}

void SparseMatriz::print(){
    for (int i = 1; i <= linhas; i++)
    {
        for (int j = 1; j <= colunas; j++)
        {
            std::cout << get(j, i) << " ";
        }
        std::cout << std::endl;
    }
}

#endif