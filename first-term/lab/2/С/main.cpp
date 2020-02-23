#include <bits/stdc++.h>

using namespace std;

const int K = 26;

string s;
vector <int> d;

int get(int x) {
    return d[x];
}

void edit(int x) {
    for (int i = 0; i < K; i++) {
        if (d[i] < d[x]) {
            d[i]++;
        }
    }
    d[x] = 0;
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("mtf.in", "rt", stdin);
    freopen("mtf.out", "wt", stdout);
#endif
    cin >> s;
    int n = s.length();
    d.resize(K);
    for (int i = 0; i < K; i++) {
        d[i] = i;
    }
    for (int i = 0; i < n; i++){
        int x = s[i] - 'a';
        int y = get(x);
        cout << y + 1 << ' ';
        edit(x);
    }
    return 0;
}
