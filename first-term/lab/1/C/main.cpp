#include <bits/stdc++.h>

using namespace std;

vector <int> d;
vector <string> a;
bool kek[5];

bool nul(int i) {
	return a[i][0] == '0';
}

bool one(int i) {
	return a[i][(1 << d[i]) - 1] == '1';
}

bool s2(int i) {
	for (int j = 0; j < (1 << d[i]); j++) {
		if (a[i][j] == a[i][(1 << d[i]) - j - 1]) {
			return false;
		}
	}
	return true;
}

string tobin(int x, int kk){
 	string res = "";
 	while(x > 0) {
   		res = res + char('0' + x % 2);
   		x /= 2;
 	}
 	int ll = res.length();
 	for (int i = 0; i < int(d[kk] - ll); i++) {
 		res.push_back('0');
 	}
 	reverse(res.begin(), res.end());
 	return res;
}

bool mon(int i) {
	for (int j = 0; j < (1 << d[i]); j++) {
		for (int k = 0; k < (1 << d[i]); k++) {
			
			string jj = tobin(j, i);
			string kk = tobin(k, i);			
			//cout << jj << ' ' << kk << "\n";
			//cout << jj << ' ' << kk << ' ' << a[i][j] << ' ' << a[i][k] << "\n";
			bool eq = true;
			for (int t = 0; t < int(jj.length()); t++) {
				if (jj[t] <= kk[t]) continue;
				eq = false;
			}
			if (a[i][j] > a[i][k] && eq)
				return false;
		}
	}
	return true;
}

bool lin(int i) {
	vector <vector<int>> dd((1 << d[i]), vector<int>((1 << d[i])));
	for (int j = 0; j < (1 << d[i]); j++) {
		dd[0][j] = int(a[i][j] - '0'); 
	}
	for (int j = 1; j < (1 << d[i]); j++) {
		for (int k = 0; k < (1 << d[i]) - j; k++) {
			dd[j][k] = (dd[j - 1][k] + dd[j - 1][k + 1]) % 2;
		}
	}
	int x = 1;
	for (int j = 1; j < (1 << d[i]); j++) {
		if (x != j && dd[j][0] != 0) {
			return false;
		}
		if (x == j) {
			x *= 2;
		}
	}
	return true;
}

int main() {
	#ifdef HOME
		freopen("input.txt", "rt", stdin);
	#endif
	int n;
	cin >> n;	
	d.resize(n);
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i] >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		kek[i] = false;
	}
	for (int i = 0; i < n; i++) {
		if (!nul(i)) {
			kek[0] = true;			
		}
		if (!one(i)) {
			kek[1] = true;			
		}
		if (!s2(i)) {
			kek[2] = true;
		}
		if (!mon(i)) {
			kek[3] = true;			
		}
		if (!lin(i)) {
			kek[4] = true;			
		}
		///cout << nul(i) << one(i) << s2(i) << mon(i) << lin(i);
	}
	if (kek[0] && kek[1] && kek[2] && kek[3] && kek[4]) 
		cout << "YES";
	else
		cout << "NO";
	return 0;
}
