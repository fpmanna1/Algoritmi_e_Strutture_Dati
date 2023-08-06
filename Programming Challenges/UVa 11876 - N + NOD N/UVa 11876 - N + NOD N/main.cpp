#include <iostream>
#include <algorithm>

using namespace std;

int find_nod(int n){
    int count = 0;

    for(int i=n; i>=1; i--){
        if(n % i == 0)
            count++;
    }
    return count;
}

int f(int low, int high){
        int value = 1;
        int count = 0;

        while(true){
            if(value >= low && value <= high)
                count++;
            if(value >= high)
               break;
            value = value + find_nod(value);
        }

        return count;
}

int main() {

    int t;
    cin >> t;
    while(t--){
        int i = 1;

        int low;
        int high;

        cin >> low >> high;

        cout << "Case " << i++ << ": " << f(low, high) << endl;
    }

    return 0;
}
