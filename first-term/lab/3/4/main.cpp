#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <vector<int>> d;
set<vector<int>> a;
vector <int> buf;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("chaincode.in", "rt", stdin);
    freopen("chaincode.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    d.push_back(vector<int>(n, 0));
    a.insert(d[0]);
    buf.resize(n);
    int cnt = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n - 1; j++) {
            buf[j] = d[cnt][j + 1];
        }
        buf[n - 1] = 1;
        if (a.find(buf) == a.end()) {
            a.insert(buf);
            d.push_back(buf);
            cnt++;
            continue;
        }
        buf[n - 1] = 0;
        if (a.find(buf) == a.end()) {
            a.insert(buf);
            d.push_back(buf);
            cnt++;
        } else {
            cnt++;
            break;
        }
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < int(d[i].size()); j++) {
            cout << d[i][j];
        }
        cout << "\n";
    }
    return 0;
}