/**
 *                                   TRABALHO DE ESTRUTURA DE DADDOS
 *                     Nome: Francisco Gabriel Alves Nunes       Matricula: 497357
 *                     Nome: Fernando Paulino de castro junior   Matricula: 505499
 * 
 * 
*/
#include "SparseMatriz.h"
#include <sstream>
#include <vector>
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
    vector<SparseMatriz *> matrizes; // Vector de ponteiros para matrizes

    while (true)
    {
        string line;
        string comando;

        getline(cin, line);
        stringstream ss{line};

        ss >> comando;

        if (comando == "exit")
        {
            for (int i = 0; i < matrizes.size(); ++i)
            {
                delete matrizes[i];
            }
            return 0;
        }
        // creatematrix [l] [c]
        else if (comando == "creatematrix")
        {
            int l, c;
            ss >> l;
            ss >> c;
            Matriz *m = new Matriz(l, c);
            for (int i = 0; i < l; ++i)
            {
                for (int j = 0; j < c; ++j)
                {
                    int val = 0;
                    cin >> val;
                    cin.ignore();
                    m->setValor(val, i, j);
                }
            }
            matrizes.push_back(m);
        }
        // printmatrix [k]
        else if (comando == "printmatrix")
        {
            int k;
            ss >> k;
            matrizes[k]->print();
        }
        // nlinhas [k]
        else if (comando == "nlinhas")
        {
            int k;
            ss >> k;
            cout << "linhas: " << (matrizes[k])->linhas() << endl;
        }
        // ncolunas [k]
        else if (comando == "ncolunas")
        {
            int k;
            ss >> k;
            cout << "colunas: " << matrizes[k]->colunas() << endl;
        }
        // getvalor [i] [j] [k]
        else if (comando == "getvalor")
        {
            int i, j, k;
            ss >> i >> j >> k;
            cout << "valor: " << matrizes[k]->getValor(i, j) << endl;
        }
        // sum [p] [q]
        else if (comando == "sum")
        {
            int p, q;
            ss >> p >> q;
            Matriz *C = matrizes[p]->soma(*(matrizes[q]));
            if (C == nullptr)
                cout << "nao foi possivel somar" << endl;
            else
            {
                C->print();
                delete C;
            }
        }
        // multiply [p] [q]
        else if (comando == "multiply")
        {
            int p, q;
            ss >> p >> q;
            Matriz *C = matrizes[p]->multiplica(*(matrizes[q]));
            if (C == nullptr)
                cout << "nao foi possivel multiplicar" << endl;
            else
            {
                C->print();
                delete C;
            }
        }
        else
        {
            cout << "comando inexistente" << endl;
        }
    }
}
