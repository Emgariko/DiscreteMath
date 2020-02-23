#include <bits/stdc++.h>

using namespace std;

vector <char> d;

void gen(int l, int k, int bal) {
    if (l == k) {
        for (int i = 0; i < k; i++) {
            cout << d[i];
        }
        cout << "\n";
    } else {
        if (k - l - 1 >= bal) {
            d[l] = '(';
            gen(l + 1, k, bal + 1);
        }
        if (bal > 0) {
            d[l] = ')';
            gen(l + 1, k, bal - 1);
        }
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("brackets.in", "rt", stdin);
    freopen("brackets.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    d.resize(2 * n);
    gen(0, 2 * n, 0);
    return 0;
}
