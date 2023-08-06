/*
 * Given two numbers n and k where n represents a number
 * of elements in a set, find a number of ways to partition
 * the set into k subsets.
Example:

Input: n = 3, k = 2
Output: 3
Explanation: Let the set be {1, 2, 3}, we can partition
             it into 2 subsets in following ways
             {{1,2}, {3}},  {{1}, {2,3}},  {{1,3}, {2}}

Input: n = 3, k = 1
Output: 1
Explanation: There is only one way {{1, 2, 3}}
 */

// A C++ program to count number of partitions
// of a set with n elements into k subsets
#include<iostream>
using namespace std;

// Returns count of different partitions of n
// elements in k subsets
int countP(int n, int k)
{
// Base cases
    if (n == 0 || k == 0 || k > n)
        return 0;
    if (k == 1 || k == n)
        return 1;

// S(n+1, k) = k*S(n, k) + S(n, k-1)
    return k*countP(n-1, k) + countP(n-1, k-1);
} // COMPLESSITa : O(2^n)  aggiungere memoization per O(n*k)

// Driver program
int main()
{
    cout << countP(3, 2);
    return 0;
}


//-----------------------------------------------------------------------

// A Dynamic Programming based C++ program to count
// number of partitions of a set with n elements
// into k subsets
#include<iostream>
using namespace std;

// Returns count of different partitions of n
// elements in k subsets
int countP(int n, int k)
{
// Table to store results of subproblems
    int dp[n+1][k+1];

// Base cases
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= k; i++)
        dp[0][k] = 0;

// Fill rest of the entries in dp[][]
// in bottom up manner
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (j == 1 || i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = j * dp[i - 1][j] + dp[i - 1][j - 1];

    return dp[n][k];
} // COMPLESSITA : O(n*k)

// Driver program
int main()
{
    cout << countP(5, 2);
    return 0;
}

