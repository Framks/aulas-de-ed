#include <iostream>
#include "Tree.h"
using namespace std;

int main(){
    Tree<int> t1("3 4 6 # # 7 # # 5 # #");
    cout << t1.serialize();
}