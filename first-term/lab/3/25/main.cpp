#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 30);

vector <int> d;
vector <bool> used;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("nextchoose.in", "rt", stdin);
    freopen("nextchoose.out", "wt", stdout);
#endif
    int n, k;
    cin >> n >> k;
    d.resize(n);
    used.resize(n + 10);
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < k; i++) {
        used[d[i]] = true;
    }
    int val = -1, index = -1;
    for (int i = k - 1; i >= 0; i--) {
        int x = -1;
        for (int j = d[i] + 1; j <= n; j++) {
            if (!used[j]) {
                x = j;
                break;
            }
        }
        if (x != -1) {
            val = x;
            index = i;
            break;
        }
    }
    if (index == -1 || val == -1) {
        cout << -1;
        return 0;
    }
    for (int i = index; i < n; i++) {
        used[d[i]] = false;
    }
    d[index] = val;
    used[val] = true;
    int last = val;
    for (int i = index + 1; i < k; i++) {
        int cur = -1;
        for (int j = last; j <= n; j++) {
            if (!used[j]) {
                cur = j;
                break;
            }
        }
        if (cur == -1) {
            cout << -1;
            return 0;
        }
        used[cur] = true;
        d[i] = cur;
        last = cur;
    }
    for (int i = 0; i < k; i++) {
        cout << d[i] << ' ';
    }
    return 0;
}
