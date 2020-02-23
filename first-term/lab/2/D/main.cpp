#include <bits/stdc++.h>

using namespace std;

const int K = 26;

map <string, int> d;
string s, buf, buf1;
int ind = 27;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("lzw.in", "rt", stdin);
    freopen("lzw.out", "wt", stdout);
#endif
    cin >> s;
    int n = s.length();
    for (int i = 0; i < K; i++) {
        buf = char(i + 'a');
        d[buf] = i + 1;
    }
    buf.clear();
    buf = s[0];
    for (int i = 1; i < n; i++) {
        buf1 = buf + s[i];
        if (d[buf1] != 0) {
            buf = buf1;
        } else {
            cout << d[buf] - 1 << ' ';
            d[buf1] = ind++;
            buf.clear();
            buf = s[i];
        }
    }
    cout << d[buf] - 1;
    return 0;
}
