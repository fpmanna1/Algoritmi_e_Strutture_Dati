/*
 * There are N houses built in a line, each of which contains some value in it.
 * A thief is going to steal the maximum value of these houses,
 * but he can’t steal in two adjacent houses because the owner of the stolen houses
 * will tell his two neighbors left and right sides.
 * The task is to find what is the maximum stolen value.
 */

#include <bits/stdc++.h>

using namespace std;

int dp[100];

int house_robber(vector<int> houses, int i){
    if(i < houses.size())
        if(dp[i] != -1)
            return dp[i];

    if(i >= houses.size())
        return 0;

    int ans = INT32_MIN;

    return dp[i] = ans = max(ans, max(houses.at(i) + house_robber(houses, i+2), house_robber(houses, i+1)));
} // COMPLESSITA : O(n)

int house_robber_bottom_up(vector<int> houses){
    if(houses.size() == 0)
        return 0;
    if(houses.size() == 1)
        return houses.at(1);

    int table[houses.size()];

    memset(table, 0, sizeof table);

    table[0] = houses.at(0);
    table[1] = max(houses.at(0), houses.at(1));

    for(int i=2; i<houses.size(); i++){
        table[i] = max(houses.at(i) + table[i-2], table[i-1]);
    }

    return table[houses.size()-1];

} // COMPLESSITA : O(n)

int main() {
    memset(dp, -1, sizeof dp);

    vector<int> a = {1, 2, 3, 1}; // output : 4
    vector<int> b = {2, 7, 9, 3, 1}; // output : 12

    cout << house_robber(b, 0) << endl;
    cout << house_robber_bottom_up(b) << endl;

    return 0;
}
