#include <bits/stdc++.h>

using namespace std;

vector <int> d;
set <vector<int>> ans;
vector <int> buf;

void gen(int l, int n) {
    if (l == n) {
        buf.clear();
        for (int i = 0; i < n; i++) {
            if (d[i] != -1) {
                buf.push_back(i + 1);
            }
        }
        ans.insert(buf);
    } else {
        d[l] = -1;
        gen(l + 1, n);
        d[l] = 0;
        gen(l + 1, n);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("subsets.in", "rt", stdin);
    freopen("subsets.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    d.resize(n);
    gen(0, n);
    for (auto it : ans) {
        for (auto j : it) {
            cout << j << ' ';
        }
        cout << "\n";
    }
    return 0;
}