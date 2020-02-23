#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <vector<int>> a, b;
vector <int> buf;



void gen(int n, int t) {
    if (t == n) {
        a.push_back(buf);
    } else {
        buf[1 + t] = 0;
        gen(n, t + 1);
        buf[1 + t] = 1;
        gen(n, t + 1);
        buf[1 + t] = 2;
        gen(n, t + 1);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("antigray.in", "rt", stdin);
    freopen("antigray.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    buf.resize(n);
    gen(n - 1, 0);
    for (int i = n - 1; i < n; i++) {
        b.clear();
        for (int j = 0; j < int(a.size()); j++) {
            b.push_back(a[j]);
            b.push_back(a[j]);
            b.push_back(a[j]);
        }
        int cnt = 0;
        for (int k = 0; k < int(b.size()); k++) {
            int val = cnt % 3;
            for (int t = n - 1; t >= 0; t--) {
                b[k][t] = (b[k][t] + val) % 3;
            }
            cnt++;
        }
        a.swap(b);
    }
    for (int i = 0; i < int(a.size()); i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}