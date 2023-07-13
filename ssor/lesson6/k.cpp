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
	multiset<int> l, r;
	for (int i = 0; i < n; ++i) {
		l.insert(ar[i]);
		if (l.size() - 1 > r.size()) {
			auto it = prev(l.end());
			r.insert(*it);
			l.erase(it);
		}
		if (r.size() && (*prev(l.end())) > (*r.begin())) {
			auto it = prev(l.end());
			r.insert(*it);
			l.erase(it);

			it = r.begin();
			l.insert(*it);
			r.erase(it);
		}
		cout << (*prev(l.end())) << endl;
	}
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
