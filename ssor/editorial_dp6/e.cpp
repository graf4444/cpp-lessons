#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	// n
	// n - 1
	// n / 2
	// n / 3
	vector<int> dp(n + 1, 1e9); // dp[i] - за сколько минимально я дошел от n до числа i
	dp[n] = 0;
	for (int i = n; i > 1; --i) {
		dp[i - 1] = min(dp[i - 1], dp[i] + i);
		if (i % 2 == 0) {
			dp[i / 2] = min(dp[i / 2], dp[i] + i);
		}
		if (i % 3 == 0) {
			dp[i / 3] = min(dp[i / 3], dp[i] + i);
		}
	}
	cout << dp[1] << endl;

//	dp[1] = 0;
//	for (int i = 1; i < n; ++i) {
//		dp[i + 1] = min(dp[i + 1], dp[i] + (i + 1));
//		if (i * 2 <= n) {
//			dp[i * 2] = min(dp[i * 2], dp[i] + (i * 2));
//		}
//		if (i * 3 <= n) {
//			dp[i * 3] = min(dp[i * 3], dp[i] + (i * 3));
//		}
//	}
//	cout << dp[n] << endl;
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
