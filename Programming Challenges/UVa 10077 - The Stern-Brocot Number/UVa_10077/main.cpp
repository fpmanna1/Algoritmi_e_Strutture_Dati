#include <iostream>

using namespace std;

struct frazione {
    int num;
    int den;
};

void stern_brocot(frazione oracolo, frazione left, frazione curr, frazione right);
bool equals(frazione a, frazione b);

int main() {

    frazione oracolo = {0, 0};
    frazione left = {0, 1};;
    frazione right = {1, 0};
    frazione curr = {1, 1};

    while(!(oracolo.num == 1 && oracolo.den ==1)){
        cin >> oracolo.num >> oracolo.den;
        stern_brocot(oracolo, left, curr, right);
        cout << endl;
    }

    return 0;
}

void stern_brocot(frazione oracolo, frazione left, frazione curr, frazione right){
    if(equals(oracolo, curr))
        return;

    if((double)oracolo.num/oracolo.den < (double)curr.num/curr.den) {
        right = curr;
        cout << "L";

        curr.num += left.num;
        curr.den += left.den;

        //stern_brocot(oracolo, left ,curr, right);
    } else {
        left = curr;
        cout << "R";

        curr.num += right.num;
        curr.den += right.den;

        //stern_brocot(oracolo, left, curr, right);
    }
	stern_brocot(oracolo, left ,curr, right);

} // complessita O(n)

bool equals(frazione a, frazione b){
    return (a.den == b.den) && (b.num == a.num);
}

