//------INSERTION SORT--------

#include <iostream>
#include <time.h>

using namespace std;

void insertionSort(int*);

const int N = 6;

int main() {
    int i;
    clock_t inizio,fine;
    double tempo;

    srand(time(NULL));

    //N = 1 + rand() % 10001;
    int A[N] = {5,2,4,6,1,3};

    /*for(i = 1; i <= N; i++) {
        A[i] = rand() % 65001;
    } */

    cout<<"Vettore A:               ";
    for(i = 0; i < N; i++) {
        cout<<A[i]<<"|";
    }
    cout<<endl;

    inizio = clock();
    insertionSort(A);
    fine = clock();

    tempo = ((double) (fine-inizio))/CLOCKS_PER_SEC;

    cout<<"Vettore A ordinato:      ";
    for(i = 0; i < N; i++) {
        cout<<A[i]<<"|";
    }
    cout<<endl;

    cout<<"T(n):                    "<<tempo<<endl;
    cout<<"DIM:                     "<<N<<endl;

    return 0;
}

void insertionSort(int* A) {
    int key;
    int i;

    for(int j = 1; j < N; j++) {
        key = A[j];
        i = j-1;
        while(i >= 0 && A[i] > key) {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
        /*
         * se ho 5 2 come primi 2 elementi, una volta che sposto il 5 al posto del 2, il
         * nella posizione 0 sta ancora la vecchia copia di 5, quindi ci metto
         * il nuovo valore 2
         */
    }
}