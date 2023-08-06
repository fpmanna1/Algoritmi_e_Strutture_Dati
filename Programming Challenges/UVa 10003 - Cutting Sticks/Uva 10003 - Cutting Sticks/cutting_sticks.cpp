/*
 * Given a stick of length 1 ≤ l ≤ 1000 and 1 ≤ n ≤ 50 cuts to be made to the stick
 * (the cut coordinates, lying in the range [0..l], are given). The cost of a cut is
 * determined by the length of the stick to be cut. Your task is to find a cutting
 * sequence so that the overall cost is minimized.
Example: l = 100, n = 3, and cut coordinates: A = {25, 50, 75} (already sorted)
If we cut from left to right, then we will incur cost = 225. 1. First cut is at
 coordinate 25, total cost so far = 100; 2. Second cut is at coordinate 50, total cost so
 far = 100 + 75 = 175; 3. Third cut is at coordinate 75, final total cost = 175 + 50 = 225;
Figure 3.12: Cutting Sticks Illustration
However, the optimal answer is 200. 1. First cut is at coordinate 50, total cost so far = 100;
 (this cut is shown in Figure 3.12) 2. Second cut is at coordinate 25, total cost so far = 100 + 50 = 150;
3. Third cut is at coordinate 75, final total cost = 150 + 50 = 200;
 */


#include <bits/stdc++.h>

using namespace std;

vector<int> A = {0, 25, 50, 75, 100};

int cut(int left, int right){
    if(left+1 == right)
        return 0;

    int temp_min = INT32_MAX;

    for(int i = left + 1; i < right; i++)
    {
        temp_min = min(temp_min, cut(left, i) + cut(i, right) + (A.at(right)-A.at(left)));
    }
    return temp_min;
}

int main() {
    cout << cut(0, 3+1) << endl;
    
    return 0;
}

//-------------------------------------------------

#include <stdio.h>
#include <limits.h>

int n, l, C[52], DP[52][52];
int min(int a, int b){ return (a < b)? a:b; }

int BottomUp(int ini, int fin)
{
    int i, j, k, L;

    /*Caso Base*/
    for(i = 0; i < fin; i++)
        DP[i][i+1] = 0;

    for(L = 2; L <= fin; L++){
        for(i = 0; i <= (fin - L); i++){
            j = i + L;
            DP[i][j] = INT_MAX;
            for(k = i+1; k < j; k++){
                DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j] + (C[j] - C[i]));
            }
        }
    }

    return DP[0][fin];
} // COMPLESSITA : O(n^3)

int main()
{
    int i, sol;

    while(1)
    {
        scanf("%d", &l);
        if(l == 0) break;
        scanf("%d", &n);
        C[0] = 0;
        for(i = 1; i <= n; i++)
            scanf("%d", &C[i]);
        C[n+1] = l;
        sol = BottomUp(0, n+1);
        printf("The minimum cutting is %d.\n", sol);
    }
    return 0;
}
