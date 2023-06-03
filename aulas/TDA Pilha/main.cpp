#include <iostream>
#include <sstream>
#include <vector>
#include "Stack.h"
using namespace std;

int main(){
    Stack<string> pilha;
    string input, palavra;
    cout << "digite uma lista de nomes: ";
    getline(cin, input);
    stringstream ss {input};
    while (ss >> palavra)
    {
        pilha.push(palavra);
    }

    while (!pilha.empty())
    {
        cout << pilha.top() << endl;
        pilha.pop();
    }
    
}