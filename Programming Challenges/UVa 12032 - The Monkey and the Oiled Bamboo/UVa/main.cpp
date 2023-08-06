#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int simulation(vector<int> vet, int k){
    int actual_k = k; // k originale
    int difference = 0;
    int actual_height = 0;

    for(int i=0; i<vet.capacity(); i++)
    {
        difference = vet.at(i) - actual_height;
        actual_height = vet[i];
        if(difference > actual_k)
            return -1;
        else if(difference == actual_k)
            actual_k--;
    }

    return k;
}

// dato un certo k, simula il gioco e, se quel k è valido (mi permette di arrivare
// all'ultimo gradino) viene restituito in output altrimenti restituisco un valore negativo

 int binary_search(vector<int> vet, int start, int end) {

    if (end >= start) {
        //mid = start + (end - start) / 2;
        int mid = (start + end) / 2;

        if (simulation(vet, mid) >= 0)
            return binary_search(vet, start ,mid - 1);
        else
            return binary_search(vet, mid + 1, end);
    } else
        return end + 1;
}

int find_min_k(vector<int> heights){
    // è una ricerca binaria del possibile risultato, devo provare tutti gli elementi
    // ma non in modo lineare, sfrutto il fatto che se un determinato k non è valido
    // allora tutti i k precedenti sicuramente non saranno validi

    return binary_search(heights, 0, 100000);
}

int main() {

    int t;
    cin >> t;
    int i=1;
    while(t--){
        int n_rungs;
        cin >> n_rungs;

        vector<int> heights(n_rungs);

        for(int i=0; i<heights.capacity(); i++)
            cin >> heights.at(i);

        cout << "Case "<<i<<": "<<find_min_k(heights) << endl;

        //cout << simulation(heights, 7) << endl;
        i++;
    }

    return 0;
}
