/*
 * Given different options for each garment (e.g. 3 shirt models, 2 belt models, 4 shoe models, ...)
 * and a certain limited budget, our task is to buy one model of each garment. We cannot spend
 * more money than the given budget, but we want to spend the maximum possible amount. The input
 * consists of two integers 1 ≤ M ≤ 200 and 1 ≤ C ≤ 20, where M is the budget
and C is the number of garments that you have to buy, followed by some information about the C garments.
 For the garment g ∈ [0..C-1], we will receive an integer 1 ≤ K ≤ 20 which indicates the number of
 different models there are for that garment g, followed by K integers indicating the price of each
 model ∈ [1..K] of that garment g. The output is one integer that indicates the maximum amount of money we can spend
purchasing one of each garment without exceeding the budget. If there is no solution due to the
 small budget given to us, then simply print “no solution”.
Suppose we have the following test case A with M = 20, C =3: Price ofthe 3models ofgarment g= 0 → 648 //
 the prices are not sorted in the input Price ofthe 2models ofgarment g= 1 → 510 Price ofthe 4models ofgarment g= 2 → 1 53 5
For this test case, the answer is 19, which may result from buying the underlined items (8+10+1).
 This is not unique, as solutions (6+10+3) and (4+10+5) are also optimal. However, suppose we have
 this test case B with M = 9 (limited budget), C =3: Price ofthe 3models ofgarment g= 0 → 648 Price of
 the 2models ofgarment g= 1 → 510
Price ofthe 4models ofgarment g= 2 → 153 5
 */


#include <bits/stdc++.h>

using namespace std;

const int max_categories = 20;
const int max_model = 20;
const int max_budget = 200;

int memo[max_categories][max_budget+1];
int prices[max_categories][max_model]; // categorie x budget massimo

void init(int mem[max_categories][max_budget + 1]){
    for(int i=0; i<max_categories; i++)
        for(int j=0; j<max_budget+1; j++)
            mem[i][j] = INT32_MAX;
}

void print(int p[20][201]) {
    for (int i = 0; i < 20; i++){
        cout << endl;
        for (int j = 0; j < 201; j++){
            cout << p[i][j] << " ";
        }
    }
}

int dp(int budget_iniziale, int numero_categorie, vector<int> sizes, int budget_rimanente, int categoria_attuale, int min_attuale)
{
    if(memo[categoria_attuale][budget_rimanente] <= 200)
        return memo[categoria_attuale][budget_rimanente];

    // desidero il minimo budget rimanente
    if(budget_rimanente < 0)
        return INT32_MAX; // valore sentinella che mi fa escludere quella soluzione

    if(categoria_attuale == numero_categorie)
        return budget_rimanente;

    for(int i=0; i<sizes.at(categoria_attuale); i++) { // i scorre i modelli appartenenti alla categoria attuale
         min_attuale = min(min_attuale, dp(budget_iniziale, numero_categorie, sizes,
                                          budget_rimanente - prices[categoria_attuale][i],
                                          categoria_attuale+1, min_attuale));
    }
    return memo[categoria_attuale][budget_rimanente] = min_attuale;
}

int main() {

    int t;
    cin >> t;
    while(t--){
        int budget, garments_to_buy;
        cin >> budget >> garments_to_buy;

        vector<int> sizes(garments_to_buy);

        for(int i=0; i<garments_to_buy; i++){
            int k;
            cin >> k;
            sizes.at(i) = k;

            for(int j=0; j<k; j++)
                cin >> prices[i][j];
        }

        init(memo);

        int budget_rimanente = dp(budget, garments_to_buy, sizes, budget, 0, INT32_MAX);

        if(budget_rimanente > budget)
            cout << "no solution"<<endl;
        else
            cout << budget - budget_rimanente<<endl;
    }

    return 0;
}

int shop(int money, int g) {
    if (money < 0) return -1000000000;
    if (g == C) return M - money;
    int &ans = memo[money][g];                 // remember the memory address
    if (ans != -1) return ans;
    for (int model = 1; model <= price[g][0]; model++)
        ans = max(ans, shop(money - price[g][model], g + 1));
    return ans;                // ans (or memo[money][g]) is directly updated
}
