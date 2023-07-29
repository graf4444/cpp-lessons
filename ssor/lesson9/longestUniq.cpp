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
	int ans = 0;

	// [1 2 3 5 16 2 3 16
	// ans = 5

//	for (int i = 0; i < n; ++i) {
//		for (int j = i; j < n; ++j) {
//			set<int> st;
//			for (int k = i; k <= j; ++k) {
//				st.insert(ar[k]);
//			}
//			int len = (j - i + 1);
//			if (st.size() == len) {
//				ans = max(ans, len);
//			}
//		}
//	}
// O(n^3logn)

	set<int> st;
	int beg = 0;
	for (int i = 0; i < n; ++i) {
		st.insert(ar[i]);
		int len = i - beg + 1;
		if (st.size() == len) {
			ans = max(ans, len);
			// ans += len
			continue;
		}
		while (ar[beg] != ar[i]) {
			st.erase(ar[beg]);
			beg++;
		}
		beg++;
		// ans += i - beg + 1
	}
	// O(nlogn)

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