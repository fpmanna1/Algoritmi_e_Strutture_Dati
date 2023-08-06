#include <bits/stdc++.h>

using namespace std;

int memo[100][100];

/*
 * DP WITH MEMOIZATION
 */

int lcs(string x, string y, int m, int n)
{

    int ans = INT32_MIN;

    if(memo[m][n] != -1)
        return memo[m][n];

    if(m == 0 || n == 0)
        return 0;

    if(x[m-1] == y[n-1]) {
        return memo[m][n] = (1 + lcs(x, y, m - 1, n - 1));
    }else{
        return memo[m][n] = max(lcs(x, y, m-1, n), lcs(x, y, m, n-1));
    }
}

/*
int main() {

    string x = "ABCDGH";
    string y = "AEDFHR";

    memset(memo, -1, sizeof(memo));

    cout << "LCS : "<<lcs(x, y, x.size(), y.size());

    return 0;
} */

//------------------------------------------

#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

/*
 * DP BOTTOM UP
 */

int lcs(string x, string y){

    for(int i=0; i<x.size(); i++)
        dp[i][0] = 0;
    for(int j=0; j<y.size(); j++)
        dp[0][j] = 0;

    for(int i=1; i<=x.size(); i++)
        for(int j=1; j<=y.size(); j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    return dp[x.size()][y.size()];

}

int main(){

    string x = "ABCDGH";
    string y = "AEDFHR";

    //string x = "AGGTAB";
    //string y = "GXTXAYB";

    memset(dp, 0, sizeof(dp));

    cout << "LCS : "<<lcs(x, y) << endl;
}


