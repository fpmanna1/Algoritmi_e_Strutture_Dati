//-------RADIX SORT-----

#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
int N;

void CountingSort(int*,int*,int);
void radixSort(int*,int*,int,int);

int main() {

    clock_t start, end;
    double timer = 0;

    srand(time(NULL));
    N = 1 + rand() % 1043367;
    //N = 1043368;

    int vet[N];

    int i;
    int m = 0;

    cout<<"VETTORE A:           ";
    for(i = 1; i <= N; i++){
        vet[i] = 1000 + rand() % 8998;
        cout<<vet[i]<<"|";
        if(vet[i] > m){
            m = vet[i];
        }

    }

    int B[N];
    start = clock();
    radixSort(vet,B,4,m);
    end = clock();

    timer = ((double)(end-start))/CLOCKS_PER_SEC;

    cout<<endl;

    cout<<"VETTORE A ORDINATO:  ";
    for(i = 1; i<=N; i++){
        cout<<B[i]<<"|";
    }
    cout<<endl;
    cout<<"T(n):                "<<timer<<endl;
    cout<<"DIM:                 "<<N<<endl;
    return 0;
}


void CountingSort(int *vet, int *B, int m) {
    int i;
    int C[m+1];

    for(i = 0; i <= m; i++){
        C[i] = 0;
    }

    for(i = 1; i <= N; i++) {
        C[vet[i]] = C[vet[i]] + 1;
    }

    for(i = 1; i <= m; i++){
        C[i] = C[i] + C[i-1];

    }

    for(i = N; i>0; i--) {
        B[C[vet[i]]] = vet[i];
        C[vet[i]] = C[vet[i]] - 1;
    }

}

void radixSort(int *vet, int* B, int d, int m){
    for(int i = 1; i <= d; i++){
        CountingSort(vet,B,m);
    }
}