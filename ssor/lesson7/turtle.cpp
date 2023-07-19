#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	/*
	 * Черепашка находится на клетчатом поле в левом верхнем углу, некоторые клетки непроходимы.
	 * Разрешено ходить только вниз и вправо, какое кол-во способов дойти до правого нижнего угла
	 */
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> dp(n, vector<int>(m));
	vector<vector<bool>> ok(n, vector<bool>(m, true));
//	set<pair<int, int>> bad;
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		ok[x][y] = false;
	}

	for (int j = 0; j < m; ++j) {
		if (!ok[0][j]) break;
		dp[0][j] = 1;
	}

	for (int i = 0; i < n; ++i) {
		if (!ok[i][0]) break;
		dp[i][0] = 1;
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (!ok[i][j]) continue;
//			if (bad.find({i, j}) != bad.end()) continue;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	// O(nm)

//	dp[0][0] = 1;
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < m; ++j) {
//			if (!ok[i][j]) {
//				continue;
//			}
//			if (i) {
//				dp[i][j] += dp[i - 1][j];
//			}
//			if (j) {
//				dp[i][j] += dp[i][j - 1];
//			}
//		}
//	}

	cout << dp[n - 1][m - 1] << endl;
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
