#include <iostream>
using namespace std;

int main()
{
    int test = 0;
    int num;
    cin >> num;
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            test += 1;
        }
    }
    if (test > 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << 1 << endl;
    }
}
