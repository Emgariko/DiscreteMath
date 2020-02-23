#include <bits/stdc++.h> 

using namespace std;

vector <vector<int>> d;
vector <string> a;

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#endif
	int k;
	cin >> k;
	int n = (1 << k);
	d.resize(n, vector<int>(n, 0));
	a.resize(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> a[i] >> c;
		d[0][i] = int(c - '0');
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			d[i][j] = (d[i - 1][j] + d[i - 1][j + 1]) % 2; 
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ' << d[i][0] << "\n";
	}
	return 0;
}