#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
	int n;
	cin >> n;
	set<ll> st;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		// O(log(n))
		st.insert(v);
	}
	for (auto v: st) {
		cout << v << " ";
	}
	cout << endl;
	cout <<	st.count(5) << endl;
	// O(log(n))
	auto it = st.find(5);
	*it;
	it++;
	it--;
	st.erase(it);
	for (set<int>::iterator it = st.begin(); it != st.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	if (st.find(5) == st.end()) {
		cout << "Not found" << endl;
	} else {
		cout << "OK" << endl;
	}

	// O(log(n))
	st.erase(5);
	for (auto v: st) {
		cout << v << " ";
	}
	cout << endl;

	multiset<int> mst;

	auto it = mst.find(5);
	if (it == mst.end()) {
		// ARRRGH
	} else {
		mst.erase(it);
	}
}

{1, 3, 5} + 3 = {1, 3, 3, 5};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}