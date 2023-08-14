/**
 *  @file main.cpp
 *  @author Francisco Gabriel Alves Nunes
 *  @brief implementação do trabalho final 
 *  @version 0.1
 *  @date 2023-07-08
 *  
 * @copyright Copyright (c) 2023
*/
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <chrono>
#include "List.h"
using namespace std;


// aqui vou fazer a função que gera os dados que serão usados e salvar em arquivos
// 
void gera_dados(const int& num_iteracoes,const int vetor_tam[]){
	for(int n = 0; n < num_iteracoes; ++n) {
		// para cada tamanho n, sao gerados 5 vetores de tamanho n com numeros aleatorios
		for(int semente = 0; semente < 5; semente++) {	
			std::string nome_arquivo = "dados/interacao"+std::to_string(n)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[n];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*) &r, sizeof(r)); // escreve numero r no arquivo binario
			}
			fout.close();
		}
	}
}

void ler_dados(int tamanho_lista, int vetor[],string nome);

void executar(const int& num_iteracoes,const int vetor_tam[],const string nome_funcao,const string nome_arquivo){
	ofstream fout(("resultados/"+nome_arquivo+".txt").c_str(), ofstream::out);
	for (int interacoes = 0; interacoes < num_iteracoes; interacoes++)
	{
		long double tempo_medio = 0.0;
		const int tamanho_lista = vetor_tam[interacoes];
		List lista;
		int vetor[tamanho_lista];
		cout << "tamanho da lista: " << tamanho_lista << endl;
		for(int i = 0; i < 5; i++)
		{
			string nome = "dados/interacao"+to_string(interacoes)+"_"+to_string(i)+".dat";
			ler_dados(tamanho_lista, vetor, nome);
			for(int j = 0; j < tamanho_lista; j++)
			{
				lista.push_back(vetor[j]);
			}
			auto inicio = chrono::high_resolution_clock::now();
			auto fim = chrono::high_resolution_clock::now();
			if(nome_funcao == "bubblesort")
			{
				inicio = chrono::high_resolution_clock::now();
				lista.bubbleSort();
				fim = chrono::high_resolution_clock::now();
			}
			else if(nome_funcao == "selectionsort")
			{
				inicio = chrono::high_resolution_clock::now();
				lista.selectionSort();
				fim = chrono::high_resolution_clock::now();
			}
			else if(nome_funcao == "insertionsort")
			{
				inicio = chrono::high_resolution_clock::now();
				lista.insertionSort();
				fim = chrono::high_resolution_clock::now();
			}
			else if(nome_funcao == "mergesort")
			{
				inicio = chrono::high_resolution_clock::now();
				lista.mergeSort();
				fim = chrono::high_resolution_clock::now();
			}
			else if(nome_funcao == "quicksort")
			{
				inicio = chrono::high_resolution_clock::now();
				lista.quickSort();
				fim = chrono::high_resolution_clock::now();
			}
			else if(nome_funcao == "radixsort")
			{
				inicio = chrono::high_resolution_clock::now();
				lista.radixSort();
				fim = chrono::high_resolution_clock::now();
			}
			auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio).count();
			tempo_medio += duracao;
		}
		fout << tamanho_lista << " " << tempo_medio/5.0 << endl;
		cout << "Tempo medio: " << tempo_medio/5.0 << endl;
	}
	fout.close();
}

void ler_dados(int tamanho_vetor, int vetor[],string nomeArquivo){
	ifstream input_file(nomeArquivo.c_str(), ios::binary); // abre arquivo binario para leitura
	for (int i = 0; i < tamanho_vetor; i++) 
	{
		input_file.read((char*) &vetor[i], sizeof(int)); // ler um inteiro do arquivo e guarda na posicao A[i]
	}
	input_file.close(); // fecha o arquivo de leitura){
}

int main(){
    // Os tamanhos dos vetores a serem testados estao guardados neste vetor 'tam'	
	// tamanhos reais para o projeto

	const int tam[] = {1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 
	                   11000, 12000, 13000, 14000, 15000, 16000, 17000, 18000, 19000, 
					   20000, 21000, 22000, 23000, 24000, 25000, 26000, 27000, 28000, 
					   29000, 30000, 31000, 32000, 33000, 34000, 35000, 36000, 37000, 
					   38000, 39000, 40000, 41000, 42000, 43000, 44000, 45000, 46000, 
					   47000, 48000, 49000, 50000, 51000, 52000, 53000, 54000, 55000, 
					   56000, 57000, 58000, 59000, 60000, 61000, 62000, 63000, 64000, 
					   65000, 66000, 67000, 68000, 69000, 70000, 71000, 72000, 73000, 
					   74000, 75000, 76000, 77000, 78000, 79000, 80000, 81000, 82000, 
					   83000, 84000, 85000, 86000, 87000, 88000, 89000, 90000, 91000, 
					   92000, 93000, 94000, 95000, 96000, 97000, 98000, 99000, 100000};

    const int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'0
    // como no projeto exemplo, os arquivos seram gerados aleatoriamente aqui na etapa 1
    gera_dados(TOTAL_N, tam);

	
	while(true){
		string entrada;
		cin >> entrada;
		if (entrada == "sair")
			break;
		else if(entrada == "bubblesort")
			executar(TOTAL_N, tam, "bubblesort", "bubblesort");
		else if (entrada == "selectionsort")
			executar(TOTAL_N, tam,"selectionsort", "selectionsort");
		else if(entrada == "insertionsort")
			executar(TOTAL_N, tam, "insertionsort", "insertionsort");
		else if(entrada == "mergesort")
			executar(TOTAL_N, tam, "mergesort", "mergesort");
		else if(entrada == "quicksort")
			executar(TOTAL_N, tam, "quicksort", "quicksort");
		else if(entrada == "radixsort")
			executar(TOTAL_N, tam, "radixsort", "radixsort");
		else 
			cout << "comando invalido" << endl;
	}

}