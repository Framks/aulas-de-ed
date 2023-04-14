#include <iostream>
using namespace std;
int main(){
    int nl, nc, sold = 0;
    cin >> nl >> nc;
    int vet[nl][nc];
    for (int i = 0; i < nl; i++){
        for (int j = 0; j < nc; j++){
            cin >> vet[i][j];
        }
    }
    for(int i=nc-1;i>=0;i--){
        for(int j=nl-1;j>0;j--){
            if(vet[j][i]<vet[j-1][i]){
                sold += 1;
            }
        }
    }
    cout << sold;
}