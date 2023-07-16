#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	ll ans = 0;
	// O(n^2)
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < i; ++j) {
//			ans += abs(ar[j] - ar[i]);
//		}
//	}
	sort(ar.begin(),  ar.end());
//	for (int i = 0; i < n; ++i) {
//		for (int j = 0; j < i; ++j) {
//			ans += ar[i] - ar[j];
//		}
//	}

	ll sum = 0;

	for (int i = 0; i < n; ++i) {
		ans += 1ll * i * ar[i] - sum;
		sum += ar[i];
	}
	cout << ans << endl;
	// O(nlogn)
}

// 0:
// 1: 0
// 2: 0 1
// 3: 0 1 2

// ans += sum(ar[i] - ar[j]), j = 0 .. i-1
// ans += i * ar[i] - sum(ar[j]), j = 0 .. i-1

// ans += (i + 1) * ar[i + 1] - sum(ar[j]), j = 0 .. i

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
