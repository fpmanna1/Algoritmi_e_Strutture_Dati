#include <iostream>

using namespace std;


int ways_to_pay(long long int price);
void init(long long int *vet, int size);
void find_possible_coins(long long int *vet, int size, long long int price);
void print(long long int *vet, int size);
bool isPrime(long long int n);

int main() {
    long long int price = 1;
    int i=1;

    while(price!=0){
        cin >> price;
        cout << "Case "<<i++<<": "<<ways_to_pay(price)<<endl;
    }

    return 0;
}

int ways_to_pay(long long int price){
    int ways = 0;
    int size = price/2;
    long  long int possible_coins[size];
    init(possible_coins, size);
    find_possible_coins(possible_coins, size, price);

    print(possible_coins, size);

    for(int i=0; i<size; i++)
        for(int j=i+1; j<size; j++){
            if(possible_coins[i] + possible_coins[j] <= price && possible_coins[j] != 0){
                cout << possible_coins[i] << "+" << possible_coins[j] << endl;
                ways++;
            }

        }
    return ways;
} // COMPLESSITA O(n^2)

void init(long long int *vet, int size){
    for(int i=0; i<size; i++)
        vet[i] = 0;
}

void find_possible_coins(long long int *vet, int size, long long int price){
    /*
     * mi restituisce tutte le possibili monete utilizzabili per
     * pagare la somma price. Devono essere numeri primi, poichè ad esempio
     * 15 può essere ottenuto come 5 + 5 + 5, 9 come 3 + 3 + 3 ecc..
     */
    vet[0] = 2;
    int k;
    for(int i=2, k=1; i<price-1; i++){
        if(i % 2 != 0 ){ // se il numero è dispari
            if(isPrime(i)) {
                vet[k] = i;
                k++;
            }
        }
    } // COMPLESSITA O(n^2)
}

void print(long long int *vet, int size){
    for(int i=0; i<size; i++)
        cout << vet[i] << " ";
    cout << endl;
}

bool isPrime(long long int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0) // se il numero è divisibile con almeno uno dei suoi precedenti ritorna falso
            return false;

    return true;
}


