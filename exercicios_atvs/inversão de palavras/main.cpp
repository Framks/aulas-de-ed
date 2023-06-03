#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

void inverte_palavras(string& palavra){
    string input;
    stringstream buf {palavra};
    while (buf >> input)
    {
        stack<char> pilha;
        pilha.push(' ');
        for (int i = 0; i < input.length(); i++)
        {
            pilha.push(input[i]);
        }
        while (!pilha.empty())
        {
            cout << pilha.top();
            pilha.pop();
        }
    }
    
}

int main(){
    string sentenca {"AMU MEGASNEM ATERCES"};
    inverte_palavras(sentenca);
}