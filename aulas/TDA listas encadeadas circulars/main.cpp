#include <iostream>
#include "CircularList.h"
using namespace std;

void print(CircularList& lst) {
    for(int i = 0; i < lst.size(); ++i)
        cout << lst[i] << " ";
    cout << endl;
}

int main() {
    CircularList lst;
    
    for(int i = 1; i <= 9; ++i) 
        lst.push_back(i);

    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (int val : lst)
    {
        cout << val << " ";
    }
    cout << endl;
    
    
}