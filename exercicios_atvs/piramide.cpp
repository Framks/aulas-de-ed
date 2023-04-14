#include <iostream>
using namespace std;

void vetor(int ve[], int n)
{
    if (n == 1)
    {
        cout << "[" << ve[n - 1] << "]" << endl;
    }
    else
    {
        int so[n - 1];
        for (int i = 0; i <= n - 1; i++)
        {
            so[i] = ve[i + 1] + ve[i];
        }
        vetor(so, n - 1);
        cout << "[";
        for (int i = 0; i < n - 1; i++)
        {
            cout << ve[i] << ", ";
        }
        cout << ve[n - 1] << "]" << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int vet[n];
    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }
    vetor(vet, n);
}