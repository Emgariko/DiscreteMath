#include <bits/stdc++.h>

using namespace std;

vector <string> d;
string s, buf;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
   	freopen("bwt.in", "rt", stdin);
   	freopen("bwt.out", "wt", stdout);
#endif
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        buf.clear();
        buf.resize(n);
        for (int j = 0; j < n; j++) {
            buf[j] = s[(i + j) % n];
        }
        d.push_back(buf);
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < n; i++) {
        cout << d[i][n - 1];
    }
    return 0;
}
