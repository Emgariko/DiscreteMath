#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> d, t;
vector <bool> used;

void gen(int n, ll k, int x) {
    if (x == n) {
        for (int i = 0; i < n; i++){
            cout << d[i] << ' ';
        }
    } else {
        ll cnt = 0;
        cnt = k / t[(n - 1 - x)];
        int c = 0;
        for (int i = 1; i <= n; i++) {
            if (!used[i])
                c++;
            if (c == cnt + 1) {
                used[i] = true;
                d[x] = i;
                gen(n, k % t[(n - x - 1)], x + 1);
                break;
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("num2perm.in", "rt", stdin);
    freopen("num2perm.out", "wt", stdout);
#endif
    int n;
    ll k;
    cin >> n >> k;
    d.resize(n);
    t.resize(n + 1);
    t[0] = 1;
    t[1] = 1;
    for (int i = 2; i <= n; i++) {
        t[i] = t[i - 1] * i;
    }
    used.resize(n + 1);
    gen(n, k, 0);
    return 0;
}