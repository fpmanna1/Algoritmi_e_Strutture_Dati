#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print(const vector<int>& vet){
    for(int i : vet){
        cout << i <<  " ";
    }
}

pair<int, int> exact_sum(vector<int> prices, int budget){
    pair<int, int> books;
    stable_sort(prices.begin(), prices.end());

    int candidate;
    int diff = 1;
    int min_diff = INT32_MAX;

    for(int i=0; i<prices.size(); i++){
        candidate = budget - prices.at(i);
        diff = candidate - prices.at(i);
        if(binary_search(prices.begin(), prices.end(), candidate)){
            if(diff < 0)
                break;
            if(diff < min_diff){
                books.first = prices.at(i);
                books.second = candidate;
                min_diff = diff;
            }
        }
    }

    return books;
}

int main() {

    int t = 2;

    while(t--){
        int num_libri;
        cin >> num_libri;

        vector<int> libri(num_libri);

        int temp;
        for(int i=0; i<num_libri; i++){
            cin >> libri.operator[](i);
        }

        int budget;
        cin >> budget;

        pair<int, int> result;
        result = exact_sum(libri, budget);

        cout << "Peter should buy books whose prices are "
        << result.first << " and " << result.second << endl << endl;

    }




    return 0;
}
