#include <iostream>
#include <string>
using namespace std;

int main(){
    //string str1("testando string"); // exemplo de como inicializar uma variavel do tipo std::string
    string id, nome;
    cout << "digite seu id: ";
    cin >> id;
    cin.ignore(); // este comando limpa o ultimo caracter do buffer
    cout << "digite seu nome: ";
    getline(cin,nome);
    cout << "nome: " << nome << ", id: " << id<< endl;
    /*      concatenação de string      */
    string a ("45");
    string b ("11");
    cout << a + b << endl;
    a += " volts";
    cout << a;
}