#include <bits/stdc++.h>

using namespace std;

struct element {
    int in;
    vector <int> inp;
    vector <int> table;
    element (){}
    element (int a, vector<int> b, vector<int> table) {
        in = a;
        inp = b;
    }
};

vector <int> leaf;
vector <element> d;
vector <int> a;
vector <int> gg;

int calc(int v) {
    if (d[v].in == 0) {
        return 0;
    }
    int res = -1;
    for (int j = 0; j < int(d[v].inp.size()); j++) {
        res = max(res, calc(d[v].inp[j]));
        //cout << v << " ---> " << d[v].inp[j] << "\n";
    }
    //cout << "v = " << v << " depth = " << res << "\n";
    return res + 1;
}

/*int get_val(int v) {
    if (d[v].in == 0) {
        return a[gg[v]];
    }
    vector <int> buf(d[v].inp.size());
    for (int i = 0; i < int(d[v].inp.size()); i++) {
        buf[i] = get_val(d[v].inp[i]);
    }
    int x = d[v].in;
    int y = 0;
    int id = 0;
    for (int i = 0; i < x; i++) {
        id = id | ((buf[i]) << y);
        y++;
    }
    cout << "V = " << v << " res = " << d[v].table[id] << " ID = " << id << "\n";
    return d[v].table[id];
}
*/

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif
    int n;
    cin >> n;
    d.resize(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            leaf.push_back(i);
        }
        d[i].in = x;
        d[i].inp.resize(x);
        if (x == 0) continue;
        for (int j = x - 1; j >= 0; j--) {
            cin >> d[i].inp[j];
            d[i].inp[j]--;
        }
        d[i].table.resize((1 << x));
        for (int j = 0; j < (1 << x); j++) {
            int tt;
            cin >> tt;
            d[i].table[j] = tt;
        }
    }
    int depth = calc(n - 1);
    cout << depth << "\n";
    int m = leaf.size();
    a.resize(n);
    vector <int> buf;
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < m; j++) {
            int val = (i >> j) & 1;
            a[leaf[m - j - 1]] = val;
        }
        for (int j = 0; j < n; j++) {
            if (d[j].in == 0) continue;
            int x = 0;
            for (int k = 0; k < d[j].in; k++) {
                x = x + ((a[d[j].inp[k]]) << k);
            }
            a[j] = d[j].table[x];
        }
        cout << a[n - 1];
        for (int j = 0; j < n; j++) {
            a[j] = 0;
        }
        /*
        for (int j = 0; j < n; j++) {
            cout << a[j];
        }
        cout << "\n";*/
        /*int ans = get_val(n - 1);
        cout << ans;*/

    }
    return 0;
}
