#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> d, t;
vector <bool> used;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("perm2num.in", "rt", stdin);
    freopen("perm2num.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    used.resize(n + 1);
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    t.resize(n + 1);
    t[0] = 1;
    t[1] = 1;
    for (int i = 2; i <= n; i++) {
        t[i] = t[i - 1] * i;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cnt = 0;
        for (int j = 1; j < d[i]; j++) {
            if (!used[j])
                cnt++;
        }
        ans += cnt * t[n - i - 1];
        used[d[i]] = true;
    }
    cout << ans;
    return 0;
}
