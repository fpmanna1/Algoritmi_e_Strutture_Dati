/*
 * Given an array arr[] where each element represents the max
 * number of steps that can be made forward from that index.
 * The task is to find the minimum number of jumps to reach
 * the end of the array starting from index 0.
 * If the end isn’t reachable, return -1.
 */

/*
 * DP WITH MEMOIZATION
 */

#include <bits/stdc++.h>

using namespace std;

int dp[100];

int minimumJumps(int arr[], int currentIndex, int n) {

    if(arr[currentIndex] >= n-currentIndex-1)
        return 1;

    if(arr[currentIndex] == 0)
        return INT_MAX;

    if(dp[currentIndex] != -1)
        return dp[currentIndex];

    int ans = INT_MAX;
    for(int i=1; i<=arr[currentIndex]; i++) {
        int jumps = minimumJumps(arr,currentIndex+i,n);

        if(jumps != INT_MAX)
            ans = min(ans,1 + jumps);
    }

    return dp[currentIndex] = ans;
}

int main() {
    int arr[] = {1, 3, 6, 3, 2, 3, 6, 0, 9, 5};
    int n = sizeof arr / sizeof arr[0];

    memset(dp,-1, sizeof dp);

    cout<<minimumJumps(arr,0,n)<<endl;

    return 0;
}

//--------------------------------------------------------------

/*
 * DP BOTTOM-UP
 */

#include <bits/stdc++.h>

using namespace std;

int minJumps(vector<int> array, int size) {
    vector<int> jumps(size);
    int i, j;

    if (size == 0 || array.at(0) == 0)
        return INT32_MAX;

    jumps.at(0) = 0; // caso base
    // 0 salti per raggiungere la posizione 0

    for (i = 1; i < size; i++) {
        jumps.at(i) = INT32_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + array.at(j) && jumps.at(j) != INT32_MAX) {
                jumps.at(i) = min(jumps.at(i), jumps.at(j) + 1);
                //jumps.at(i) = jumps.at(j) + 1;
                break;
            }
        }
    }

    return jumps.at(size - 1);
}

int main(){

    vector<int> array = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << minJumps(array, array.size());

    return 0;
}



