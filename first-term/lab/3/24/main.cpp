#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 30);

vector <int> d, nx;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("nextperm.in", "rt", stdin);
		freopen("nextperm.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    d.resize(n);
    nx.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        nx[i] = d[i];
    }
    for (int i = n - 1; i >= 1; i--) {
        if (d[i - 1] > d[i]) {
            int mx = -1;
            int id = -1;
            for (int j = n - 1; j >= i; j--) {
                if (d[j] < d[i - 1]) {
                    mx = max(mx, d[j]);
                    if (d[j] == mx) {
                        id = j;
                    }
                }
            }
            swap(d[i - 1], d[id]);
            reverse(d.begin() + i, d.end());
            break;
        }
    }
    int ccc = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == nx[i]) {
            ccc++;
        }
    }
    if (ccc == n) {
        for (int i = 0; i < n; i++) {
            d[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
        d[i] = nx[i];
    }
    cout << "\n";
    for (int i = n - 1; i >= 1; i--) {
        int mn = INF;
        if (d[i] > d[i - 1]) {
            int id = -1;
            for (int j = n - 1; j >= i; j--) {
                if (d[j] > d[i - 1]) {
                    mn = min(mn, d[j]);
                    if (d[j] == mn) {
                        id = j;
                    }
                }
            }
            swap(d[i - 1], d[id]);
            reverse(d.begin() + i, d.end());
            break;
        }
    }
    ccc = 0;
    for (int i = 0; i < n; i++) {
        if (d[i] == nx[i]) {
            ccc++;
        }
    }
    if (ccc == n) {
        for (int i = 0; i < n; i++) {
            d[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
        d[i] = nx[i];
    }
    return 0;
}
