/*
 * Given a set of non-negative integers, and a value sum, determine if
 * there is a subset of the given set with sum equal to given sum.

Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.
 */

#include <bits/stdc++.h>

using namespace std;

int dp[100][100];
// numero elementi array x sum da raggiungere

bool subset_sum(vector<int> array, int sum, int partial_sum, int i){
    if(dp[i][partial_sum] != -1)
        return dp[i][partial_sum];

    if(sum == 0)
        return false;

    if(i >= array.size())
        return false;

    if(partial_sum == sum)
        return true;

    if(partial_sum > sum)
        return false;

    return dp[i][partial_sum] = subset_sum(array, sum, partial_sum + array.at(i), i+1) ||
    subset_sum(array, sum, partial_sum, i+1);

} // COMPLESSITA : O(sum * dimensione array)

bool subset_sum_bottom_up(int set[], int n, int sum){
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j]
                               || subset[i - 1][j - set[i - 1]];
        }
    }

    return subset[n][sum];

} // COMPLESSITA : O(n*sum)

int main() {
    memset(dp, -1, sizeof dp);

    vector<int> array = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    vector<int> vet = {3, 34, 4, 12, 5, 2};
    int somma = 30;

    if(subset_sum(array, sum, 0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
