#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	vector<bool> dp(n + 1, false);
	dp[0] = true;
	for (int i = 0; i < n; ++i) {
		if (i - ar[i] >= 0 && dp[i - ar[i]]) {
			dp[i + 1] = true;
		}

		if (!dp[i]) continue;

		if (i + ar[i] + 1 <= n) {
			dp[i + ar[i] + 1] = true;
		}
	}
	// 2 1 2 [3] 2 1 3
	if (dp[n]) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
