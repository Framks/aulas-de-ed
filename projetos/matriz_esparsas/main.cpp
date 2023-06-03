/**
 *                                   TRABALHO DE ESTRUTURA DE DADDOS
 *                     Nome: Francisco Gabriel Alves Nunes       Matricula: 497357
 *                     Nome: Fernando Paulino de castro junior   Matricula: 505499
 * 
 * 
*/
#include "SparseMatriz.h"
#include <iostream>
using namespace std;
/*
// função que retorna a multiplicação de duas matrizes
SparseMatriz *multiply(SparseMatriz *a, SparseMatriz *b){
    
}

// função que retorna a soma de duas matrizes
SparseMatriz *sum(SparseMatriz *a, SparseMatriz *b){
    
}

// função que le uma matriz esparsa de um arquivo pasado por parametro
SparseMatriz *readSparseMatriz(string fileName){
    
}

*/
int main(){
    SparseMatriz a (4,4);
    a.print();
    
    a.insert(1,4,1);
    a.insert(1,2,2);
    a.insert(3,1,3);
    a.insert(4,3,4);
    a.insert(2,2,5);
    a.insert(1,1,6);
    a.print();

    a.insert(1,4,8);    
    a.print();
}
