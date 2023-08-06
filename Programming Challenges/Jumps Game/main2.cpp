/*
 * DP BOTTOM-UP
 */

#include <bits/stdc++.h>

using namespace std;

int minJumps(vector<int> array, int size) {
    vector<int> jumps(size);
    int i, j;

    if (size == 0 || array.at(0) == 0)
        return INT32_MAX;

    jumps.at(0) = 0; // caso base
    // 0 salti per raggiungere la posizione 0

    for (i = 1; i < size; i++) {
        jumps.at(i) = INT32_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + array.at(j) && jumps.at(j) != INT32_MAX) {
                jumps.at(i) = min(jumps.at(i), jumps.at(j) + 1);
                //jumps.at(i) = jumps.at(j) + 1;
                break;
            }
        }
    }

    return jumps.at(size - 1);
}

int main(){

    vector<int> array = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    cout << minJumps(array, array.size());

    return 0;
}

