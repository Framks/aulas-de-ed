#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct aluno
{
    int matricula;
    string nome;
    string disciplina;
    double nota;
};

aluno ler_aluno()
{
    aluno a1;
    getline(cin, a1.nome);
    cin >> a1.matricula;
    cin.ignore();
    getline(cin, a1.disciplina);
    cin >> a1.nota;
    cin.ignore();
    return a1;
}

void ver_nota(aluno a1)
{
    if (a1.nota >= 7.0)
    {
        cout << a1.nome << " aprovado(a) em " << a1.disciplina << endl;
    }
    else
    {
        cout << a1.nome << " reprovado(a) em " << a1.disciplina << endl;
    }
}

int main()
{
    aluno a = ler_aluno(); // teste
    ver_nota(a);    // teste
    cout << endl; // teste
}