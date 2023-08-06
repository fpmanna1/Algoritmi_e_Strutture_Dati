/*
 * Given an array of n positive integers. Write a program to find the sum of
 * maximum sum subsequence of the given array such that the integers in the
 * subsequence are sorted in increasing order. For example, if input is
 * {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100),
 * if the input array is {3, 4, 5, 10}, then output should be
 * 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10
 */

#include <bits/stdc++.h>

using namespace std;

int max_sum_incr_sub(vector<int> array){
    vector<int> dp(array.size());

    for(int i=0; i<dp.size(); i++)
        dp.at(i) = array.at(i);

    for(int i=1; i<array.size(); i++){
        for(int j=0; j<i; j++) {
            if (array.at(i) > array.at(j))
                dp[i] = max(dp[i], dp[i] + array.at(j));
        }
    }

    return *max_element(dp.begin(), dp.end());
} // COMPLESSITA : O(n^2)


int main() {
    vector<int> array = {1, 101, 2, 3, 100, 4, 5};

    cout << max_sum_incr_sub(array) << endl;

    return 0;
}
