#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
    Queue<int> fila;

    fila.push(1);
    fila.push(2);
    fila.push(5);
    Queue<int> fila2(fila);
    while (!fila.empty())
    {
        cout << fila.front() << endl;
        fila.pop();
    }
    while (!fila.empty())
    {
        cout << fila2.front() << endl;
        fila.pop();
    }
    
}