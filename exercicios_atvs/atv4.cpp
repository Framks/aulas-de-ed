#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;

string maiuscula(string str)
{
    int i = 0;
    while (str[i] != 0)
    {
        str[i] = toupper(str[i]);
        i++;
    }
    return str;
}

string minuscula(string str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}

string inverter(string str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (isupper(str[i]))
        {
            str[i] = tolower(str[i]);
        }
        else
        {
            str[i] = toupper(str[i]);
        }
    }
    return str;
}

string primeiro(string str)
{
    string resultado;
    string test;
    stringstream frase, result;
    frase << str;
    while (frase >> test)
    {
        if (test.size() != 1)
        {
            test[0] = toupper(test[0]);
        }else{
            test[0] = tolower(test[0]);
        }
        resultado += test + " ";
    }
    resultado.pop_back();
    return resultado;
}

int main()
{
    char letra;
    string frase;
    getline(cin, frase);
    cin >> letra;
    switch (letra)
    {
    case 'M':
        cout << maiuscula(frase);
        break;

    case 'm':
        cout << minuscula(frase);
        break;

    case 'p':
        cout << primeiro(frase);
        break;

    case 'i':
        cout << inverter(frase);
        break;
    }
}