/*
 * Consider a 2-D map with a horizontal river passing through its center.
 * There are n cities on the southern bank with x-coordinates a(1) … a(n) and n
 * cities on the northern bank with x-coordinates b(1) … b(n).
 * You want to connect as many north-south pairs of cities as possible
 * with bridges such that no two bridges cross. When connecting cities,
 * you can only connect city a(i) on the northern bank to city b(i) on
 * the southern bank. Maximum number of bridges that can be built to
 * connect north-south pairs with the above mentioned constraints.
 *
 * Input : 6 4 2 1
        2 3 6 5
Output : Maximum number of bridges = 2
Explanation: Let the north-south x-coordinates
be written in increasing order.

1  2  3  4  5  6
  \  \
   \  \        For the north-south pairs
    \  \       (2, 6) and (1, 5)
     \  \      the bridges can be built.
      \  \     We can consider other pairs also,
       \  \    but then only one bridge can be built
        \  \   because more than one bridge built will
         \  \  then cross each other.
          \  \
1  2  3  4  5  6

Input : 8 1 4 3 5 2 6 7
        1 2 3 4 5 6 7 8
Output : Maximum number of bridges = 5
 */

#include <bits/stdc++.h>
using namespace std;

bool myComparison(const pair<int,int> &a,const pair<int,int> &b)
{
    return a.first<b.first;
}

int fun(vector<pair<int, int>> bases)
{
    vector<int> dp(bases.size());

    for(int i=0; i<bases.size(); i++)
        dp[i] = 1;

    for(int i=1; i<bases.size(); i++){
        for(int j=0; j<i; j++){
            if(bases[j].second <= bases[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return *max_element(dp.begin(), dp.end());

} // COMPLESSITA : O(n^2)

int main() {
/*
    int t;
    cin >> t;

    while(t--){
        int dim;
        cin >> dim;

        vector<int> x(dim);
        vector<int> y(dim);

        for(int i=0; i<x.size(); i++)
            cin >> x.at(i);
        for(int i=0; i<y.size(); i++)
            cin >> y.at(i);

            */

    /*vector<pair<int, int>> militar_bases = {{8, 1}, {1,2}, {4, 3}, {3, 4},
                                                {5,5}, {2, 6}, {6, 7}, {7, 8}}; */

    vector<pair<int, int>> militar_bases = {{6, 2}, {4,3}, {2, 6}, {1, 5}};

    sort(militar_bases.begin(), militar_bases.end(), myComparison);

    /*for(int i=0; i<militar_bases.size(); i++)
        cout << militar_bases[i].first << " " << militar_bases[i].second << endl; */

    cout << fun(militar_bases) << endl;

    return 0;
}
