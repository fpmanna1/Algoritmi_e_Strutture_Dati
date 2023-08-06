#include <iostream>

using namespace std;

void max_popes_number(int period, int *years, int num_papi);

int main() {

    int period = 5;
    const int num_papi = 20;

   // cin >> period;
    //cin >> num_papi;
    int years[num_papi] = {
            1, 2, 3, 6, 8, 12, 13,
            13,15, 16, 17, 18, 19,
            20, 20, 21, 25, 26, 30, 31
    };
    //for(int i=0; i<num_papi; i++){
      //  cin >> years[i];
    //}
    max_popes_number(period, years, num_papi);

    return 0;
}

void max_popes_number(int period, int *years, int num_papi){
    int counter = 0;
    int max_numero_papi = INT32_MIN;

    int anno_primo_papa = 0;
    int anno_ultimo_papa = 0;

    int max_anno_primo_papa = 0;
    int max_anno_ultimo_papa = 0;

    int sum = 0; // differenza tra anni consecutivi (deve essere inferiore a period)
    int k = 0;

    for(int i=0; i<num_papi; i++){
        k=i; // considero la sequenza massima a partire dall' i-esimo elemento del vettore
        anno_primo_papa = years[k]; // salvo valore inizio sequenza
        while(sum < period){
            sum+=years[k+1]-years[k];
            counter++; // numero di papi in 5 anni
            k++; // indice vettore
        }
        anno_ultimo_papa = years[k-1]; // salvo valore di fine sequenza
        if(counter > max_numero_papi) { // se ho trovato una nuova sequenza più lunga
            max_anno_primo_papa = anno_primo_papa;
            max_anno_ultimo_papa = anno_ultimo_papa;
            max_numero_papi = counter;
        }
        counter = 0;
        sum = 0;
    }

    cout << max_numero_papi << " " << max_anno_primo_papa << " " << max_anno_ultimo_papa << endl;

} // COMPLESSITA NEL CASO PEGGIORE : O(n^2)
