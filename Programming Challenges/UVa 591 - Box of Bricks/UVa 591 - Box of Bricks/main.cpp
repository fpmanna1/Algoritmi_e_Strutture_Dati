#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum_elements(vector<int> vet){
    int sum = 0;
    for(int i=0; i<vet.size(); i++)
        sum += vet.at(i);

    return sum;
}

int min_moves(vector<int> stacks){

    int obj = sum_elements(stacks) / stacks.size();

    /*
    sort(stacks.begin(), stacks.end());

    int index = distance(stacks.begin(), upper_bound(stacks.begin(), stacks.end(), obj));

    int count = 0;
    for(int i=index; i<stacks.size(); i++)
        count += stacks.at(i) - obj;

    return count;

     */

    vector<int> differences(stacks.size());
    for(int i=0; i<differences.size(); i++)
        differences.at(i) = stacks.at(i) - obj;

    int sum = 0;
    for(int i=0; i<differences.size(); i++)
        sum += abs(differences.at(i));

    return sum/2;

} // 1) O(n log n), 2) O(n)

int main() {

    int num_stacks;
    int i=1;
    cin >> num_stacks;
    while(num_stacks!=0) {
        vector<int> stacks(num_stacks);

        for (int i = 0; i < num_stacks; i++)
            cin >> stacks.at(i);

        cout << "SET #"<<i<<endl;
        cout << "The minimum number of moves is "<<min_moves(stacks)<<endl;

        cin >> num_stacks;
    }

    return 0;
}
