#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	deque<int> d;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		d.push_back(v);
	}
	sort(d.begin(),  d.end());
	int ans = 0;

	for (;;) {
		while (!d.empty() && 1ll * d.front() * d.back() > m) {
			d.pop_back();
		}
		if (d.size() > 1) {
			d.pop_front();
			d.pop_back();
			ans++;
		} else {
			break;
		}
	}

	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}

// m = 100
// 1 10 10 99 100 1000
//