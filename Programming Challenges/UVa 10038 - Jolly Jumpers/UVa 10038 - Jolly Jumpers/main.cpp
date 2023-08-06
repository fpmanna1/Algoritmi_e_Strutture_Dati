#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isJolly(vector<int> numbers, int size){
    vector<bool> differences(size-1);

    for(int j=0; j<size-1; j++)
        differences.operator[](j) = false;
    unsigned int difference = 0;

    for(int i=0; i<numbers.size() - 1; i++){
        difference = abs(numbers.at(i+1) - numbers.at(i));
        if(difference > size-1 || differences.at(difference-1))
            return false;
        differences.operator[](difference-1) = true;
    }

    return true;
} // complessita O(n)

int main() {

    int size;
    int t = 2;
    while(t--) {
        cin >> size;
        vector<int> numbers(size);
        for (int i=0; i<size; i++) {
            cin >> numbers.operator[](i);
        }

        if (isJolly(numbers, size))
            cout << "Jolly" << endl;
        else
            cout << "Not Jolly" << endl;

    }

    return 0;
}
