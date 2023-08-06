/*
Given an array A[] of n numbers and another number x, 
the task is to check whether or not there exist two 
elements in A[] whose sum is exactly x. 

Examples: 

Input: arr[] = {0, -1, 2, -3, 1}, x= -2
Output: Yes
Explanation:  If we calculate the sum of the output,1 + (-3) = -2

Input: arr[] = {1, -2, 1, 0, 5}, x = 0
Output: No


*/


#include <bits/stdc++.h>

using namespace std;

const int TRUE = true;
const int FALSE = false;

int memo[100][100]; // capacita residua x numero elementi array

bool fun(vector<int> a, int x, int i, int num_objects){
    if(memo[x][i] != -1)
        return memo[x][i];

    if(num_objects == 2 && x == 0)
        return TRUE;

    if(num_objects > 2 || i>=a.size())
        return FALSE;

    return memo[x][i] = fun(a, x - a.at(i), i + 1, num_objects + 1)
        || fun(a, x, i + 1, num_objects);
} // COMPLESSITA : O(x * a.size())

int main() {
    vector<int> a = {0, -1, 2, -3, 1};
    vector<int> b = {1, -2, 1, 0, 5};

    int x = 0;

    memset(memo, false, sizeof memo);

    if(fun(b, x, 0, 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
