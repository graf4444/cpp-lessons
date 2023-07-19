#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	/*
	 * Кузнечик стоит на числовой прямой в точке 0 и может прыгать только направо максимум на k клеток.
	 * Но некоторые клетки непроходимы. Каким количеством способов он может добраться до клетки n
	 */
	int n, m, k;
	cin >> n >> m >> k;
	vector<bool> ok(n + 1, true);
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		ok[v] = false;
	}
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		if (!ok[i]) continue;
		// i - k, i - k + 1, ..., i - 1
		for (int j = max(0, i - k); j < i; ++j) {
			if (!ok[j]) continue;
			dp[i] += dp[j];
		}
	}
	// O(nk)

	cout << dp[n] << endl;
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
