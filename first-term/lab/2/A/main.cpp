#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <ll> d, h;
set <pair<ll, ll>> a;
vector <vector<ll>> g;
int ind;

void build() {
    int n = d.size();
    //p.resize(3 * n);
    g.resize(3 * n);
    h.resize(3 * n);
    ind = n;
    for (int i = 0; i < n; i++) {
        a.insert({d[i], i});
    }
    while (true) {
        if (a.size() == 1) {
            break;
        }
        auto m1 = *a.begin();
        a.erase(a.begin());
        auto m2 = *a.begin();
        a.erase(a.begin());
        g[ind].push_back(m1.second);
        g[ind].push_back(m2.second);
        pair<ll, ll> y = {m1.first + m2.first, ind};
        a.insert(y);
        ind++;
    }
}

void dfs(int u) {
    for (auto v : g[u]) {
        h[v] = h[u] + 1;
        dfs(v);
    }
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
   	freopen("huffman.in", "rt", stdin);
   	freopen("huffman.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    build();
    h[ind - 1] = 0;
    dfs(ind - 1);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        //cout << h[i] << ' ';
        sum += d[i] * h[i];
    }
    //cout << "\n";
    cout << sum;
    return 0;
}
