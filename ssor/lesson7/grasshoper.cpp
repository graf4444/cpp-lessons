#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	/*
	 * Кузнечик стоит на числовой прямой в точке 0 и может прыгать только направо максимум на k клеток.
	 * Каким количеством способов он может добраться до клетки n
	 */
	int n, k;
	cin >> n >> k;
	vector<int> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		// i - k, i - k + 1, ..., i - 1
		for (int j = max(0, i - k); j < i; ++j) {
			dp[i] += dp[j];
		}
	}
	// O(nk)

//	for (int i = 0; i < n; ++i) {
//		for (int j = i + 1; j <= min(i + k, n); ++j) {
//			dp[j] += dp[i];
//		}
//	}

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
