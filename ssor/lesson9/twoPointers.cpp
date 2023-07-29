#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	// |ai - aj| <= K
	long long ans = 0;
//	for (int i = 0; i < n; ++i) {
//		for (int j = i + 1; j < n; ++j) {
//			if (abs(ar[i] - ar[j]) <= k) ans++;
//		}
//	}
//	// O(n^2)
//	cout << ans << endl;
	sort(ar.begin(),  ar.end());
	int r = 0;
	for (int j = 0; j < n; ++j) {
		while (r < n && ar[r] - ar[j] <= k) {
			r++;
		}
		ans += r - (j + 1);
	}
	// O(nlogn + n)
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



// 2 5 3 1 4
// 2 7 10 11 15
// 10