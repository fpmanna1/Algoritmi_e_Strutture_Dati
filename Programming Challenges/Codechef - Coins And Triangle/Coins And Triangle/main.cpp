#include <iostream>

using namespace std;

int max_height(int coins);
int sum_prec(int num);

int main() {

    int coins = 0;
    int numero_casi_test = 0;

    cin >> numero_casi_test;
    while(numero_casi_test--){
        cin >> coins;
        max_height(coins);
    }
    return 0;
}

int max_height(int coins){
    int max_coins_per_level = 0;
    int i = 1;

    while(max_coins_per_level <= coins) {
        // max_coins_per_level = sum_prec(i++);
        max_coins_per_level = (i * (i + 1) / 2);
        i++;
    }

    cout << "Numero coins necessarie per altezza "<<i-1 << " -> " << max_coins_per_level << endl;
    cout << "Altezza max raggiungibile con "<<coins<<" coins -> " << i-2 << endl;

    return i-2;
} // COMPLESSITA' O(h+1)

int sum_prec(int num){ // somma dei primi num termini
    return (num*(num+1)) / 2;
}