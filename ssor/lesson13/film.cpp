#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	// dp[day][seen] = max_score
//	const ll INF = 1e18;
//	vector<ll> dp(n + 1, -INF);
//	auto nxt = dp;
//	dp[0] = 0;
//	ll ans = 0;
//	for (int i = 0; i < n; ++i) {
//		nxt.assign(n, -INF);
//		for (int seen = 0; seen <= min(m, i); ++seen) {
//			if (dp[seen] == -INF) continue;
////			cout << "[" << i << "][" << seen << "] = " << dp[seen] << endl;
//			ans = max(ans, dp[seen]);
//			if (seen < m) {
//				nxt[seen + 1] = max(nxt[seen + 1], dp[seen] + ar[i] - d);
//			}
//			nxt[seen] = max(nxt[seen], dp[seen] - d);
//		}
//		swap(nxt, dp);
//	}
//	for (auto v: dp) {
//		ans = max(ans, v);
//	}
//	cout << ans << endl;

	{
		ll ans = 0;
		ll sum = 0;
		multiset<int> st;
		for (int i = 0; i < n; ++i) {
			if (ar[i] > 0) {
				st.insert(ar[i]);
				sum += ar[i];
			}
			if (st.size() > m) {
				sum -= *st.begin();
				st.erase(st.begin());
			}
			ans = max(ans, sum - 1ll * (i + 1) * d);
		}
		cout << ans << endl;
		// O(nlogm)
	}

//	vector<int> newFence(n);
//	newFence[0] = n;
//	for (int i = 0; i < n; ++i) {
//		newFence[a[i]] -= 1;
//	}
//	for (int i = 0; i < n; ++i) {
//		newFence[i + 1] += newFence[i];
//	}
//	cout << (newFence == ar) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
