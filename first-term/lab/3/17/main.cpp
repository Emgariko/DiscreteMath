#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <vector<ll>> dp;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("num2brackets.in", "rt", stdin);
    freopen("num2brackets.out", "wt", stdout);
#endif
    int n;
    ll k;
    cin >> n >> k;
    dp.resize(2 * n + 5, vector<ll>(2 * n + 5, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= 2 * n; i++) {
    	for (int j = 0; j <= 2 * n; j++) {
    		if (j >= 1)
    			dp[i][j] += dp[i - 1][j - 1];
    		dp[i][j] += dp[i - 1][j + 1];
    	}
    }
    int bal = 0;
    k++;
    for (int i = 0; i < 2 * n; i++) {
    	//cout << k << "\n";
		ll x = k - dp[2 * n - i - 1][bal + 1];
		if (x <= 0) {
			cout << "(";
			//k -= dp[2 * n - i - 1][bal - 1];
			bal++;
		} else {
			cout << ")";
			k -= dp[2 * n - i - 1][bal + 1];
			bal--;
		}
	}
    return 0;
}