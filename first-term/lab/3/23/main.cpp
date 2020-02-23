#include <bits/stdc++.h>

using namespace std;

string s;
string pr, nx;

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#else
		freopen("nextvector.in", "rt", stdin);
		freopen("nextvector.out", "wt", stdout);
	#endif
	cin >> s;
	int z = 0, o = 0;
	int n = s.length();
	pr = s;
	nx = s;
	for (int i = 0; i < n; i++) {
		if (s[i] != '0')
			o++;
		else
			z++;
	}
	if (z == n) {
		cout << "-\n";
		for (int i = 0; i < n - 1; i++) {
			cout << 0;
		}
		cout << 1;
	} else if (o == n) {
		for (int i = 0; i < n - 1; i++) {
			cout << 1;
		}
		cout << "0\n";
		cout << "-";
	} else {
		int j = n - 1;
		while (s[j] == '1') {
			nx[j] = '0';
			j--;
		}
		nx[j] = '1';
		j = n - 1;
		while (s[j] == '0') {
			pr[j] = '1';
			j--;
		}
		pr[j] = '0';
		cout << pr << "\n" << nx;
	}
	return 0;
}