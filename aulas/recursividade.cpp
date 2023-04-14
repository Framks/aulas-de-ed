#include <iostream>
using namespace std;

/*
    função recursiva que retorna a soma de todos os elementos de um vetor
*/

int soma(int v[], int n)
{
    if (n == 1)
    {
        return v[0];
    }
    else
    {
        return v[n - 1] + soma(v, n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << soma(v, n);
}