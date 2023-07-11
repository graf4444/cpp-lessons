#include <bits/stdc++.h>

using namespace std;

void solve() {
	int l, r;
	cin >> l >> r;
	int ans = -1;
	int who;
	for (int i = l; i <= r; ++i) {
		auto s = to_string(i);
		int mn = *min_element(s.begin(),  s.end());
		int mx = *max_element(s.begin(),  s.end());
		int cur = mx - mn;
		if (cur > ans) {
			ans = cur;
			who = i;
		}
		if (ans == 9) break;
	}
	cout << who << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
