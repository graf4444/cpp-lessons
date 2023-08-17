#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
#define endl '\n'

std::mt19937 rnd(time(nullptr));
int genRand(int a, int b) {
	// a <= b !
	return rnd() % (b - a + 1) + a;
}

void solve() {
	int n;
	cin >> n;
	vector<int> ar(n);
	map<int, vector<int>> mp;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i];
		mp[ar[i]].push_back(i);
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		const int len = r - l + 1;
		const int MAGIC_NUMBER = 20;
		int ans = -1;
		int mx = 0;
		set<int> used;
		for (int i = 0; i < min(MAGIC_NUMBER, len); ++i) {
			int idx;
			do {
				idx = genRand(l, r);
			} while (used.count(idx));
			used.insert(idx);
			int cnt = upper_bound(mp[ar[idx]].begin(),  mp[ar[idx]].end(), r) - lower_bound(mp[ar[idx]].begin(),  mp[ar[idx]].end(), l);
			if (3 * cnt >= 2 * len && cnt > mx) {
				mx = cnt;
				ans = ar[idx];
			}
		}
		cout << ans << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//    cin >> t;
	while (t--) {
		solve();
	}
}

//(1 2 3 1 1 1 2 2)(2 2 2 2 5 6 1 2 2)
//c1 k1
//c2 k2
//
//cand = 1
//cnt = 2

// [l, r]
// 1/3^k
