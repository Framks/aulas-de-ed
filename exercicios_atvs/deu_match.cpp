#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>


using namespace std;

// função que retorna um vetor de inteiros que representa a 
// frequencia com que o vetor de busca aparece
// no vetor de entrada
vector<int> matchString(vector<string>& entradas, vector<string>& busca) {
    vector<int> resultado(busca.size());

    for (int i = 0; i < busca.size(); i++){
        resultado[i] = 0;
        for (int j = 0; j < entradas.size(); j++){
            if (entradas[j] == busca[i]){
                resultado[i]++;
            }
        }
    }
    return resultado;
}

int main() {
    // este primeiro bloco de comandos estão todos funcionando
    int tamanho;
    cin >> tamanho;
    vector<string> entradas;
    string aux;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, aux);
    stringstream bff;
    bff << aux;
    while (bff >> aux)
    {
        entradas.push_back(aux);
    }

    // este segundo bloco não esta funcionando
    cin >> tamanho;
    stringstream bff2;
    vector<string> busca;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, aux);
    bff2 << aux;
    while (bff2 >> aux)
    {
        busca.push_back(aux);
    }
    vector<int> resultado = matchString(entradas, busca);
    for (int i = 0; i < resultado.size(); i++)
    {
        cout << resultado[i];
        if (i != resultado.size() - 1)
            cout << " ";     

    }
    cout << endl;
}