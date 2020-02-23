#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <vector<ll>> dp;
string s;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("brackets2num.in", "rt", stdin);
    freopen("brackets2num.out", "wt", stdout);
#endif
    cin >> s;
    int n = s.length();
    dp.resize(2 * n + 5, vector<ll>(2 * n + 5, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= 1)
                dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j + 1];
        }
    }
    ll cnt = 0, bal = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            bal++;
        }
        else {
            cnt += dp[n - i - 1][bal + 1];
            bal--;
        }
    }
    cout << cnt;
    return 0;
}
