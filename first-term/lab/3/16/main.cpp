#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> d, t;
vector <vector<ll>> kek;
vector <bool> used;
/*
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
}*/

void prec(int n) {
    kek[0][0] = 1ll;
    for (int i = 1; i <= n; i++) {
        kek[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            kek[i][j] = kek[i - 1][j - 1] + kek[i - 1][j];
        }
    }
}

ll val(int n, int k) {
    return kek[n][k];
}

void gen(int x, int n, int m, ll k, int from) {
    if (x == m) {
        for (int i = 0; i < m; i++) {
            cout << d[i] << ' ';
        }
    } else {
        int kk = k;
        for (int c = from; c <= n; c++) {
            d[x] = c;
            ll cnt = val(n - c, m - x - 1);
            if (cnt <= kk) {
                kk -= cnt;
            } else {
                gen(x + 1, n, m, kk, c + 1);
                break;
            }
        }
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("choose2num.in", "rt", stdin);
    freopen("choose2num.out", "wt", stdout);
#endif
    int n;
    ll k;
    cin >> n >> k;
    d.resize(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> d[i];
    }
    kek.resize(n + 1, vector<ll>(n + 1, 0));
    prec(n);
    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = d[i - 1] + 1; j <= d[i] - 1; j++) {
            ans += kek[n - j][k - i];
        }
    }
    cout << ans;
    return 0;
}