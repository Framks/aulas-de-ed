#include <iostream>
#include <string>
using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
    if (n == 0)
    {
        if (str[n] == c)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int soma = contaCaracteres(str, n - 1, c);
        if (str[n] == c)
        {
            return soma + 1;
        }
        else
        {
            return soma;
        }
    }
}

int main()
{
    string frase;
    char a;
    getline(cin, frase);
    cin >> a;
    int i = 0, n = 0;
    while (frase[i] != 0)
    {
        n++;
        i++;
    }
    cout << contaCaracteres(frase, n, a);
}