#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

int main(){
    // strcpy(char *destino, const char *origem);
    string str;
    int com = 0;
    stringstream ss;
    char tes[20],ant[20] = "a";
    getline(cin, str);
    ss << str;
    while(ss >> tes){
        if(strcmp(ant,tes) > 0){
            cout << "nao";
            com = 0;
            break;
        }else{
            com = 1;
        }
        strcpy(ant,tes);
        cout << ant << endl;
    }
    if(com){
        cout << "sim";
    }
}