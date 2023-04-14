#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <cctype>
using namespace std;

int main()
{
    string entrad;
    string resultado;
    char testar[20];
    stringstream bff;
    getline(cin, entrad);
    bff << entrad;
    while (bff >> testar)
    {
        int integer_test = 1;
        for (int i = 0; testar[i]; i++)
        {
            if (islower(testar[i]) || isupper(testar[i]))
            {
                integer_test = 0;
                resultado += "str ";
                break;
            }
        }
        for (int i = 0; testar[i]; i++)
        {
            if (testar[i] == '.')
            {
                integer_test = 0;
                resultado += "float ";
                break;
            }
        }

        if (integer_test)
        {
            resultado += "int ";
        }
    }
    resultado.pop_back();
    cout << resultado;
}