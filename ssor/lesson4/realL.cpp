#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	sort(ar.begin(),  ar.end());
	long long ans = 0;
//	for (int i = 0; i < n; ++i) {
//		auto bound = upper_bound(ar.begin() + i + 1,  ar.end(), m / ar[i]) - ar.begin() - i - 1;
//		ans += bound;
//	}
	int p = n - 1;
	for (int i = 0; i < p; ++i) {
		while (i < p && 1ll * ar[i] * ar[p] > m) p--;
		if (p <= i) break;
		ans += p - i;
	}
	cout << ans << endl;
}

// 3 2 3 2 5
// 2 [2 3 3 5]
//

// m = 1000000
// 10000 10000

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
