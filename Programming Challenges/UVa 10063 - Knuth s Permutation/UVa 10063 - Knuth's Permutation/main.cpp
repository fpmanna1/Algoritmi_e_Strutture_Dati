#include <iostream>
#include <algorithm>

using namespace std;

void generate_all_permutations(string str, string permutation, int k)
{
    if(k == str.size()){
        cout << permutation << endl;
        return;
    }else{
        char c = str[k];
        string temp;

        for(int i=0; i<=permutation.size(); i++){
            temp = permutation;
            temp.insert(temp.begin() + i, c);
            generate_all_permutations(str, temp, k+1);
        }
    }
}

int main() {

    int t = 3;

    while(t--){
        string str;
        cin >> str;

        generate_all_permutations(str, "", 0);
    }

    return 0;
}
