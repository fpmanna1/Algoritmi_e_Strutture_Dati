/*
 * Given an integer array of coins[ ] of size N representing different types
 * of currency and an integer sum, The task is to find the number of ways
 * to make sum by using different combinations from coins[].

Note: Assume that you have an infinite supply of each type of coin
 */

#include <bits/stdc++.h>

using namespace std;

int memo[1000][1000];

int coin_change(vector<int> coins, int sum, int i){
    if(sum >= 0 && i >= 0)
        if(memo[sum][i] != -1)
            return memo[sum][i];

    if(i >= coins.size())
        return 0;

    if(sum == 0)
        return 1;

    if(sum < 0)
        return 0;

    return memo[sum][i] = coin_change(coins, sum - coins.at(i), i) +
            coin_change(coins, sum, i+1);
} // COMPLESSITA : O(sum da raggiungere * dimensione array)

int coin_change_bottom_up(vector<int> coins, int sum){
    int x, y;

    int dp[sum + 1][coins.size()];
    memset(dp, -1, sizeof dp);

    for(int i=0; i<coins.size(); i++)
        dp[0][i] = 1;

    for(int i=1; i<sum + 1; i++){
        for(int j=0; j<coins.size(); j++){
            // conto le soluzioni che includono coins[j]
            if(i - coins[j] >= 0)
                x = dp[i - coins[j]][j];
            else
                x = 0;

            // conto le soluzioni che escludono coins[j]
            if(j >= 1)
                y = dp[i][j-1];
            else
                y = 0;

            dp[i][j] = x + y;
        }
    }

    return dp[sum][coins.size()-1];
} // COMPLESSITA : O(dim array * sum)


int main() {

    memset(memo, -1, sizeof memo);

    vector<int> array = {2, 5, 3, 6};
    int sum = 10;

    cout << coin_change(array, sum, 0) << endl;
    cout << coin_change_bottom_up(array, sum) << endl;

    return 0;
}
