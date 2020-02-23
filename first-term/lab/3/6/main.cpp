#include <bits/stdc++.h>

using namespace std;

vector <int> d;
vector <vector<int>> ans;

int main() {
    #ifdef HOME
        freopen("input.txt", "rt", stdin);
    #else
        freopen("vectors.in", "rt", stdin);
        freopen("vectors.out", "wt", stdout);
    #endif
    int n;
    cin >> n;
    d.resize(n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = n - 1; j >= 0; j--) {
            int x = i & (1 << j);
            d[n - 1 - j] = x >> j;
        }
        bool ok = false;
        for (int j =  0; j < n - 1; j++) {
        	if (d[j] == 1 && d[j + 1] == 1) { break; }
        	if (j == n - 2) {
        		ok = true;
        	}
        }
        if (ok) {
        	ans.push_back(d);
        }
    }
    cout << int(ans.size()) << "\n";
    for (auto i : ans) {
        for (auto j : i) {
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}
