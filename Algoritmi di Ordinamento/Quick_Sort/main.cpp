//-------QUICKSORT-------

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Partition(int*,int,int);
void swap(int*,int,int);
void QuickSort(int*,int,int);

const int N = 10;

int main() {

    srand(time(NULL));

    int k = 10; // range numeri nel vettore, 0,....,k
    int vet[N];
    int i;

    cout<<"Vettore A:           ";
    for(i = 0; i<N; i++){
        vet[i] = rand() % (k + 1);
        cout<<vet[i]<<" ";
    }

    cout<<endl;
    QuickSort(vet,0,N-1);

    cout<<"VETTORE ORDINATO:    ";
    for(i = 0; i<N; i++){
        cout<<vet[i]<<" ";
    }
    return 0;
}

int Partition(int* A, int p, int r){
    int pivot = A[r];
    int i = p-1;

    int j;

    for(j = p; j < r; j++){
        if(A[j] <= pivot) {
            i++;
            swap(A, i, j);
        }
    }

    swap(A,i+1,r);
    return i+1;
}

void QuickSort(int* A, int p, int r){
    if(p<r){
        int indice = Partition(A,p,r);
        QuickSort(A,p,indice-1);
        QuickSort(A,indice+1,r);
    }
}
void swap(int* A, int p, int r) {
    int temp;
    temp = A[p];
    A[p] = A[r];
    A[r] = temp;
}
