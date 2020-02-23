#include <bits/stdc++.h>

using namespace std;

/*vector <vector<int>> d;
vector <int> cnt;
vector <int> val;
vector <bool> init;
vector <vector<bool>> ig;
vector <bool> skip;
*/

vector <vector<int>> d;
vector <int> val;

bool calc(int i) {
    bool res = false;
    for (int j = 0; j < int(val.size()); j++) {
        if (val[j] == 0 && d[i][j] == 0) {
            res = true;
            break;
        }
        if (val[j] == 1 && d[i][j] == 1) {
            res = true;
            break;
        }
    }
    return res;
}

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#endif
    int n, k;
    cin >> n >> k;
    val.resize(n);
    d.resize(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        val[i] = 0;
    }
    double t = clock();
    while (true) {
        t = clock();
        //cout << double(t / CLOCKS_PER_SEC) << "\n";
        if (t / CLOCKS_PER_SEC >= 1.5) {
            cout << "YES";
            return 0;
        }
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            bool ok = calc(i);
            if (!ok) {
                for (int j = 0; j < n; j++) {
                    if (val[j] == 1 && d[i][j] == 1) {
                        cout << "YES";
                        return 0;
                    }
                    if (val[j] == 0 && d[i][j] == 1) {
                        val[j] = 1;
                        break;
                    }
                }
            } else {
                cnt++;
            }
        }
        if (cnt == k) {
            cout << "NO";
            return 0;
        }
    }
    cout << "NO";
    /*cnt.resize(k, n);
    val.resize(n);
    used.resize(n);
    skip.resize(n);
    init.resize(n, -1);
    ig.resize(k, vector<bool>(n, false));
    d.resize(k, vector<int>(n));
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
            if (d[i][j] == 0) {
                cnt[i]--;
            }
        }
    }
    while (true) {
        for (int i = 0; i < k; i++) {
            if (cnt[i] == 1 && !skip[i]) {
                for (int j = 0; j < n; j++) {
                    if (ig[i][j]) continue;
                    if (d[i][j] == 1) {
                        if (val[j] == 0) {
                            cout << "YES";
                            return 0;
                        }
                        val[j] = 1;
                        init[j] = true;
                    } else if (d[i][j] == -1) {
                        if (val[j] == 1) {
                            cout << "YES";
                            return 0;
                        }
                        val[j] = 0;
                        init[j] = true;
                    }
                }
            }
        }
        for (int i = 0; i < k; i++) {
            int count = 0, sz = 0;
            for (int j = 0; j < n; j++) {
                if (ig[i][j])
                if (init[j] == -1) continue;
                if (d[i][j] == -1 && val[j] == 1) {
                    count++;
                }
                if (d[i][j] == 1 && val[j] == 0) {
                    count++;
                }
            }
            if (count == n) {
                cout << "YES";
                return 0;
            }
        }
        // скобка 1 - игнор. переменная 0 - игнор

    }*/
    return 0;
}
