#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	ll n, k, c;
	cin >> n >> k >> c;
	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> d(n);
	function<void(int, int)> go = [&](int cur, int prv) {
		d[cur] = 0;
		for (auto to: g[cur]) {
			if (to == prv) continue;
			go(to, cur);
			d[cur] = max(d[cur], d[to] + 1);
		}
	};
	go(0, -1);

	ll ans = 0;
	function<void(int, int, int, ll)> go2 = [&](int cur, int prv, int upDepth, ll cost) {
		multiset<int> st;
		for (auto to: g[cur]) {
			if (to == prv) continue;
			st.insert(d[to]);
		}
		st.insert(upDepth);

		ans = max(ans, (*prev(st.end()) + 1) * k - cost);

		for (auto to: g[cur]) {
			if (to == prv) continue;
			st.erase(st.find(d[to]));
			int newD = *prev(st.end()) + 1;

			go2(to, cur, newD, cost + c);

			st.insert(d[to]);
		}
	};
	go2(0, -1, -1, 0);
	cout << ans << endl;
	// O(n + m + (n + m)logn)
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
