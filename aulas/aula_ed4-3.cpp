/*
    ponteiro
        variavel que guarda indereço de memoria ou indereço de outra variavel
    ex.:
    x = 77;
    p = &x;

    x == 77
    p == 0xasdkf   // indereço da x
    *p = 1;        // assim eu mudo o valor da variavel não o ponteiro
    x == 1

*/

#include <iostream>
using namespace std;

void troca(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int main()
{
    int a,b;
    cout << "digite dois numeros para A e B, respctivamente: ";
    cin >> a >> b;
    troca(&a, &b);
    cout << "a:" << a << ", B: "<< b;
}