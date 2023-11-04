#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

// ordena um vetor a[l..r] com índice inicial l
// e indice final r, contendo r-l+1 elementos
// complexidade: O(n^2)
void selectionsort(int a[], int l, int r){
    for(int i = l; i < r; i++){
        int indexmin = i;
        for(int j = i+1; j < r; j++)
            if(a[j] < a[indexmin])
                indexmin = j;
        int temp = a[i];
        a[i] = a[indexmin];
        a[indexmin] = temp;
    }
}

void bubblesort(int a[], int l, int r){
    for(int i = l; i < r; i++){
       for (int j = r; j > i; j--)
       {
           if (a[j] < a[j - 1])
           {
               swap(a[j], a[j - 1]);
           }
       }
    }
}

void print(int a[] , int TAM){
    for(int i = 0; i < TAM; i++)
        cout << a[i] << " ";
    cout << endl;
}

void merge(int a[], int p, int q, int r){
    int *aux = new int[r - p + 1];
    int i = p, j = q + 1, k = 0;

    while(i <= q && j <= r){
        if(a[i] <= a[j])
            aux[k++] = a[i++];
        else
            aux[k++] = a[j++];
    }

    while(i <= q)
        aux[k++] = a[i++];
    while(j <= r)
        aux[k++] = a[j++];
    for(int i = 0; i < r - p + 1; i++)
        a[p + i] = aux[i];
    delete[] aux;
}

void mergesort(int a[], int p, int r){
    if(p < r){
        int q = (p+r)/2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        merge(a, p, q, r);
    }

}

void insertionsort(int a[], int l, int r){
    for (int i = l+1; i < r; i++)
    {
        int key = a[i];
        int j = i-1;
        while ( j >= l && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void heapsort(int a[], int n){
    
}

void testa_algoritmo(int vec[], int l, int r,void (*f)(int[], int, int)){
    auto start = chrono::steady_clock::now();
    f(vec, l, r);
    auto end = chrono::steady_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "tempo: " << duration.count() << endl;
}


int main(){
    srand(time(NULL));
    int tam = 10000;
    int a[tam];
    for(int i = 0; i < tam; i++)
        a[i] = rand() % 10000;
    //print(a, tam);
    testa_algoritmo(a, 0, tam-1, mergesort);
    //print(a, tam);
}
