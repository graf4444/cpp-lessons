#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//#define endl '\n'

bool can(int thrs, const vector<int>& ar, int k) {
	for (auto v: ar) {
		if (v >= thrs) k -= v;
		else break;
	}
	return k >= 0;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> ar(n);
	for (auto& v: ar) {
		cin >> v;
	}
	sort(ar.rbegin(),  ar.rend());

	int l = 0;
	int r = 10001;

	while (l < r - 1) {
		int m = (l + r) / 2;
		if (can(m, ar, k)) {
			r = m;
		} else {
			l = m;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (ar[i] >= r) ans++;
	}
	cout << ans << endl;
}
// O(nlogn)

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}