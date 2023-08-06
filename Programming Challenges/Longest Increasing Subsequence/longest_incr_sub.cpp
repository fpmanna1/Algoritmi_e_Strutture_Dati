#include <bits/stdc++.h>
#include <iostream>

using namespace std;

/*
 * DP BOTTOM UP APPROACH
 */

int lis(vector<int> array){
    int dp[array.size()];

    for(int k=0; k<array.size(); k++)
        dp[k] = 1;

    for(int i=1; i<array.size(); i++){
        for(int j=0; j<i; j++)
            if(array[i] > array[j])
                dp[i] = max(dp[i], dp[j] + 1);
    }

    for(int i=0; i<array.size(); i++)
        cout << dp[i] << " ";

    cout << endl;

    return dp[array.size() - 1];
} // COMPLESSITA: O(n^2)


int main() {

    vector<int> array = {50,3,10,7,40,80};

    cout << "LIS : "<<lis(array) << endl;

    return 0;
}
