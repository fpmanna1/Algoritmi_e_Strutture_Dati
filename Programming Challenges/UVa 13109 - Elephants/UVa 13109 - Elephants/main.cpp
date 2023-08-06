#include <iostream>
#include <algorithm>

using namespace std;

int largest_number(int *vet, int size, int capacity){
    int sum = 0;
    int i=0;
    sort(vet, vet + size);
    while(sum <= capacity){
        sum += vet[i];
        i++;
    }

    return i-1;
}

int main() {

    int t;
    int num_elephants;
    int max_weight;

    cin >> t;
    while(t--){
        cin >> num_elephants;
        cin >> max_weight;
        int vet[num_elephants];

        for(int i=0; i<num_elephants; i++){
            cin >> vet[i];
        }

        cout << largest_number(vet, num_elephants, max_weight) << endl;
    }
    return 0;
}
