/**
 *                                   TRABALHO DE ESTRUTURA DE DADDOS
 *                     Nome: Francisco Gabriel Alves Nunes       Matricula: 497357
 *                     Nome: Fernando Paulino de castro junior   Matricula: 505499
 * 
 * 
*/
#include "SparseMatriz.h"
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

//
// função que retorna a multiplicação de duas matrizes
template <typename T>
SparseMatriz<T> *multiply(SparseMatriz<T> *a, SparseMatriz<T> *b){
    if (a->colunas <= b->linhas && a->linhas <= b->colunas)
    {
        SparseMatriz<T> *mult = new SparseMatriz<T>(a->linhas, b->colunas);
        for (int i = 1; i <= a->linhas; i++)
        {
            for (int j = 1; j <= b->colunas; j++)
            {
                for (int k = 1; k <= a->colunas; k++)
                {
					mult->insert(i, j, (mult->get(i, j) + (a->get(i, k) * b->get(k, j))));
                }
            }
        }
        return mult;
    }
    else
    {
        return nullptr;
    }
}

// função que retorna a soma de duas matrizes 
template <typename T>
SparseMatriz<T> *sum(SparseMatriz<T> *a, SparseMatriz<T> *b){
	if (a->linhas == b->linhas && a->colunas == b->colunas)
	{
		SparseMatriz<T> *sum = new SparseMatriz<T>(a->linhas, b->colunas);
		for (int i = 1; i <= a->linhas; i++)
		{
			for (int j = 1; j <= b->colunas; j++)
			{
				sum->insert(i, j, (a->get(i, j) + b->get(i, j)));
			}
		}
		return sum;
	}
	else
	{
		return nullptr;
	}
}

// função que le uma matriz esparsa de um arquivo pasado por parametro 
template <typename T>
SparseMatriz<T> *readSparseMatriz(string fileName){
	try
	{
		fstream fileMatriz(fileName);
		SparseMatriz<T> *aux = nullptr;
		if (!fileMatriz.is_open())
		{
			throw out_of_range("não foi possivel abrir o arquivo");
		}else{
			int linha, coluna;
			if (fileMatriz >> coluna >> linha)
			{
				T value;
				aux = new SparseMatriz<T>(coluna,linha);
				while (fileMatriz >> coluna >> linha >> value)
				{
					aux->insert(coluna, linha, value);
				}
			}
		}
		fileMatriz.close();
		return aux;
	}
	catch(exception e)
	{
		cout << e.what() << " erro ao abrir o arquivo" << endl;
		return nullptr;
	}
}

int main(){
    vector<SparseMatriz<double>*> matrizes; // Vector de ponteiros para matrizes
	
	while(true) {
		string line;
		string comando;
		
		getline(cin, line);
		stringstream ss { line };
		
		ss >> comando;

		if(comando == "exit") {
			for(int i = 0; i < matrizes.size(); ++i) {
				delete matrizes[i];
			}
			return 0;
		}
		// creatematrix [l] [c]
		else if(comando == "creatematrix") {
			int l, c;
			ss >> c;
			ss >> l;
            SparseMatriz<double> *m = new SparseMatriz<double>(c, l);
			matrizes.push_back( m );
		}
		// printmatrix [k]
		else if(comando == "printmatrix") {
			int k;
			ss >> k;
			matrizes[k]->print();
		}
		// nlinhas [k]
		else if(comando == "nlinhas") {
			int k;
			ss >> k;
			cout << "linhas: " << (matrizes[k])->linhas << endl;
		}
        // ncolunas [k]
		else if(comando == "ncolunas") {
			int k;
			ss >> k;
			cout << "colunas: " << matrizes[k]->colunas << endl;
		}
        // getvalor [i] [j] [k]
		else if(comando == "getvalor") {
			int i, j, k;
			ss >> i >> j >> k;
			cout << "valor: " << matrizes[k]->get(i,j) << endl;
		}
        // setvalor [i] [j] [k] [value]
		else if(comando == "setvalor") {
			int i, j, k;
            double val;
			ss >> i >> j >> k >> val;
			matrizes[k]->insert(i,j,val);
		}
		// sum [p] [q] 
		else if(comando == "sum") {
            int p, q;
			ss >> p >> q;
			SparseMatriz<double> *C = sum(matrizes[p], matrizes[q]);
			if(C == nullptr) 
                cout << "nao foi possivel somar" << endl;
            else {
                C->print();
                delete C;
            }
		}
        // multiply [p] [q] 
		else if(comando == "multiply") {
            int p, q;
			ss >> p >> q;
			SparseMatriz<double> *C = multiply(matrizes[p], matrizes[q]);
			if(C == nullptr) 
                cout << "nao foi possivel multiplicar" << endl;
            else {
                C->print();
                delete C;
            }
		}
		// remove [i] [j] [k]
		else if(comando == "remove"){
			int i, j, k;
			ss >> i >> j >> k;
			matrizes[k]->remove(i, j);
		}
		// read [name file]
		else if(comando == "read"){
			string file;
			ss >> file;
			SparseMatriz<double> *c = readSparseMatriz<double>(file);
			if (c != nullptr)
			{
				matrizes.push_back(c);
			}else{
				cout << "nao foi posivel inserir a matriz; " << endl;
			}
			
		}
		// help
		else if(comando == "help"){
			cout << "\n\n\nOs comandos validos sao:" << endl;
			cout << "exit -------------------------- sai do programa" << endl;
			cout << "creatematrix [l] [c] ---------- cria uma matrix de l linhas e c colunas" << endl;
			cout << "printmatrix [k] --------------- imprime uma matriz na posicao k" << endl;
			cout << "nlinhas [k] ------------------- imprime a quantidade de linhas na matriz k" << endl;
			cout << "ncolunas [k] ------------------ imprime a quantidade de colunas na matriz k" << endl;
			cout << "getvalor [i] [j] [k] ---------- busca o valor na matriz k na posicao i linhas e j colunas" << endl;
			cout << "setvalor [i] [j] [k] [value] -- insere o valor na matriz k na posicao i linhas e j colunas" << endl;
			cout << "sum [p] [q] ------------------- soma as matrizes p e q" << endl;
			cout << "multiply [p] [q] -------------- multiplica as matrizes p e q" << endl;
			cout << "remove [i] [j] [k] ------------ remove uma valor da matriz k na posicao i linhas e j colunas" << endl;
			cout << "read [name file] -------------- le uma matriz do arquivo\n\n" << endl;

		}
		// qualquer coisa que for digitada não é válida
		else{
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}
