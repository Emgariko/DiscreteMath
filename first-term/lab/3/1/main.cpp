#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#else
		freopen("allvectors.in", "rt", stdin);
		freopen("allvectors.out", "wt", stdout);
	#endif
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		for (int j = n - 1; j >= 0; j--) {
			int x = i & (1 << j);
			cout << (x >> j);
		}
		cout << "\n";
	}
	return 0;
}