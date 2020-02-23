#include <bits/stdc++.h>

using namespace std;

vector <vector<int>> a, b;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("telemetry.in", "rt", stdin);
    freopen("telemetry.out", "wt", stdout);
#endif
    int n, k;
    cin >> n >> k;
    a.resize(k, vector<int>(1));
    for (int i = 0; i < k; i++) {
        a[i][0] = i;
    }
    for (int t = 1; t < n; t++) {
        b.clear();
        int ssz = a.size();
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < ssz; j++) {
                a.push_back(a[j]);
            }
        }
        int id;
        for (int j = 0; j < k; j++) {
            if (j % 2 == 0) {
                for (int i = 0; i < ssz; i++) {
                    a[i + ssz * j].push_back(j);
                    b.push_back(a[i + ssz * j]);
                }
            } else {
                for (int i = ssz - 1; i >= 0; i--) {
                    a[i + ssz * j].push_back(j);
                    b.push_back(a[i + ssz * j]);
                }
            }
        }
        b.swap(a);
    }
    for (int i = 0; i < int(a.size()); i++) {
        for (int j = 0; j < int(a[i].size()); j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
