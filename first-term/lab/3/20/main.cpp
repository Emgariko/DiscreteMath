/*#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <vector<vector<ll>>> dp;
string s;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("brackets2num2.in", "rt", stdin);
    freopen("brackets2num2.out", "wt", stdout);
#endif
    cin >> s;
    int n = s.length();
    dp.resize(2 * n + 5, vector<vector<ll>>(2 * n + 5, vector<ll>(2 * n + 5, 0)));
   	dp[0][0][0] = 1;
   	for (int i = 1; i <= n; i++) {
   		for (int j = 0; j <= n; j++) {
   			for (int k = 0; k <= n; k++) {
   				if (j > 0)
   					dp[i][j][k] += dp[i - 1][j - 1][k];
   				dp[i][j][k] += dp[i - 1][j + 1][k];
   				if (k > 0)
   					dp[i][j][k] += dp[i - 1][j][k - 1];
   				dp[i][j][k] += dp[i - 1][j][k + 1];
   			}
   		}
   	}
    ll cnt = 0, bal1 = 0, bal2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
        	bal1++;
        } else if (s[i] == ')') {
        	cnt += dp[n - i - 1][bal1 + 1][bal2];
        	bal1--;
        } else if (s[i] == '[') {
        	cnt += dp[n - i - 1][bal1 + 1][bal2];
        	if (bal1 > 0)
        		cnt += dp[n - i - 1][bal1 - 1][bal2];
        	bal2++;
        } else if (s[i] == ']') {
        	cnt += dp[n - i - 1][bal1 + 1][bal2] +
        	dp[n - i - 1][bal1][bal2 + 1];
        	if (bal1 > 0)
        		cnt += dp[n - i - 1][bal1 - 1][bal2];
        	bal2--;
        }
    }
    cout << cnt;
    return 0;
}*/
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
