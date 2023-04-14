#include <iostream>
using namespace std;

int main()
{
    int vet[3][3], tes = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> vet[i][j];
        }
    }
    int diag = vet[0][0] + vet[1][1] + vet[2][2];
    int diag2 = vet[0][2] + vet[1][1] + vet[2][0];

    for (int i = 0; i < 3; i++)
    {
        int li = 0;
        for (int j = 0; j < 3; j++)
        {
            li = vet[i][j] + li;
        }
        int colu = 0;
        for (int j = 0; j < 3; j++)
        {
            colu = vet[j][i] + colu;
        }
        if ((diag2 != diag) || (diag2 != li) || (diag2 != colu) || (diag != li) || (diag != colu) || (li != colu))
        {
            cout << "nao";
            tes = 1;
            break;
        }
    }
    if (tes == 0)
    {
        cout << "sim";
    }
}