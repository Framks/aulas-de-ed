#include <iostream>
#include <iomanip>
#include <limits>   
using namespace std;

int main()
{
    int num1 = 123456789;
    float num2 = 654.3216;
    double num3 = 357.654987321;
    bool num4 = true;
    cout << setprecision(2) << fixed << num2 << endl; // aqui esta um exemplo de como definir as casas decimais.
    cout << oct << num1 << endl;                      // aqui é um exemplo de como definir a saida de inteiro como octal
    cout << hex << num1 << endl;                      // aqui é um exemplo de hexadecimal
    cout << hex << showbase << num1 << endl;          // aqui é um exemplo de como colocar a base no hexa ou no octa = 0 para octal e 0x para hexa
    cout << scientific << num2 << endl;               // saida como notação cientifica
    cout << showpos << num2 << endl;                  // saida do positivo com o simbolo de positivo na frente / noshowpos para limpar a configuração
    cout << boolalpha << num4 << endl;                // boolalpha faz com que os numeros boleanos sejam impressos como true e false
    cout << setfill('0');
    cout << "/" << left << setw(20) << num1 << "/" << endl;
    cout << "/" << num1 << "/" << endl;
    cout << "/" << right << setw(20) << num1 << "/" << endl;

    int v;
    while (!cin.fail()){
        cin >> v;
        if(cin.fail()){
            cerr << "fail: enter a valid integer";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }else{
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << v;
        }
    }
    
}