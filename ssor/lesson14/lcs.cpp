#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void selfMax(int& a, int b) {
	a = max(a, b);
}

void solve() {
	// longest common subsequence
	// НОП

	// 1 8 3 89 4 0
	// 2 89 1 3 9 0 97 3
	// res: 1 3 0
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& v: a) {
	    cin >> v;
	}
	vector<int> b(m);
	for (auto& v: b) {
	    cin >> v;
	}
	// dp[i][j] посмотрел i элементов в первом и j во втором = макс кол-во совпавших
	// if a[i] == b[j] dp[i + 1][j + 1] = max(..., dp[i][j] + 1)
	// dp[i + 1][j] = max(..., dp[i][j])
	// dp[i][j + 1] = max(..., dp[i][j])
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 0; i <= m; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (i < n && j < m && a[i] == b[j]) {
				selfMax(dp[i + 1][j + 1], dp[i][j] + 1);
			}
			if (i < n) {
				selfMax(dp[i + 1][j], dp[i][j]);
			}
			if (j < m) {
				selfMax(dp[i][j + 1], dp[i][j]);
			}
		}
	}
	cout << dp[n][m] << endl;
	// O(nm)
	vector<int> ans;
	int x = n;
	int y = m;
	while (x && y) {
		if (dp[x][y] == dp[x - 1][y - 1] + 1) {
			ans.push_back(a[x - 1]);
			x--;
			y--;
		} else if (dp[x][y] == dp[x - 1][y]) {
			x--;
		} else {
			y--;
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto v: ans) {
		cout << v << " ";
	}
	cout << endl;
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
