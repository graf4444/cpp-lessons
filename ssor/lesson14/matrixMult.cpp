#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void selfMax(int& a, int b) {
	a = max(a, b);
}

void solve() {
	// sizes: [a, b] [b, c] = [a, c]
	// abc
	//	for (int i = 0; i < a; ++i) {
	//		for (int j = 0; j < c; ++j) {
	//			for (int k = 0; k < b; ++k) {
	//				res[i][j] += A[i][k] * B[k][j];
	//			}
	//		}
	//	}

	// A1 * A2 * ... * An

	// [2 10] [10 5] [5 1000]
	// 10 * 5 * 1000 + 2 * 10 * 1000

	// 2 * 10 * 5 + 2 * 5 * 1000

	// dp[l][r] - min кол-во операций для перемножения матриц с l по r включительно
	// dp[i][j] = min(dp[i][k] + dp[k + 1][j] + sz[i][0] * sz[k][1] * sz[j][1]) k = i...j

	// [1 2 3 4 5 6] * [7 8 9]
	int n;
	cin >> n;
	vector<pair<int, int>> sz(n);
	for (auto& [n, m]: sz) {
		cin >> n >> m;
	}
	const int INF = 1e9;

	vector<vector<int>> dp(n, vector<int>(n));
	vector<vector<int>> where(n, vector<int>(n));
//	for (int i = 0; i < n; ++i) {
//		dp[i][i] = 0;
//	}
//	for (int len = 2; len <= n; ++len) {
//		for (int beg = 0; beg + len <= n; ++beg) {
//			int end = beg + len - 1;
//			int mn = INF;
//			int bst;
//			for (int k = beg; k < end; ++k) {
//				// [beg k] [k + 1, end]
//				int cur = dp[beg][k] + dp[k + 1][end] + sz[beg].first * sz[k].second * sz[end].second;
//				if (cur < mn) {
//					mn = cur;
//					bst = k;
//				}
//			}
//			dp[beg][end] = mn;
//			where[beg][end] = bst;
//		}
//	}
// 1 - 1
// 2 - 1
// 3 (1 2) (2 1) = 1 + 1 + 1 + 1 = 4
// 4 (1 3) (2 2) (3 1) = (1 + 4) + (1 + 1) + (4 + 1) = 12
// 5 (1 4) (2 3) (3 2) (4 1) = (1 + 12) + (1 + 4) + (4 + 1) + (12 + 1) = 36
// 6 (1 5) (2 4) (3 3) (4 2) (5 1) = (1 + 36) * 2 + (1 + 12) * 2 + 4*2 = 108
	function<int(int, int)> calc = [&](int l, int r) {
		if (l == r) {
			return 0;
		}
		if (dp[l][r] > 0) {
			return dp[l][r];
		}
		int mn = INF;
		for (int i = l; i < r; ++i) {
			int left = calc(l, i);
			int right = calc(i + 1, r);
			int cur = left + right + sz[beg].first * sz[k].second * sz[end].second;
			mn = min(mn, cur);
		}
		return dp[l][r] = mn;
	};
	calc(0, n - 1);
	cout << dp[0][n - 1] << endl;
	function<void(int, int)> go = [&](int l, int r) {
		if (l == r) {
			cout << l + 1;
			return;
		}
		int pos = where[l][r];
		cout << "(";
		go(l, pos);
		cout << ") * (";
		go(pos + 1, r);
		cout << ")";
	};
	go(0, n - 1);
	cout << endl;
	// O(n^3)
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}
