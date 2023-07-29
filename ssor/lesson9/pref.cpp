#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}

	vector<int> pref(n + 1);
	pref[0] = 0;
	for (int i = 0; i < n; ++i) {
		pref[i + 1] = ar[i] ^ pref[i];
	}

	// a ^ a = 0
	// a ^ b = b ^ a
	// a ^ b ^ a = (a ^ a) ^ b = 0 ^ b = b

	// (a ^ b ^ c ^ d) ^ (a) = b ^ c ^ d
	// (a ^ b ^ c ^ d) ^ (a ^ b) = c ^ d

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << pref[r + 1] ^ pref[l] << endl;
//		int ans = 0;
//		for (int i = l; i <= r; ++i) {
//			ans ^= ar[i];
//		}
//
//		for (int i = 0; i <= r; ++i) {
//			ans ^= ar[i];
//		}
//		for (int i = 0; i < l; ++i) {
//			ans ^= ar[i];
//		}
	}
	// O(n + q)
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
