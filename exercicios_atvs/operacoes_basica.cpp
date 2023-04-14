#include <sstream> //cabeçalho que contém o tipo de dado stringstream
#include <vector>  //cabeçalho que contém a estrutura de dados vector
#include <string>
#include <iostream>
using namespace std;

void imprimi(vector<int> vetor, int tam)
{
    for (int i = 0; i < tam - 1; i++)
    {
        cout << vetor[i] << " ";
    }
    cout << vetor[tam - 1];
}

vector<int> inverter(vector<int> vetor, int ini, int fim)
{
    if (ini >= fim)
    {
        return vetor;
    }
    else
    {
        vetor = inverter(vetor, ini + 1, fim - 1);
        int aux;
        aux = vetor[ini];
        vetor[ini] = vetor[fim - 1];
        vetor[fim - 1] = aux;
        return vetor;
    }
}

int soma(vector<int> vetor, int tam)
{
    if (tam == 1)
    {
        return vetor[0];
    }
    else
    {
        int som = soma(vetor, tam - 1);
        som = som + vetor[tam - 1];
        return som;
    }
}

long int mult(vector<int> vetor, int tam)
{
    if (tam == 1)
    {
        return vetor[0];
    }
    else
    {
        return mult(vetor, tam - 1) * vetor[tam - 1];
    }
}

int menor(vector<int> vetor, int tam)
{
    if (tam == 1)
    {
        return vetor[0];
    }
    else
    {
        int min = menor(vetor, tam - 1);
        if (min < vetor[tam - 1])
        {
            return min;
        }
        else
        {
            return vetor[tam - 1];
        }
    }
}

int main()
{
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> vet;
    int value;
    int count = 0;
    while (ss >> value)
    {
        vet.push_back(value);
        count++;
    }
    cout << "vet : [ ";
    imprimi(vet, count);
    cout << " ]" << endl;

    vet = inverter(vet, 0, count);

    cout << "rvet: [ ";
    imprimi(vet, count);
    cout << " ]" << endl;

    cout << "sum : " << soma(vet, count) << endl;

    cout << "mult: " << mult(vet, count) << endl;

    cout << "min : " << menor(vet, count) << endl;

    cout << "inv : [ ";
    imprimi(vet, count);
    cout << " ]" << endl;
}