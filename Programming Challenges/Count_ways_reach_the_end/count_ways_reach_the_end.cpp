/*
 * Given an array of numbers where each element represents the
 * max number of jumps that can be made forward from that element.
 * For each array element, count the number of ways jumps can be made
 * from that element to reach the end of the array. If an element is 0,
 * then a move cannot be made through that element.
 * The element that cannot reach the end should have a count “-1“.

Examples:

Input: {3, 2, 0, 1}
Output: 2 1 -1 0
Explanation:

For 3 number of steps or jumps that can be taken are 1, 2 or 3.
 The different ways are:
3 -> 2 -> 1
3 -> 1
For 2 number of steps or jumps that can be taken are 1, or 2.
 The different ways are:
2 -> 1
For 0 number of steps or jumps that can be taken are 0.
 One cannot move forward from this point.
For 1 number of steps or jumps that can be taken are 1.
 But the element is at the end so no jump is required.
Input: {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9}
Output: 52 52 28 16 8 -1 -1 4 2 1 0
 */
// C++ implementation to count number
// of ways to jump to reach end
#include <bits/stdc++.h>
using namespace std;

// function to count ways to jump to
// reach end for each array element
void countWaysToJump(int arr[], int n)
{
    // count_jump[i] store number of ways
    // arr[i] can reach to the end
    int count_jump[n];
    memset(count_jump, 0, sizeof(count_jump));

    // Last element does not require to jump.
    // Count ways to jump for remaining
    // elements
    for (int i=n-2; i>=0; i--)
    {
        // if the element can directly
        // jump to the end
        if (arr[i] >= n - i - 1)
            count_jump[i]++;

        // add the count of all the elements
        // that can reach to end and arr[i] can
        // reach to them
        for (int j=i+1; j < n-1 && j <= arr[i] + i; j++)

            // if element can reach to end then add
            // its count to count_jump[i]
            if (count_jump[j] != -1)
                count_jump[i] += count_jump[j];

        // if arr[i] cannot reach to the end
        if (count_jump[i] == 0)
            count_jump[i] = -1;
    }

    // print count_jump for each
    // array element
    for (int i=0; i<n; i++)
        cout << count_jump[i] << " ";
} // COMPLESSITA : O(n^2)

// Driver program to test above
int main()
{
    int arr[] = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    countWaysToJump(arr, n);
    return 0;
}


