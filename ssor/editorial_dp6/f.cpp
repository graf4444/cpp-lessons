#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

void solve(const vector<vector<int>>& dp) {
	int n, s;
	cin >> n >> s;
	cout << dp[n][s] << endl;

//	vector<int> dp(s + 1, 0);
//
//	for (int i = 0; i < 10; ++i) {
//		dp[i] = 1;
//	}
//	for (int len = 2; len <= n; ++len) {
//		for (int sum = min(s, len * 9); sum >= 0; --sum) {
//			dp[sum] = 0;
//			for (int firstDigit = 0; firstDigit <= min(9, sum); ++firstDigit) {
//				dp[sum] += dp[sum - firstDigit];
//				dp[sum] %= MOD;
//			}
//		}
//	}
//	cout << dp[s] << endl;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	// dp[i][j] - i цифр, осталось набрать j

	const int MAXN = 100;
	const int MAXS = 1000;
	vector<vector<int>> dp(MAXN + 1, vector<int>(MAXS + 1, 0));

	for (int i = 0; i < 10; ++i) {
		dp[1][i] = 1;
	}
	for (int len = 2; len <= MAXN; ++len) {
		for (int sum = 0; sum <= min(MAXS, len * 9); ++sum) {
			for (int firstDigit = 0; firstDigit <= min(9, sum); ++firstDigit) {
				dp[len][sum] += dp[len - 1][sum - firstDigit];
				dp[len][sum] %= MOD;
			}
		}
	}
	int t = 1;
//	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve(dp);
	}
}
