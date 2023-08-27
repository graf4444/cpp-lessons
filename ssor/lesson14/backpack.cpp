#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void selfMax(int& a, int b) {
	a = max(a, b);
}

void solve() {
	int n;
	cin >> n;
	int W;
	cin >> W;
	vector<pair<int, int>> ar(n);
	for (auto& [weight, cost]: ar) {
	    cin >> weight >> cost;
	}
	const int INF = 1e9;
	vector<int> dp(W + 1, -INF);
	vector<vector<int>> from(n + 1, vector<int>(W + 1, -1));
	dp[W] = 0;
	for (int i = 0; i < n; ++i) {
		for (int remain = ar[i].first; remain <= W; ++remain) {
			if (dp[remain] == -INF) continue;
			if (dp[remain] + ar[i].second > dp[remain - ar[i].first]) {
				from[i + 1][remain - ar[i].first] = i;
				dp[remain - ar[i].first] = dp[remain] + ar[i].second;
			}
//			selfMax(dp[remain - ar[i].first], dp[remain] + dp[i].second);
		}
	}
	int remain = max_element(dp.begin(),  dp.end()) - dp.begin();
	cout << "cost = " << dp[remain] << endl;
	vector<int> ans;
	for (int i = n; i >= 0; --i) {
		if (from[i][remain] != -1) {
			int who = from[i][remain];
			remain += ar[who].first;
			ans.push_back(who);
		}
	}
	cout << ans.size() <<  endl;
	for (auto v: ans) {
		cout << v + 1 << " ";
	}
	cout << endl;
	// O(nW)
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
