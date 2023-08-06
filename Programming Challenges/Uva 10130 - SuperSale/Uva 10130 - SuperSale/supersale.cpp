#include <bits/stdc++.h>

using namespace std;

int dp[1000][1000];

int supersale(vector<pair<int, int>> objects, int capacity, int i){
    // i : indice che scorre l'oggetto i-esimo

    if(dp[capacity][i] != -1)
        return dp[capacity][i];

    if(i >= objects.size())
        return 0;

    if(objects.at(i).second > capacity)
        return dp[capacity][i] = supersale(objects, capacity, i+1); // qui non ho scelta, sicuro non prendo l'oggetto
    else
        return dp[capacity][i] = max(supersale(objects, capacity - objects.at(i).second, i+1) + objects.at(i).first, // prendo l'oggetto
                   supersale(objects, capacity, i+1)); // non lo prendo
} // COMPLESSITA : O(objects.size() * capacity)

int main() {

    int t; // numero test cases

    cin >> t;

    while(t--){
        int n; // numero di oggetti
        cin >> n;
        vector<pair<int, int>> objects(n); // prezzo, peso

        for(int i=0; i<objects.size(); i++){
            cin >> objects[i].first;
            cin >> objects[i].second;
        }

        int g; // numero persone nel gruppo
        cin >> g;

        vector<int> people_capacity(g);
        vector<int> max_values(g);

        for(int i=0; i<people_capacity.size(); i++)
            cin >> people_capacity.at(i);

        int sum = 0;
        memset(dp, -1, sizeof dp);

        for(int i=0; i<people_capacity.size(); i++){
            sum += supersale(objects, people_capacity.at(i), 0);
        }

        cout << endl << endl;

        cout << sum << endl;
    }

    return 0;
}
