/*
 * We have some boxes numbered 1 to N. The dimensions of all boxes are identical. Now we have to
stack up some of the boxes, subject to the following constraints:
1. One cannot put more than one boxes directly upon a box;
2. Boxes with lower serial numbers are not to be put upon one with a higher number;
3. The weight and maximum load for each box are given. The total weight of all boxes upon a box
should not exceed its maximum load.
Please write a program that finds the maximum number of boxes that can be stacked up according
to the above constraints.
Input
The first line of each set of input is an integer N (1 ≤ N ≤ 1000). This is followed by N lines, each
with two integers, both ≤ 3000, representing the weight and maximum load of each box respectively.
Input ends with a case where N = 0.
Output
Each line of your output should give the number of boxes that can be stacked up.
Sample Input
5
19 15
7 13
5 7
6 8
1 2
0
Sample Output
4
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAX_WEIGHT = 3000, MAX_LOAD = 3000;

int main()
{
    int N;
    while (cin >> N, N != 0)
    {
        // dp[i] stores the maximum number of boxes that can be
        // stacked up for exactly total weight i.
        vector<int> W(N + 1), L(N + 1);
        for (int i = 1; i <= N; ++i)
            cin >> W[i] >> L[i];

        vector<int> dp(MAX_WEIGHT + MAX_LOAD + 1, 0);
        // Consider box N, box N-1..to box 1.
        for (int box = N; box >= 1; --box)
        {
            for (int load = L[box]; load >= 0; --load)
            {
                if (dp[load])
                    dp[load + W[box]] = max(dp[load + W[box]], // The original best stack.
                                            dp[load] + 1);     // The box stack.
            }
            if (dp[W[box]] == 0)
                dp[W[box]] = 1;
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}

//----------------------------------

#include <iostream>

using namespace std;

int N;
int maxNumberWithLoadLeft[1005][3005];

int weight[1005], load[1005];

int GetNumberCanHold(int currentBox, int loadLeft)
{
    if (currentBox == N)
        return 0;

    int &num = maxNumberWithLoadLeft[currentBox][loadLeft];

    if (num == -1)
    {
        num = GetNumberCanHold(currentBox + 1, loadLeft); // Try not including it

        if (loadLeft >= weight[currentBox])
            // Include box
            num = max(num, 1 + GetNumberCanHold(currentBox + 1,
                                                min(loadLeft - weight[currentBox], load[currentBox])));
    }

    return num;
}


int FindBest()
{
    int best = 0;
    for (int box = 0; box < N; ++box)
    {
        // Starting using this box, and then see how much can hold
        best = max(best, GetNumberCanHold(box + 1, load[box]) + 1);
    }
    return best;
}

int main()
{
    while (cin >> N, N)
    {
        int highestLoad = 0;
        for (int i = 0; i < N; ++i)
        {
            cin >> weight[i] >> load[i];
            highestLoad = max(highestLoad, load[i]);
        }

        // Reset data
        for (int i = 0; i < N; ++i)
            for (int j = 0; j <= highestLoad; ++j)
                maxNumberWithLoadLeft[i][j] = -1;

        cout << FindBest() << '\n';
    }
}