#include <bits/stdc++.h>

using namespace std;

vector <int> d;

void gen(int l, int r, int len, bool mir) {
	if (l == r) {
		for (int i = 0; i < int(d.size()); i++) {
			cout << d[i];
		}
		cout << "\n";
	} else {
		int m = (l + r) / 2;
		d[len] = int(mir);
		gen(l, m, len + 1, 0);
		d[len] = int(!mir);
		gen(m + 1, r, len + 1, 1);
	}
}

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#else
		freopen("gray.in", "rt", stdin);
		freopen("gray.out", "wt", stdout);
	#endif
	int n;
	cin >> n;
	d.resize(n);
	gen(0, (1 << n) - 1, 0, false);
	return 0;
}