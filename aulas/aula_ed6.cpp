/*
    aula de Estrutura de dados 03/04
    alocação dinâmica de memória.
    pagina 229 à
*/

// atividade em aula-

#include <iostream>
using namespace std;

void preencherArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
}

void imprimeArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << endl;
    }
}

void main()
{
    int n;
    cin >> n;
    int *ponteiro = new int[n];
    preencherArray(ponteiro, n);
    imprimeArray(ponteiro, n);
    delete[] ponteiro;
}

/*
    ver depois como fuciona: tratamento de exceções
    try{
        int *v = new int[i];
    }
    catch(bad_alloc e){
        cout << "não foi possivel alocar: " << e.what() << endl;
    }
*/

/*
    atividade para casa pagina 269:

*/