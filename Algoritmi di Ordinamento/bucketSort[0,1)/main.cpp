//-----BUCKET SORT-----

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <math.h>
#include <iterator>

using namespace std;

void BucketSort(float *);
void printList(list<float> L);

int N;

int main() {

    clock_t inizio,fine;
    double tempo;

    srand(time(NULL));
    N = 0;


    N = 1 + rand() % 10;

    float A[N];

    int i;
    cout<<"Vettore A:           ";
    for(i = 0; i < N; i++){
        A[i] = (rand() % 65000);
        A[i] = A[i]/65000;
        cout<<A[i]<<"|";
    }
    cout<<endl;

    inizio = clock();
    BucketSort(A);
    fine = clock();

    cout<<"VETTORE A ORDINATO:  ";
    for(i = 0; i < N; i++){
        cout<<A[i]<<"|";
    }
    cout<<endl;

    tempo = ((double)(fine-inizio))/CLOCKS_PER_SEC;

    cout<<"T(n):                "<<tempo<<endl;
    cout<<"DIM:                 "<<N<<endl;

    return 0;
}



void BucketSort(float *A){
    int i;
    int indice;

    list<float> L[N];
    //cout<<"NUMERO ELEM. VETTORE: "<<N<<endl;

    for(i = 0; i < N; i++){
        indice = trunc(N*A[i]); //varia questa cosina
        L[indice].push_back(A[i]);
    }

    for(i = 0; i < N; i++){
        L[i].sort();
        /*cout<<"LISTA: "<<i<<endl;
        printList(L[i]);
        cout<<endl;*/
    }

    int id = 0;


    for(i = 0; i < N; i++) {
        while(L[i].empty() != 1) {
            A[id] = L[i].front();
            L[i].pop_front();
            id++;
        }
    }
}

void printList(list<float> L) {
    if (L.empty()) {
        //cout <<"LISTA VUOTA"<<endl;
        return;
    } else {
        ostream_iterator<float> output(cout, " | ");
        copy(L.cbegin(),L.cend(), output);
        return;
    }
}