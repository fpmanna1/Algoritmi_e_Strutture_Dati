#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n,min,currentCalc;
    cin >> n;

    while (n != 0) {
        min = INT32_MAX;
        for ( int i = 0; i < 31; i++) {
            for ( int j = 0; j < 31; j++) {
                currentCalc = pow(2,i) * pow(3,j);
                if (currentCalc >= n && currentCalc < min) {
                    min = currentCalc;
                    break;
                }
            }
        }
        cout << min << endl;
        cin >> n;
    }

    return 0;
}
