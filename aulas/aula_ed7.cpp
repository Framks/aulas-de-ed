/*
    Recursão e finalização do slide da aula passada

*/
/*
#include <iostream>
using namespace std;

int somatoria(int a) // Exemplo de função recursiva onde retorna a somatoria
{                    // de um inteiro mais o antecessor desse numero
    if (a != 1)
    {
        return a + somatoria(a - 1);
    }
    else
    {
        return a;
    }
}

int main()
{
    int a;
    cin >> a;
    cout << somatoria(a);
}
*/

#include <iostream>
using namespace std;
// função recursiva que retorna o maior elmento de um vetor.
int maxima(int v[], int n)
{
    if (n == 0)
    {
        return v[0];
    }
    else
    {
        int max = maxima(v, n - 1);
        if (max > v[n - 1])
        {
            return max;
        }
        else
        {
            return v[n - 1];
        }
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
    cout << maxima(v, n);
}
