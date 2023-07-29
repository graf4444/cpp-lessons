#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> ar(n);
	for (auto& [l, r]: ar) {
	    cin >> l >> r;
	}
	// n <= 2e5
	// 0 < l < r <= 1e5
	sort(ar.begin(),  ar.end(), cmp);
//	const int MAX = 1e5;
//	vector<int> dp(MAX + 1);
//	dp[0] = 0;
//	int j = 0;
//	for (int curTime = 0; curTime < MAX; ++curTime) {
//		while (j < n && ar[j].first == curTime) {
//			dp[ar[j].second] = max(dp[ar[j].second], dp[curTime] + 1);
//			j++;
//		}
//		dp[curTime + 1] = max(dp[curTime + 1], dp[curTime]);
//	}
//
//	for (int curTime = 1; curTime <= MAX; ++curTime) {
//		while (j < n && ar[j].second == curTime) {
//			dp[ar[j].second] = max(dp[ar[j].second], dp[ar[j].first] + 1);
//			j++;
//		}
//		dp[curTime] = max(dp[curTime], dp[curTime - 1]);
//	}
//	int ans = dp[MAX];
	// O(nlogn + MAX + n)
	// O(n) - mem

	int ans = 0;
	int curTime = 0;
	for (int i = 0; i < n; ++i) {
		if (ar[i].first >= curTime) {
			ans++;
			curTime = ar[i].second;
		}
	}
	// O(nlogn + n)
	// O(1) - mem

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
