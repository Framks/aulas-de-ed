#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int hexa_dec(string str, int tam)
{
    int result = 0;
    for (int i = 0; str[i]; i++)
    {
        if (str[i] == 'A')
        {
            result += 10 * pow(16, ((tam - 1) - i));
        }
        else if (str[i] == 'B')
        {
            result += 11 * pow(16, ((tam - 1) - i));
        }
        else if (str[i] == 'C')
        {
            result += 12 * pow(16, ((tam - 1) - i));
        }
        else if (str[i] == 'D')
        {
            result += 13 * pow(16, ((tam - 1) - i));
        }
        else if (str[i] == 'E')
        {
            result += 14 * pow(16, ((tam - 1) - i));
        }
        else if (str[i] == 'F')
        {
            result += 15 * pow(16, ((tam - 1) - i));
        }
        else
        {
            result += (str[i] - '0') * pow(16, ((tam - 1) - i));
        }
    }
    return result;
}

string dec_bin(int str)
{
    string saida;
    if (str < 2)
    {
        return "1";
    }
    else
    {
        saida = dec_bin(str / 2);
        if (str % 2)
        {
            saida += '1';
        }
        else
        {
            saida += '0';
        }
    }
    return saida;
}

int bin_dec(string str, int tam)
{
    int result = 0;
    for (int i = 0; str[i]; i++)
    {
        result += (str[i] - '0') * pow(2, ((tam - 1) - i));
    }
    return result;
}

string dec_hexa(int str)
{
    string saida;
    if (str < 16)
    {
        if (str == 15)
        {
            saida = 'F';
        }
        else if (str == 14)
        {
            saida = 'E';
        }
        else if (str == 13)
        {
            saida = 'D';
        }
        else if (str == 12)
        {
            saida = 'C';
        }
        else if (str == 11)
        {
            saida = 'B';
        }
        else if (str == 10)
        {
            saida = 'A';
        }
        else
        {
            saida = to_string(str);
        }
        return saida;
    }
    else
    {
        saida = dec_hexa(str / 16);
        int teste = str % 16;
        if (teste == 15)
        {
            saida += 'F';
        }
        else if (teste == 14)
        {
            saida += 'E';
        }
        else if (teste == 13)
        {
            saida += 'D';
        }
        else if (teste == 12)
        {
            saida += 'C';
        }
        else if (teste == 11)
        {
            saida += 'B';
        }
        else if (teste == 10)
        {
            saida += 'A';
        }
        else
        {
            saida += to_string(teste);
        }
        return saida;
    }
}

int main()
{
    int loop = 1;
    while (loop)
    {
        int tipo;
        cout << "conversao de tipos de saidas:" << endl;
        cout << "de hexa para decimal: 1 \nde decimal para binario: 2 \nde binario para decimal: 3 \nde hexadecimal para binario: 4 \nde binario para hexadecimal: 5\nde decimal para hexadecimal: 6" << endl;
        cin >> tipo;
        string entrada;
        cout << "digite o que vc quer converter: ";
        cin >> entrada;
        int num_entra = 0;

        switch (tipo)
        {
        case 1: // de hexadecimal para decimal
            cout << "seu numero em decimal e: " << hexa_dec(entrada, entrada.length()) << endl;
            cout << endl;
            break;
        case 2: // de decimal para binario
            for (int i = 0; entrada[i]; i++)
            {
                num_entra = num_entra * 10 + (entrada[i] - '0');
            }
            cout << dec_bin(num_entra) << endl;
            break;
        case 3: // de binario para decimal
            cout << bin_dec(entrada, entrada.length());
            cout << endl;
            break;
        case 4: // de hexadecimal para binario
            cout << dec_bin(hexa_dec(entrada, entrada.length())) << endl;
            break;
        case 5: // de bin para hexadecimal
            cout << dec_hexa(bin_dec(entrada, entrada.length())) << endl;
            break;
        case 6: // de decimal para hexadecimal
            for (int i = 0; entrada[i]; i++)
            {
                num_entra = (num_entra * 10) + (entrada[i] - '0');
            }
            cout << dec_hexa(num_entra) << endl;
            break;
        default:
            break;
        }
    }
}