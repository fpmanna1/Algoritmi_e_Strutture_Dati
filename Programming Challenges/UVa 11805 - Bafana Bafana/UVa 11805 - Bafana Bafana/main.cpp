#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bafana_bafana(int n, int k, int p){
    if(k + p > n)
        return (k + p) % n;
    else
        return k + p;
}

int main() {

    int t;
    cin >> t;
    while(t--){
        int n, k, p;
        cin >> n >> k >> p;

        cout << bafana_bafana(n, k, p) << endl;
    }


    return 0;
}
