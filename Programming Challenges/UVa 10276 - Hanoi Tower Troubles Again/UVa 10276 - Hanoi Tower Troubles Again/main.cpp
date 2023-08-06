#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int value = 0;

void print(int *vet, int size){
    for(int i=0; i<size; i++)
        cout << vet[i] << " ";
    cout << endl;
}

bool isSquareNumber(int n){

    double sq = sqrt(n);
    int sq_int = (int)sq;

    if(sq_int * sq_int == n)
        return true;
    else
        return false;
}

int hanoi_tower(int *vet, int num_pegs, int ball){

    for(int j=0; j<num_pegs; j++){
        if(isSquareNumber(vet[j] + ball) || vet[j] == 0){
            vet[j] = value = ball;
            hanoi_tower(vet, num_pegs, ++ball);
            return value;
        }
    }
}

int main() {

    int t;
    cin >> t;

    while(t--){
        int pegs;
        cin >> pegs;
        int vet[pegs];
        for(int i=0; i<pegs; i++)
            vet[i] = 0;
        cout << hanoi_tower(vet, pegs, 1) << endl;
    }

    return 0;
}
