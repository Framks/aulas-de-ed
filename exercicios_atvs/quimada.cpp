#include <iostream>
#include <string>
using namespace std;

void show(string *mat, int nl) // esta função imprime a matriz na tela
{
    for (int l = 0; l < nl; l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(int nl, int nc, string *mat, int l, int c) // esta funão faz com que a "queimada aconteça"
{
}

int main()
{
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    cin >> nl >> nc >> lfire >> cfire;
    string *mat = new string[nl];
    for (int l = 0; l < nl; l++)
    {
        string line;
        cin >> line;
        mat[l] = line;
    }
    tocar_fogo(nl, nc, mat, lfire, cfire);
    show(mat, nl);
    delete[] mat;
}