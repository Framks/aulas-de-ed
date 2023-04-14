#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

struct aluno
{
    int matricula;
    string nome;
    double media;
};

aluno ler_aluno()
{
    aluno a1;
    cin >> a1.matricula;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, a1.nome);
    cin >> a1.media;
    return a1;
}

void encontrar(aluno vet[], int tamanho, int matricula)
{
    int nao_encontrado = 1;
    for (int i = 0; i < tamanho; i++)
    {
        if (vet[i].matricula == matricula)
        {
            nao_encontrado = 0;
            cout << vet[i].nome << endl;
            cout << fixed << setprecision(1) << vet[i].media << endl;
            break;
        }
    }

    if (nao_encontrado)
    {
        cout << "NAO ENCONTRADA" << endl;
    }
}

int main()
{
    int tam_vetor, matricula;
    cin >> tam_vetor;
    aluno vet[tam_vetor];
    for (int i = 0; i < tam_vetor; i++)
    {
        vet[i] = ler_aluno();
    }
    cin >> matricula;
    encontrar(vet, tam_vetor, matricula);
}