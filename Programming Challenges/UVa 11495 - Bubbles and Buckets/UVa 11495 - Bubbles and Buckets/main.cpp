#include <iostream>

using namespace std;

void winner_choice(int *vet, int size);
void swap(int *vet, int size, int a, int b);

int main() {

    int lunghezza_sequenza = 0;
    cin >> lunghezza_sequenza;

    while(lunghezza_sequenza!=0){
        int vet[lunghezza_sequenza];

        for(int i=0; i<lunghezza_sequenza; i++)
            cin >> vet[i];

        winner_choice(vet, lunghezza_sequenza);

        cin >> lunghezza_sequenza;
    }

    return 0;
}

void winner_choice(int *vet, int size){
    int swaps = 0;
    for(int i=0; i < size-1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                swap(vet, size, j, j + 1);
                swaps++;
            }
        }
    }

    cout << "NUMERO DI SWAP  : " << swaps << endl;

    if(swaps % 2 == 0)
        cout << "Carlos" << endl;
    else
        cout << "Marcelo" << endl;
} // COMPLESSITA O(n^2)

void print(int *vet, int size){
    for(int i=0; i<size; i++)
        cout << vet[i] << " ";
}

void swap(int *vet, int size, int a, int b){
    int temp;
    temp = vet[a];
    vet[a] = vet[b];
    vet[b] = temp;
}
