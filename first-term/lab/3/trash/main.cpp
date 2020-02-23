#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;

int dp[MAXN][MAXN];

int main() {
	freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[1][1] = 1;
	for (int j = 1; j <= n; j++) {
		dp[1][j] = 1;
		dp[0][j] = 1;
	}
	for (int i = 0; i < n; i++) dp[i][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++)
			if (i - j >= 0)
				dp[i][j] = dp[i - j][j - 1] + dp[i][j - 1];
		for (int j = i + 1; j <= n; j++)
			dp[i][j] = dp[i][i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dp[i][j] << ' ';
		}
		cout << "\n";
	}
	return 0;
}