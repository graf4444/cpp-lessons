#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
	string s;
	cin >> s;
	int n = s.size();

	vector<vector<int>> dp(n + 1, vector<int>(2, 1e9)); // dp[i][j] i - номер текущей позиции, j - какой сейчас регистр
	// 0 - a, 1 - A

	// AAAAAAAAAAAAaaaaaaaaaaaaaaaaaaa
	// 1111111111110000000000000000000
	dp[0][0] = 0;
	dp[0][1] = 0;

	for (int i = 1; i <= n; ++i) {
		if (s[i - 1] >= 'a' && s[i - 1] <= 'z') {
			dp[i][1] = dp[i - 1][1] + 1;
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]);
		} else {
			dp[i][1] = dp[i - 1][1];
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]) + 1;
		}
	}
	cout << min(dp[n][0], dp[n][1]) << endl;
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