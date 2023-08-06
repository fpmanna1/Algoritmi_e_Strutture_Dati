/*
 * Given N non-negative integers which signifies the cost of the moving from each stair.
 * Paying the cost at i-th step, you can either climb one or two steps. Given that one can s
 * tart from the 0-the step or 1-the step, the task is to find the minimum cost to reach
 * the top of the floor(N+1) by climbing N stairs.
 *
 * Input: a[] = { 16, 19, 10, 12, 18 }
Output: 31
Start from 19 and then move to 12.

Input: a[] = {2, 5, 3, 1, 7, 3, 4}
Output: 9
2->3->1->3
 */

#include <bits/stdc++.h>

using namespace std;

int dp[100];

// TOP-DOWN
int min_climbing_stairs(vector<int> cost, int i){

    if(dp[i] != -1)
        return dp[i];

   if(i<2)
       return cost[i];

   int ans = INT32_MAX;

   ans = min(ans, min(min_climbing_stairs(cost, i-1) + cost[i], min_climbing_stairs(cost, i-2) + cost[i]));

   return dp[i] = ans;
}

// BOTTOM-UP
int fun(vector<int> cost){

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i=2; i<cost.size(); i++){
        dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i]);
    }

    return min(dp[cost.size()-1], dp[cost.size()-2]);

}

int main() {

    vector<int> a = {2, 5, 3, 1, 7, 3, 4};
    vector<int> b = {16, 19, 10, 12, 18};

    memset(dp, -1, sizeof dp);

    //cout << min_climbing_stairs(a, a.size()) << endl;

    cout << fun(b) << endl;

    return 0;
}
