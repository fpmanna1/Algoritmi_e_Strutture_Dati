#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int lcs(string x, string y, int i, int j, int count){
    if(dp[i][j] != -1 && i > -1 && j > -1)
       return dp[i][j];

    if(i == -1 || j == -1)
        return count;

    if(x[i] == y[j]) {
        count = lcs(x, y, i-1, j-1, count + 1);
    }

    return dp[i][j] = max(count,
                max(lcs(x, y, i, j-1, 0),
                    lcs(x, y, i-1, j, 0)));

   // return dp[i][j] = count;

    // se due posizioni omologhe sono diverse, allora count torna a 0 (ecco la differenza con la
    // longest common subsequence
} // COMPLESSITA: O(x.size * y.size)


int main() {

    memset(dp, -1, sizeof dp);

    string x = "abcdxyz"; // output : 4
    string y = "xyzabcd";

    cout << lcs(x, y, x.size()-1, y.size()-1, 0) << endl;
    //cout << lcs_bottom_up(x, y) << endl;

    return 0;
}
