#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 30);

vector <int> d;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("nextpartition.in", "rt", stdin);
    freopen("nextpartition.out", "wt", stdout);
#endif
    int n, a;
    char x;
    cin >> n >> x;
    while (cin >> a) {
        d.push_back(a);
        cin >> x;
    }
    int cnt = int(d.size());
    if (cnt == 1) {
        cout << "No solution";
        return 0;
    }
    d[cnt - 1]--;
    d[cnt - 2]++;
    if (d[cnt - 1] < d[cnt - 2]) {
        d[cnt - 2] += d[cnt - 1];
        cnt--;
        cout << n << "=";
        for (int i = 0; i < cnt - 1; i++) {
            cout << d[i] << "+";
        }
        cout << d[cnt - 1];
        return 0;
    }
    while (d[cnt - 2] * 2 <= d[cnt - 1]) {
        d.push_back(d[cnt - 1] - d[cnt - 2]);
        d[cnt - 1] = d[cnt - 2];
        cnt++;
    }
    cout << n << "=";
    for (int i = 0; i < cnt - 1; i++) {
        cout << d[i] << "+";
    }
    cout << d[cnt - 1];
    return 0;
}
