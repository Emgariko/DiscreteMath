#include <bits/stdc++.h>

using namespace std;

vector <int> d;
vector <bool> used;

void gen(int l, int k) {
	if (l == k) {
		for (int i = 0; i < l ;i++) {
			cout << d[i] + 1 << ' ';
		}
		cout << "\n";
	} else {
		for (int i = 0; i < int(d.size()); i++) {
			if (!used[i]) {
				used[i] = true;
				d[l] = i;
				gen(l + 1, k);
				used[i] = false;
			}
		}
	}
}

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#else
		freopen("permutations.in", "rt", stdin);
		freopen("permutations.out", "wt", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	d.resize(n);
	used.resize(n, false);
	gen(0, k);
	return 0;
}
