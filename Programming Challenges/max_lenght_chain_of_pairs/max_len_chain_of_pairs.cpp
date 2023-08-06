/*
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number. A pair (c, d) can follow another pair (a, b) if b < c.
 * Chain of pairs can be formed in this fashion. Find the longest chain which can be formed from a given set of pairs.

For example, if the given pairs are
 {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} },
 then the longest chain that can be formed is of length 3,
 and the chain is {{5, 24}, {27, 40}, {50, 90}}
 */

#include <bits/stdc++.h>

using namespace std;

int max_len_chains_pairs(vector<pair<int, int>> pairs){
    // applicare una LIS con il vincolo che una coppia segue un'altra nella catena
    // se data (a, b) e (c, d) abbiamo che b < c
    // se .second della precedente e < di .first della successiva allora conta + 1
    // trova il massimo degli elementi che posso accodare tra queste sottosequenze

    int dp[pairs.size()];

    for(int i=0; i<pairs.size(); i++)
        dp[i] = 1;

    for(int i=1; i<pairs.size(); i++){
        for(int j=0; j<i; j++){
            if(pairs[j].second < pairs[i].first){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    for(int i=0; i<pairs.size(); i++)
        cout << dp[i] << " ";

    cout << endl;

    return dp[pairs.size()-1];
} // COMPLESSITA : O(n^2)


int main() {

    vector<pair<int, int>> pairs = {
            {5, 24},
            {39, 60},
            {15, 28},
            {27, 40},
            {50, 90}
    };

    cout << max_len_chains_pairs(pairs) << endl;



    return 0;
}
