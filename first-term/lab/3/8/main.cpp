#include <bits/stdc++.h>

using namespace std;

vector <int> d;
vector <bool> used;

void gen(int l, int k, int last) {
	if (l == k) {
		for (int i = 0; i < l ;i++) {
			cout << d[i] + 1 << ' ';
		}
		cout << "\n";
	} else {
		for (int i = last; i < int(d.size()); i++) {
			if (!used[i]) {
				d[l] = i;
				used[i] = true;
				gen(l + 1, k, i);
				used[i] = false;
			}
		}
	}
}

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#else
		freopen("choose.in", "rt", stdin);
		freopen("choose.out", "wt", stdout);
	#endif
	int n, k;
	cin >> n >> k;
	d.resize(n);
	used.resize(n, false);
	gen(0, k, 0);
	return 0;
}


// 1 2 
// 1 3
// 1 4
// 1 5
// 2 3
// 2 4
// 2 5
// 3 4