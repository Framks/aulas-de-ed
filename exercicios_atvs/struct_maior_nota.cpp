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

void maior_nota(aluno a1, aluno a2)
{
    if (a1.nota == a2.nota)
    {
        cout << a1.nome << " e " << a2.nome << " , " << fixed << setprecision(1) << a1.nota << endl;
    }
    else if (a1.nota > a2.nota)
    {
        cout << a1.nome << " , " << fixed << setprecision(1) << a1.nota;
    }
    else
    {
        cout << a2.nome << " , " << fixed << setprecision(1) << a2.nota;
    }
}

int main()
{
    aluno a = ler_aluno();
    aluno b = ler_aluno();
    maior_nota(a, b);
}