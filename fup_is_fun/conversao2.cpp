#include <iostream>
using namespace std;

// função recursiva que imprime um valor convertido na base passada por parametro
void conversao_por_base(int valor, int base)
{

    if (valor < base)
    {
        if (valor >= 10)
        {
            char a = 'A' + (valor - 10);
            cout << a;
        }
        else
        {
            cout << valor;
        }
    }
    else
    {
        conversao_por_base(valor / base, base);
        int aux = valor % base;
        if (aux >= 10)
        {
            char a = 'A' + (aux - 10);
            cout << a;
        }
        else
        {
            cout << aux;
        }
    }
}

int main()
{
    int base, valor;
    cout << "digite o valor: ";
    cin >> valor;
    cout << "digite a base: ";
    cin >> base;
    cout << "O numero: " << valor << ", na base: " << base << ", e : ";
    conversao_por_base(valor, base);
}