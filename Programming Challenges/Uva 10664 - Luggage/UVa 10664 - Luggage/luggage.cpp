/*
 * There is a list of luggage (defined by their weights)
 * and you are trying to split them among 2 cars exactly equally,
 * se trovo un insieme di oggetti che fa sum/2, anche l'altra metà sarà
 * sum/2 e quindi ho risolto il problema

print "YES" if you can, "NO" otherwise
 */

#include <bits/stdc++.h>

using namespace std;

int memo[1000][1000];

int luggage(vector<int> a, int sum, int i){

    if(i >= a.size() || sum < 0)
        return 0;

    //if(i<a.size())
    if(memo[sum][i] != -1)
        return memo[sum][i];

    if(sum == 0)
        return 1;

    return memo[sum][i] = luggage(a, sum - a.at(i), i+1) + luggage(a, sum, i+1);
}

int main() {

    memset(memo, -1, sizeof memo);

    vector<int> c = {10, 100, 1000, 200, 358};
    vector<int> b = {2, 3, 4, 1, 2, 5, 10, 50, 3, 50};
    vector<int> a = {3, 5, 2, 7, 1, 7, 5, 2, 8, 9, 1, 25,15, 8, 3, 1, 38, 45, 8, 1};

    int sum = 0;

    for(int i=0; i<a.size(); i++){
        sum += a.at(i);
    }

    if(sum % 2 != 0)
        cout << "NO" << endl;
    else
        if(luggage(a, sum/2, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    return 0;
}
