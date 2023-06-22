#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

int main(){
    int interacoes;
    cin >> interacoes;
    cin.ignore();
    Queue fila = Queue();
    for (int i = 0; i < interacoes; i++){
        string teste;
        
        getline(cin, teste);
        stringstream ss(teste);
        int comando, value;
        ss >> comando;
        if (comando == 1)
        {
            ss >> value;
            fila.add(value);
        }else if(comando == 2){
            fila.remove();
        }else if (comando == 3){
            cout << fila.front() << endl;
        }
        cout << " esta é a interação: " << i << endl;
    }
}