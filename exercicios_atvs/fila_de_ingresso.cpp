#include <iostream>
#include <vector>

using namespace std;

// retorna um vetor com as pessoas que ficaram na fila
vector<int>* fila_de_ingresso(vector<int>& fila, vector<int>& fila_pessoa_sairam)
{
    vector<int>* retorno = new vector<int>();
    for (int i = 0; i < fila.size(); i++)
    {
        int aux = 0;
        for (int j = 0; j < fila_pessoa_sairam.size(); j++)
        {
            if (fila[i] == fila_pessoa_sairam[j])
            {
                aux = 1;
                break;
            }
        }
        if (aux == 0)
        {
            retorno->push_back(fila[i]);
        }
    }
    return retorno;
}

int main(){
    int quant_pessoas, quant_deixar_fila;
    cin >> quant_pessoas;
    vector<int> fila(quant_pessoas);
    for(int i = 0; i < quant_pessoas; i++){
        cin >> fila[i];
    }
    cin >> quant_deixar_fila;
    vector<int> fila_pessoa_sairam(quant_deixar_fila);
    for (int i = 0; i < quant_deixar_fila; i++)
    {
        cin >> fila_pessoa_sairam[i];
    }
    
    vector<int>* retorno = fila_de_ingresso(fila, fila_pessoa_sairam);
    for (int i = 0; i < retorno->size(); i++)
    {
        cout << retorno->at(i) << " ";
    }
    cout << endl;
}