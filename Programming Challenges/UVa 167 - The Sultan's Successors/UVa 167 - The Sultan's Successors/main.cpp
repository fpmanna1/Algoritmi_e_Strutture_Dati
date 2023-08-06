#include <iostream>
#include <algorithm>

using namespace std;

const int r = 8;
const int c = 8;

bool isValid(pair<int, int> sol[8], int queens_placed, int i, int j){
    // i e j sono le coordinate della posizione da controllare
    // queens_placed è il riempimento attuale del vettore soluzione
    for(int k=0; k<queens_placed; k++){
        if(sol[k].first == i || sol[k].second == j) // stessa riga o stessa colonna
            return false;
        if(abs(sol[k].first - i) == abs(sol[k].second - j)) // stessa diagonale
            return false;
    }
    return true;
}


void backtrack(int board[r][c], pair<int, int> sol[8], int queens_placed, int value, int &max_value, int j){

    if(queens_placed == c){
        if(value > max_value)
            max_value = value;
        return;
    }

        /*
         * scorro tutte le righe alla ricerca di una riga valida
         * se la trovo, passo alla colonna successiva
         */
        for(int i=0; i<r; i++){ // scorro le righe
            if(isValid(sol, queens_placed, i, j))
            {
                // aggiungi posizione (i,j) al vettore soluzione
                sol[j].first = i;
                sol[j].second = j;

                backtrack(board, sol, queens_placed + 1, value + board[i][j], max_value, j+1);
            }
        }
}


int main() {

    int t = 1;
    while (t--){
        int board[r][c] = {
                10, 28, 68, 57, 98, 54, 87, 66,
                7, 84, 20, 25, 29, 72, 33, 30,
                4, 20, 71, 69, 9, 16, 41, 50,
                97, 24, 19, 46, 47, 52, 22, 56,
                80, 89, 65, 29, 42, 51, 94, 1,
                35, 65, 25, 15, 88, 57, 44, 92,
                28, 66, 60, 37, 33, 52, 38, 29,
                76, 8, 75, 22, 59, 96, 30, 38
        };

        int massimo = INT32_MIN;
        pair<int, int> sol[8];
        backtrack(board, sol, 0, 0, massimo, 0);

        cout << massimo << endl;

    }

    return 0;
}
