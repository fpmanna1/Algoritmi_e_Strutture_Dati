/*
You are climbing a staircase. 
It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?
*/

#include <bits/stdc++.h>

using namespace std;

int dp[100];

/* BRUTE-FORCE APPROACH
int climbing_stairs(int i){

    int val = 0;

    if(i<=2)
        return i;

    val = climbing_stairs(i-1) + climbing_stairs(i-2);

    return val;

}
 */

/* DP MEMOIZATION
int climbing_stairs(int i) {

    if(dp[i] != -1)
        return dp[i];

    dp[i] = climbing_stairs(i-1) + climbing_stairs(i-2);

    return dp[i];
}

 */

// DP BOTTOM UP
int climbing_stairs(int n){

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    if(n <= 2)
        return dp[n];

    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}


int main() {

    memset(dp, -1, sizeof(dp));

    for(int i=0; i<=2; i++)
        dp[i] = i;

    cout << climbing_stairs(5) << endl;

    return 0;
}
