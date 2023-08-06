/*
 * Given an array of n size, the task is to find the
 * longest subsequence such that difference between adjacents is one.
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> vet = {10, 9, 4, 5, 4, 8, 6};
vector<int> dp = {1, 1, 1, 1 , 1, 1, 1};

int ls(){
    for(int i=0; i<dp.size(); i++)
        dp.at(i) = 1;

    for(int i = 1; i < 7; i++){
        for(int j = 0; j < i; j++){
            if(abs(vet.at(i) - vet.at(j)) == 1)
                dp.at(i) = max(dp.at(i), dp.at(j) + 1);
        }

    }

    return dp.at(6);
}

int main() {

    cout << "RESULT : "<<ls() << endl;
    for(int i=0; i<dp.size(); i++)
        cout << dp.at(i) << " ";

    return 0;
}
