/*
 * Given an array of n non-negative numbers, the task is to find
 * the minimum sum of elements (picked from the array) such that
 * at least one element is picked out of every 3 consecutive elements in the array.

Examples :

Input : arr[] = {1, 2, 3}
Output : 1

Input : arr[] = {1, 2, 3, 6, 7, 1}
Output : 4
We pick 3 and 1  (3 + 1 = 4)
Note that there are following subarrays
of three consecutive elements
{1, 2, 3}, {2, 3, 6}, {3, 6, 7} and {6, 7, 1}
We have picked one element from every subarray.

Input : arr[] = {1, 2, 3, 6, 7, 1, 8, 6, 2,
                 7, 7, 1}
Output : 7
The result is obtained as sum of 3 + 1 + 2 + 1
 */


#include <bits/stdc++.h>

using namespace std;

int minimum(int a, int b, int c){
    return min(a, min(b, c));
}

int f(vector<int> a){
    // dp : dp[i] memorizza il minimo quando a[i] è incluso nella soluzione
    int dp[a.size()];

    memset(dp, 0, sizeof dp);

    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];

    for(int i=3; i<a.size(); i++)
        dp[i] = a[i] + minimum(dp[i-3], dp[i-2], dp[i-1]);

    return minimum(dp[a.size()-1], dp[a.size()-2], dp[a.size()-3]);

} // COMPLESSITA : O(n)

int main() {

    vector<int> a = {1, 2, 3, 6, 7, 1, 8, 6, 2, 7, 7, 1}; // output : 7
    vector<int> b = {1, 2, 3, 6, 7, 1}; // output : 4
    vector<int> c = {1, 2, 3}; // output : 1

    cout << f(c) << endl;

    return 0;
}
