/*
 * You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if
 you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such
 that you can reach nums[n - 1].



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from
 index 0 to 1, then 3 steps to the last index.
 */

#include <bits/stdc++.h>

using namespace std;

// recursive solver to find min jumps to reach end
int solve(vector<int>& nums, vector<int>& dp, int pos) {
    if(pos >= size(nums) - 1) return 0;    // when we reach end, return 0 denoting no more jumps required
    if(dp[pos] != 10001) return dp[pos];    // number of jumps from pos to end is already calculated, so just return it
    // explore all possible jump sizes from current position. Store & return min jumps required
    for(int j = 1; j <= nums[pos]; j++)
        dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));
    return dp[pos];
} // COMPLESSITA : O(n^2)

int jump_top_down(vector<int>& nums) {
    vector<int> dp(size(nums), 10001); // initialise all to max possible jumps + 1 denoting dp[i] hasn't been computed yet
    return solve(nums, dp, 0);
}

int jump_bottom_up(vector<int>& nums) {
    int n = size(nums);
    vector<int> dp(n, 10001);
    dp[n - 1] = 0;  // start from last index. No jumps required to reach end if we are already here
    // same as above. For each index, explore all jump sizes and use the one requiring minimum jumps to reach end
    for(int i = n - 2; i >= 0; i--)
        for(int jumpLen = 1; jumpLen <= nums[i]; jumpLen++)
            dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]);  // min(n-1, i + jumpLen) for bounds handling
    return dp[0];
}


int main() {

    vector<int> heights = {2, 3, 1, 1, 4};

    cout << jump_top_down(heights) << endl;

    return 0;
}
