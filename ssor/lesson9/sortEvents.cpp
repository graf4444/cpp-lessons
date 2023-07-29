#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> ar(n);
	for (auto& [l, r]: ar) {
		cin >> l >> r;
	}

	int q;
	cin >> q;
	vector<int> x(q);
	for (auto& v: x) {
	    cin >> v;
	}
	vector<int> ans(q);

	vector<pair<int, int>> events;
	for (int i = 0; i < n; ++i) {
		events.push_back({ar[i].first, 1});
		events.push_back({ar[i].second + 1, -1});
	}
//	vector<int> sortedX = x;
//	sort(sortedX.begin(),  sortedX.end());
//	int p = 0;
	for (int i = 0; i < q; ++i) {
		events.push_back({x[i], i + 2});
	}

	sort(events.begin(),  events.end());
	int cur = 0;
	for (auto [_, v]: events) {
		if (v == -1) {
			cur--;
		} else if (v == 1) {
			cur++;
		} else {
			v -= 2;
			ans[v] = cur;
		}
	}

	for (auto v: ans) {
		cout << v << " ";
	}
	cout << endl;
	// O((n + q)log(n + q) + n + q)

//	while (q--) {
//		int x;
//		cin >> x;
//		int ans = 0;
//		for (auto [l, r]: ar) {
//			if (l <= x && x <= r) {
//				ans++;
//			}
//		}
//		cout << ans << endl;
//	}
// O(nq)
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