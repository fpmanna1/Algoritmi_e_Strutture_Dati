//-------MERGE SORT------

#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

void merge(int*,int,int,int);
void mergeSort(int*,int,int);
const int N = 10;
int main() {
    int i = 20;

    int k = 10;

    srand(i);
    int A[N];

    for(int i = 0; i < N; i++) {
        A[i] = rand() % (k + 1);
    }

    cout << "Vettore A:          ";
    for(int i=0; i<N; i++)
        cout << A[i] << "|";

    mergeSort(A,0,N-1);

    cout<<endl<<"Vettore A ordinato: ";
    for(int k = 0; k < N; k++) {
        cout<<A[k]<<"|";
        }
    cout<<endl;

    return 0;
}

void mergeSort(int* A, int p, int r) {
    // p: inizio vettore
    // r: fine vettore

    int q; // elemento centrale
    q = trunc((p+r)/2); // sarebbe il floor
    if(p < r) { // se non ho 0 elementi o 1 elemento

        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
    //merge(A,p,q,r);
}

void merge(int* A, int p, int q, int r) {
    //definisco le dimensioni dei due array
    int n1 = q - p + 1; // da elemento iniziale a pivot
    int n2 = r - q; // da pivot a elemento finale
    int inf = 65000; //elemento maggiore di qualunque elemento della sequenza
    int j, i;

    //creo gli array
    int L[n1+1];
    int R[n2+1];

    //Riempio il vettore L
    for(i = 1; i <= n1; i++) {
        L[i] = A[p+i-1];
    }
    L[n1+1] = inf; // sentinella: cosi' non gestisco il caso di fine vettore

    //cout<<endl;
    //Riempio il vettore R
    for(j = 1; j <= n2; j++){
        R[j] = A[q+j];
    }
    R[n2+1] = inf; // sentinella: cosi' non gestisco il caso di fine vettore

    i = 1;
    j = 1;
    for(int k = p; k <= r; k++) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    // funziona perche' parto dal presupposto che i vettori L ed R
    // sono ordinati
}

