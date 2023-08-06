/*
 * Given N, count the number of ways to express N as sum of 1, 3 and 4.

Examples:

Input :  N = 4
Output : 4
Explanation: 1+1+1+1
             1+3
             3+1
             4

Input : N = 5
Output : 6
Explanation: 1 + 1 + 1 + 1 + 1
             1 + 4
             4 + 1
             1 + 1 + 3
             1 + 3 + 1
             3 + 1 + 1
 */

#include <bits/stdc++.h>

using namespace std;

int dp[1000];

int fun(int n){

    if(n >= 0)
        if(dp[n] != -1)
            return dp[n];

    if(n < 0)
        return 0;

    if(n == 0)
        return 1;

    return dp[n] = fun(n-1) + fun(n-3) + fun(n-4);
} // COMPLESSITA : O(n)

int fun_bottom_up(int n){
    // casi base
    dp[0] = dp[1] = dp[2] = 1;
    dp[3] = 2;

    for(int i=4; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-3] + dp[i-4];

    return dp[n];
}

int main() {

    memset(dp, -1, sizeof dp);

    int n = 7;

    cout << fun(n) << endl;

    memset(dp, -1, sizeof dp);

    cout << fun_bottom_up(n) << endl;

    return 0;
}
