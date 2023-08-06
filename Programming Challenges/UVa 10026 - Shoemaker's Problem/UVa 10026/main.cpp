#include <iostream>
#include <cmath>

struct lavoro{
    int tempo;
    int penale;
    double rapporto;
    int indice;
};

using namespace std;

void find_min_cost(lavoro *vet, int num_lavori);
void mergeSort(lavoro* A, int p, int r);
void merge(lavoro* A, int p, int q, int r);

int main() {

    int numero_casi_test= 0;
    int numero_lavori = 0;

    cin >> numero_casi_test;
    cout << endl;
    while(numero_casi_test--){
        cin >> numero_lavori;

        lavoro vet[numero_lavori];

        for(int i=0; i<numero_lavori; i++){
            cin >> vet[i].tempo >> vet[i].penale;
            vet[i].indice = i+1;
            vet[i].rapporto = (double)vet[i].tempo/vet[i].penale;
        }

        find_min_cost(vet, numero_lavori);
        cout << endl;
    }

    return 0;
}

void find_min_cost(lavoro *vet, int num_lavori){
    mergeSort(vet, 0, num_lavori-1);
    for(int i=0; i<num_lavori; i++)
        cout << vet[i].indice << " ";

} // COMPLESSITA' : O(n log n)

void mergeSort(lavoro* A, int p, int r) {
    // p: inizio vettore
    // r: fine vettore

    int q; // elemento centrale
    q = trunc((p+r)/2); // sarebbe il floor
    if(p < r) { // se non ho 0 elementi o 1 elemento

        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

void merge(lavoro* A, int p, int q, int r) {
    //definisco le dimensioni dei due array
    int n1 = q - p + 1; // da elemento iniziale a pivot
    int n2 = r - q; // da pivot a elemento finale
    int inf = 65000; //elemento maggiore di qualunque elemento della sequenza
    int j, i;

    //creo gli array
    lavoro L[n1+1];
    lavoro R[n2+1];

    //Riempio il vettore L
    for(i = 1; i <= n1; i++) {
        L[i] = A[p+i-1];
    }
    L[n1+1].rapporto = inf; // sentinella: cosi' non gestisco il caso di fine vettore

    //cout<<endl;
    //Riempio il vettore R
    for(j = 1; j <= n2; j++){
        R[j] = A[q+j];
    }
    R[n2+1].rapporto = inf; // sentinella: cosi' non gestisco il caso di fine vettore

    i = 1;
    j = 1;
    for(int k = p; k <= r; k++) {
        if(L[i].rapporto <= R[j].rapporto) {
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
