#include <iostream>
#include <string>

using namespace std;

int main()
{
    int loop = 1;
    while (loop)
    {
        int tipo;
        cout << "conversao de hexa para decimal: 1 \n de decimal para binario: 2 \n de binario para decimal: 3 \n de hexadecimal para binario: 4 \n de binario para hexadecimal: 5" << endl;
        cin >> tipo;
        string entrada;
        cout << "digite o que vc quer converter: ";
        switch (tipo)
        {
        case 1: // de hexa para decimal

            break;
        case 2: // de decimal para binario

            break;
        case 3: // de binario para decimal
            break;
        case 4: // de hexa para bin
            break;
        case 5: // de bin para hexa
            break;
        default:
            break;
        }
    }
}