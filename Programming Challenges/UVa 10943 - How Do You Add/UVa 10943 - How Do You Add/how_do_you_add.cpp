/*
 * Larry is very bad at math — he usually uses a calculator,
 * which worked well throughout college. Unforunately, he is now struck in a
 * deserted island with his good buddy Ryan after a snowboarding accident.
 * They’re now trying to spend some time figuring out some good
problems, and Ryan will eat Larry if he cannot answer, so his fate is up to you!
 It’s a very simple problem — given a number N, how many ways
can K numbers less than N add up to N? For example, for N = 20 and K = 2,
 there are 21 ways: 0+20
 1+19
 2+18
 3+17
 4+16
 5+15
 ...
18+2
 19+1
 20+0

Input
Each line will contain a pair of numbers N and K. N and K will both be an
 integer from 1 to 100, inclusive. The input will terminate on 2 0’s.
Output
 Since Larry is only interested in the last few digits of the answer,
 for each pair of numbers N and K, print a single number
 mod 1,000,000 on a single line.
Sample Input 20 2 20 2 0 0
Sample Output 21
21
 */

#include <bits/stdc++.h>

int memo[110][110];

using namespace std;

void print(int mat[110][110], int n, int k){
    for(int i=0; i<k; i++){ // i scorre le righe, cioè i k
        cout << endl;
        for(int j=0; j<n; j++)
            cout << mat[i][j] << " ";
    }
}

int ways(int n, int k){

    if(k == 1)
        return 1;
    else if(memo[n][k] != -1)
        return memo[n][k];

    int total_ways = 0;
    for(int i=0; i<=n; i++)
        total_ways = (total_ways + ways(n-i, k-1)) % 1000000;

    return memo[n][k] = total_ways;
} // COMPLESSITA : O(n*k)

int main() {
    memset(memo, -1, sizeof memo);
    int n;
    int k;

    cin >> n >> k;
    while(n != 0 && k != 0){

        cout << ways(n, k) << endl;
        print(memo, n, k);
        cout << endl << endl;
        cin >> n >> k;
    }

    return 0;
}

