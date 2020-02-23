#include <bits/stdc++.h>

using namespace std;

const int INF = (1 << 30);

vector <int> d, nx;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("nextmultiperm.in", "rt", stdin);
    freopen("nextmultiperm.out", "wt", stdout);
#endif
    int n;
    cin >> n;
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int index = -1;
    for (int i = n - 1; i > 0; i--) {
        if (d[i - 1] < d[i]) {
            index = i - 1;
            break;
        }
    }
    if (index == -1) {
        for (int i = 0; i < n; i++) {
            cout << 0 << ' ';
        }
        return 0;
    }
    int j = index + 1;
    while (j < n - 1 && d[j + 1] > d[index]) {
        j++;
    }
    swap(d[index], d[j]);
    reverse(d.begin() + index + 1, d.end());
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
    }
    return 0;
}
