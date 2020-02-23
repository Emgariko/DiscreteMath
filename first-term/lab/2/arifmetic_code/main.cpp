#include <bits/stdc++.h>

using namespace std;

const int K = 26;

string s;
vector <int> cnt;
vector <double> freq;
vector <double> pref;
int scnt = 0;

void init(string &s) {
	int n = s.length();
	cnt.resize(K);
	freq.resize(K);
	pref.resize(K + 1); // сумма на перфиксе длины i
	for (int i = 0; i < n; i++) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] != 0) {
			scnt++;
		}
	}
	for (int i = 0; i < 26; i++) {
		freq[i] = double(cnt[i]) / n;
	}
	for (int i = 1; i <= 26; i++) {
		pref[i] = pref[i - 1] + freq[i - 1];
	}
}

pair <double, double> code(string &s) {
	double l = 0, r = 1;
	int n = s.length();
	for (int i = 0; i < n; i++) {
		int x = s[i] - 'a';
		double len = r - l;
		double nl, nr;
		nl = pref[x] * len + l;
		nr = nl + len * freq[x];
		r = nr;
		l = nl;
		cout << l << ' ' << r << "\n";
	}
	return {l, r};
}

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#endif
	cin >> s;
	init(s);
	pair <double, double> res = code(s);
	/*cout << "\n";
	for (auto i : pref) {
		cout << i << ' ';
	}
	cout << "\n";*/
	cout << res.first << ' ' << res.second << "\n";
	return 0;
}