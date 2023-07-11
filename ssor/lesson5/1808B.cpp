#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ar(m, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> ar[j][i];
		}
	}
	for (int i = 0; i < m; ++i) {
		sort(ar[i].begin(),  ar[i].end());
	}
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		ll sum = 0;
		for (int j = 0; j < n; ++j) {
			ans += 1ll * j * ar[i][j] - sum;
			sum += ar[i][j];
		}
	}
	cout << ans << endl;
}

// O(nm + nmlogn + nm) ~ O(nmlogn)

// j = 1, k = 0
// j = 2, k = 0, 1
// j = 3, k = 0, 1, 2

//aj - a0 + aj - a1 + aj - a2 + ...
//j * aj - sum(ai)[i=0..j-1]
//(j + 1) * a[j+1] - sum(ai)[i=0..j]

// 1 65 32 2 0
// 0 1 2 32 65


// a b c
// (a1 - b1) + (a2 - b2) + ... + (am - bm)
// (a1 - c1) + (a2 - c2) + ... + (am - cm)
// (b1 - c1) + (b2 - c2) + ... + (bm - cm)


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
