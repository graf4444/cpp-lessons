#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	vector<int> pref(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = pref[i];
		if (s[i] >= 'a' && s[i] <= 'z') {
			pref[i + 1]++;
		}
	}

	// suf[i] = (n - i) - (pref[n] - pref[i])

	vector<int> suf(n + 1);
	suf[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		suf[i] = suf[i + 1];
		if (s[i] >= 'A' && s[i] <= 'Z') {
			suf[i]++;
		}
	}

	int ans = n;
	for (int i = 0; i <= n; ++i) {
		int cur = pref[i] + suf[i];
		ans = min(ans, cur);
	}
	cout << ans << endl;
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



// 2 5 3 1 4
// 2 7 10 11 15
// 10