#include <iostream>

using namespace std;

int max_partecipants = 3;

void draw_is_possible(int* vet);
int find_max(int *vet, int &indice);
void swap(int *vet, int a, int b);

int main() {
    int numero_casi_test = 0;
    int vet[max_partecipants];

    cin >> numero_casi_test;
    while(numero_casi_test--){
        for(int & i : vet)
            cin >> i;
        draw_is_possible(vet);
    }
    return 0;
}

void draw_is_possible(int* vet){
    bool superato = false;
    int indice = 0;
    int sum = 0;
    int massimo = find_max(vet, indice); // O(n)
    swap(vet, 0, indice);

    for(int i=1; i<max_partecipants && !superato ; i++) {
        sum += vet[i];
        if(sum > massimo)
            superato = true;
    }
    if(sum == massimo)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
} // complessita O(n)

int find_max(int *vet, int &indice){
    int massimo = INT32_MIN;
    for(int i=0; i<max_partecipants; i++)
        if(vet[i]>massimo) {
            indice = i;
            massimo = vet[i];
        }
    return massimo;
}

void swap(int *vet, int a, int b){
    int temp;
    temp = vet[a];
    vet[a] = vet[b];
    vet[b] = temp;
}
