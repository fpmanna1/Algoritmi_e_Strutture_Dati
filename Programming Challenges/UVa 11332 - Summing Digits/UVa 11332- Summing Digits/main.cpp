#include <iostream>
#include <algorithm>

using namespace std;

int summing_digits(int num){
    int sum = 0;
    if(num < 10)
        return num;
    else{
        while(num != 0) {
            sum += num % 10; // 547 % 10 = 7, 54 % 10 = 4, 5 % 10 = 5
            num /= 10; // es. 547 - 54 - 5 - 0.5 ed esco
        }
        summing_digits(sum);
    }
}

int main() {

    int num;

    while(num!=0){
        cin >> num;
        cout << summing_digits(num) << endl;
    }

    return 0;
}
