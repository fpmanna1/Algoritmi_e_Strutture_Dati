#include <iostream>

using namespace std;

void choice(const int *scimmie, int num_scimmie, int altezza){
    int min_differenza_positiva = INT32_MAX;
    int max_differenza_negativa = INT32_MIN;
    int precedente = 0;
    int successivo = 0;

    int differenza = 0;

    for(int i=0; i<num_scimmie; i++){
        differenza = altezza - scimmie[i];
        if(differenza > 0 && differenza < min_differenza_positiva) {
            min_differenza_positiva = differenza;
            precedente = i;
        }else if(differenza < 0 && differenza > max_differenza_negativa){
            max_differenza_negativa = differenza;
            successivo = i;
        }
    }
    if(min_differenza_positiva != INT32_MAX)
        cout << scimmie[precedente];
    else
        cout << "x ";
    if(max_differenza_negativa != INT32_MIN)
         cout << " " << scimmie[successivo] << endl;
    else
        cout << " x" << endl;

} // COMPLESSITA O(n)

int main() {

    int numero_scimmie = 0;
    int numero_altezze = 0;
    cin >> numero_scimmie;

    int vet[numero_scimmie];

    for(int i=0; i<numero_scimmie; i++)
        cin >> vet[i];

    cin >> numero_altezze;

    int altezze[numero_altezze];
    for(int i=0; i<numero_altezze; i++) {
        cin >> altezze[i];
        choice(vet, numero_scimmie, altezze[i]);
    }

    //for(int i=0; i<numero_altezze; i++)
      //  choice(vet, numero_scimmie, altezze[i]);

    return 0;
}
