//--------COUNTING SORT--------

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int N = 8; // dimensione del vettore da ordinare

void CountingSort(int *, int *, int);

int main() {

    clock_t start, end;
    double timer = 0;

    srand(time(NULL));
    //N = 1 + rand() % 10001;

    //int vet[N] = {2,5,3,0,2,3,0,3}; // array da ordinare
    int vet[N] = { 3, 4, 5, 0, 3, 2, 1, 0};
    int B[N]; // array ordinato

    int i;
    int k = 5;

    cout<<"VETTORE A:           ";
    /*for(i = 1; i <= N; i++){
        vet[i] = rand() % (k + 1);
        cout<<vet[i]<<"|";
    } */

    for(i = 0; i < N; i++){
        //vet[i] = rand() % (k + 1);
        cout<<vet[i]<<"|";
    }

    start = clock();
    CountingSort(vet,B,k);
    end = clock();

    timer = ((double)(end-start))/CLOCKS_PER_SEC;

    cout<<endl;

    cout<<"VETTORE A ORDINATO:  ";
    for(i = 0; i<N; i++){
        cout<<B[i]<<"|";
    }

    cout<<endl;
    cout<<"T(n):                "<<timer<<endl;
    cout<<"DIM:                 "<<N<<endl;
    return 0;
}


void CountingSort(int *vet, int *B, int m) {
    // int *vet = vettore da ordinare.
    // int *B = vettore che mantiene i valori ordinati.
    // m = i numeri presenti nel vettore da ordinare sono compresi tra 0 e m (k).
    int i;
    int C[m+1]; // vettore che indica le occorrenze di ciascun valore compreso tra 0 e k
    // il +1 è per considerare anche lo 0


    for(i = 0; i <= m; i++){
        C[i] = 0; // inizializzazione
    }

    for(i = 0; i < N; i++) { // N = dim. vettore da ordinare
        C[vet[i]] = C[vet[i]] + 1; // conto numero occorrenze
    }

    for(i = 1; i <= m; i++){
        C[i] = C[i] + C[i-1]; // conto numero elementi <= all'elemento i-esimo
    }

    for(i = N-1; i>=0; i--) {
        B[C[vet[i]] - 1] = vet[i];
        C[vet[i]] = C[vet[i]] - 1;
    }
}

