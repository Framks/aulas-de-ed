#include <iostream>
#include "ForwardList.h"

int main(){
    ForwardList lista;

    for (int i = 0; i < 8; i++)
    {
        lista.push_back(i);
    }
    lista.print();
}