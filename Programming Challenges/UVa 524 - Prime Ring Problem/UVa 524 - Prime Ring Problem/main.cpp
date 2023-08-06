#include <iostream>

using namespace std;


void print(int *vet, int size){
    for(int i=0; i<size; i++)
        cout << vet[i] << " ";
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i < n; i++)
        if (n % i == 0) // se il numero è divisibile con almeno uno dei suoi precedenti ritorna falso
            return false;

    return true;
}

void backtrack(int path[], int size, int candidates[], bool used[], int k, int nodes) {

    if (nodes == size && isPrime(path[size-1] + path[0])) {
        print(path, size);
        cout << endl;
        return;
    }
    for (int i = 0; i < size - 1; i++)
    {
        if (isPrime(path[k] + candidates[i]) && !used[i])
        {
            path[k+1] = candidates[i];
            used[i] = true;
            backtrack(path, size, candidates, used, k + 1, nodes + 1);
            used[i] = false;
        }
    }
}

int main() {

    int numero_nodi = 0;
    int numero_test_case = 2;

    while(numero_test_case--) {

        cin >> numero_nodi;

        int candidates[numero_nodi-1];
        bool used[numero_nodi - 1];
        for(int i=0; i<numero_nodi-1; i++) {
            candidates[i] = i + 2;
            used[i] = false;
        }
        int path[numero_nodi];

        for(int i=1; i<numero_nodi; i++)
            path[i] = 0;
        path[0] = 1;

        backtrack(path, numero_nodi, candidates, used, 0, 1);
    }

    return 0;
}

