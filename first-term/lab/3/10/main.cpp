#include <bits/stdc++.h>

using namespace std;

vector <int> d;

void gen(int sum, int last, int l) {
    if (sum == 0) {
        for (int i = 0; i < l; i++) {
            cout << d[i];
            if (i != l - 1) {
                cout << '+';
            }
        }
        cout << "\n";
    } else {
        for (int i = last; i <= sum; i++) {
            d[l] = i;
            gen(sum - i, i, l + 1);
            d[l] = -1;
        }
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("partition.in", "rt", stdin);
    freopen("partition.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    d.resize(n);
    gen(n, 1, 0);
    return 0;
}
