#include <bits/stdc++.h>

using namespace std;

string s;
vector <int> bal;

int main() {
#ifdef HOME
    freopen("input.txt", "rt", stdin);
#else
    freopen("nextbrackets.in", "rt", stdin);
		freopen("nextbrackets.out", "wt", stdout);
#endif
    cin >> s;
    int n = s.length();
    bal.resize(n);
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') { b++; } else {b --;}
        bal[i] = b;
    }
    /*	01234567
    n - 1 - i
    (((())))
    ((()
    bal = 2
    12343210 */
    int index = -1;
    for (int i = n - 1; i >= 0; i--) {
        int x = bal[i];
        if (s[i] == '(' && x > 1) {
            if (x <= n - i - 1) {
                index = i;
                break;
            }
        }
    }
    if (index == -1) {
        cout << "-";
        return 0;
    }
    s[index] = ')';
    bal[index] -= 2;
    b = bal[index];
    for (int i = 0; i <= index; i++) {
        cout << s[i];
    }
    for (int i = index + 1; i < n; i++) {
        if (b + 1 <= n - i - 1) {
            cout << "(";
            b++;
        } else {
            cout << ")";
            b--;
        }
    }
    return 0;
}
