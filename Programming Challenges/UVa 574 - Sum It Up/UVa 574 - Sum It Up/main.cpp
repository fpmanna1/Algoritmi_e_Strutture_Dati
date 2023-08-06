#include<cstdio>
#include<map>
#include<vector>

using namespace std;

int t, n;
int ar[20];
map<vector<int>, bool > solutions;
// vector int contiene la sequenza di numeri della soluzione
// bool mi dice se ho già trovato quella sequenza
vector<int> v;

void search(int k, int m, int sum, vector<int> v) {
    /*
     * v è una soluzione
     */
    if(sum == t) {
        if(solutions[v] == true) // se la soluzione v che ho trovato era già stata trovata in precedenza
            return;
        solutions[v] = true;
        // stampa della soluzione
        for(int i = 0; i < k; i++){
            if(i == k-1)
                printf("%d", v[i]);
            else
                printf("%d+", v[i]);

        }
        printf("\n");
        return;
    }
    if(sum > t || m == n)
        return;
    for(int i = m; i < n; i++) {
        v.push_back(ar[i]);
        search(k + 1, i + 1, sum + ar[i], v);
        v.pop_back();
    }
}

int main() {
    for(;;) {
        scanf("%d %d", &t, &n);
        if(t == 0 && n == 0) break;
        for(int i = 0; i < n; i++)
            scanf("%d", &ar[i]);
        solutions.clear();
        printf("Sums of %d:\n", t);
        search(0, 0, 0, v);
        if(solutions.size() == 0) printf("NONE\n");
    }
}