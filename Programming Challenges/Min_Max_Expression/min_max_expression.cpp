/*
 * Given an expression which contains numbers and two operators
 * ‘+’ and ‘*’, we need to find maximum and minimum value which
 * can be obtained by evaluating this expression by different parenthesization.
Examples:

Input  : expr = “1+2*3+4*5”
Output : Minimum Value = 27, Maximum Value = 105
Explanation:
Minimum evaluated value = 1 + (2*3) + (4*5) = 27
Maximum evaluated value = (1 + 2)*(3 + 4)*5 = 105
 */


#include <bits/stdc++.h>
using namespace std;

int dp_max[100][100];
int dp_min[100][100];

int evalExpressionMin(int i, int j, string str)
{
    if(dp_min[i][j] != -1)
        return dp_min[i][j];

    if (i > j)
        return 0;


    if (i == j)
    {
        return str[i] - '0';
    }


    int ans = INT_MAX;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int tempAns = 0, ELeft = 0, ERight = 0;
        ELeft = evalExpressionMin(i, k - 1, str);
        ERight = evalExpressionMin(k + 1, j, str);


        if (str[k] == '+')
            tempAns = ELeft + ERight;
        if (str[k] == '*')
            tempAns = ELeft * ERight;
        ans = min(ans, tempAns);
    }
    return dp_min[i][j] = ans;
}


int evalExpressionMax(int i, int j, string str)
{

    if(dp_max[i][j] != -1)
        return dp_max[i][j];
    if (i > j)
        return 0;


    if (i == j)
        return str[i] - '0';


    int ans = INT_MIN;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int tempAns = 0, ELeft = 0, ERight = 0;
        ELeft = evalExpressionMax(i, k - 1, str);
        ERight = evalExpressionMax(k + 1, j, str);
        if (str[k] == '+')
            tempAns = ELeft + ERight;
        if (str[k] == '*')
            tempAns = ELeft * ERight;
        ans = max(ans, tempAns);
    }
    return dp_max[i][j] = ans;
} // COMPLESSITA: O(n^3)


int main()
{
    memset(dp_max, -1, sizeof dp_max);
    memset(dp_min, -1, sizeof dp_min);

    string S = "1+2*3+4*5";
    int N = S.size();
    int minn = evalExpressionMin(0, N - 1, S);
    int maxx = evalExpressionMax(0, N - 1, S);
    cout << "Minimum Value is " << minn << endl
         << "Maximum Value is " << maxx << endl;
    return 0;
}
