#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
		cin >> v;
	}
	int ans = 0;

	// O(n^2)
//	for (int i = 0; i < n; ++i) {
//		for (int j = i + 1; j < n; ++j) {
//			if (ar[j] < ar[i]) {
//				ans++;
//				break;
//			}
//		}
//	}

//	(3 9 6 6 4 5)
//	3 (9 6 6 4 5)

	// O(nlogn)
//	multiset<int> st;
//	for (auto v: ar) {
//		st.insert(v);
//	}
//	for (int i = 0; i < n; ++i) {
//		int mn = *st.begin();
//		if (ar[i] > mn) {
//			ans++;
//		}
//		st.erase(st.find(ar[i]));
//	}

	// O(nlogn)
//	map<int, vector<int>> mp;
//	for (int i = n - 1; i >= 0; --i) {
//		mp[ar[i]].push_back(i);
//	}
//	for (int i = 0; i < n; ++i) {
//		auto it = mp.begin();
//		if (ar[i] > it->first) {
//			ans++;
//		}
//		mp[ar[i]].pop_back();
//		if (mp[ar[i]].empty()) mp.erase(ar[i]);
//	}

//	O(nlogn)
//	map<int, int> mp;
//	for (int i = 0; i < n; ++i) {
//		mp[ar[i]]++;
//	}
//	for (int i = 0; i < n; ++i) {
//		auto it = mp.begin();
//		if (ar[i] > it->first) {
//			ans++;
//		}
//		mp[ar[i]]--;
//		if (mp[ar[i]] == 0) mp.erase(ar[i]);
//	}

//	(3 9 6 6 4 5)
//	3 (9 6 6 4 5)
//	3 9 (6 6 4 5)
//	3 9 6 (6 4 5)
//	3 9 6 6 (4 5)
//	3 9 6 6 4 (5)
//	O(n)
//	int mn = ar.back();
//	for (int i = n - 2; i >= 0; --i) {
//		mn = min(mn, ar[i]);
//		if (ar[i] > mn) ans++;
//	}

	reverse(ar.begin(),  ar.end());
	int mn = ar[0];
	for (auto v: ar) {
		mn = min(mn, v);
		if (v > mn) ans++;
	}
	cout << ans << endl;
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
