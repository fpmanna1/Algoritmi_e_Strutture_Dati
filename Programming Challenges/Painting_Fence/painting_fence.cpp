/*
 * Given a fence with n posts and k colors, find out the number
 * of ways of painting the fence such that at most 2 adjacent posts
 * have the same color. Since the answer can be large return it modulo 10^9 + 7.

Examples:

Input : n = 2 k = 4
Output : 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color : 4
Ways when both posts have diff color :4(choices for 1st post) * 3(choices for 2nd post) = 12

Input : n = 3 k = 2
Output : 6
 */


#include <bits/stdc++.h>

using namespace std;

long painting_fence(int n, int k){ // posti, colori
    long dp[n+1];
    memset(dp, 0, sizeof dp);
    long long mod = 1000000007;

    dp[1] = k;
    dp[2] = k*k;

    for(int i=3; i<=n; i++)
        dp[i] = ((k-1) * (dp[i-1] + dp[i-2])) % mod;

    return dp[n];
} // COMPLESSITA : O(n)

int main() {

    int n = 3;
    int k = 2;

    cout << painting_fence(n, k) << endl;

    return 0;
}
