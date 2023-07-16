#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	string s;
	cin >> s;
	int val = 0;
	for (int i = 0; i < s.size(); ++i) {
		val = 10 * val + s[i] - '0';
		val %= 97;
	}
	if (val == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
