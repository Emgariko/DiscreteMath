#include <bits/stdc++.h>

using namespace std;

vector <pair<int, int>> d;
vector <string> a;
set <pair<int, int>> g;
vector <bool> b;

void gen(int x) {
	if (x == int(b.size())) {
		int cnt = 0;
		for (int i = 0; i < int(d.size()); i++) {
			int x = d[i].first, y = d[i].second;
			bool xx, yy;
			if (x > 0 && y > 0) {
				xx = b[x - 1], yy = b[y - 1];
				if (xx | yy) {
					cnt++;
				}
			}
			if (x > 0 && y < 0) {
				xx = b[x - 1], yy = !b[abs(y) - 1];
				if (xx || yy) {
					cnt++;
				}
			}
			if (x < 0 && y > 0) {
				xx = !b[abs(x) - 1], yy = b[y - 1];
				if (xx || yy) {
					cnt++;
				}
			}
			if (x < 0 && y < 0) {
				xx = !b[abs(x) - 1], yy = !b[abs(y) - 1];
				if (xx || yy) {
					cnt++;
				}
			}
		}
		if (cnt == int(d.size())) {
			cout << "NO";
			exit(0);
		}
	} else {
		b[x] = 0;
		gen(x + 1);
		b[x] = 1;
		gen(x + 1);
	}
}

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#endif
	int n, m;
	cin >> n >> m;
	b.resize(n);
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		g.insert({x, y});
	}

	int id = 0;
	d.resize(int(g.size()));
	for (auto i : g) {
		d[id] = i;
		id++;
	}
	gen(0);
	cout << "YES";
	return 0;
}
