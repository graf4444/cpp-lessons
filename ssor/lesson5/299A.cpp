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
	int mn = *min_element(ar.begin(),  ar.end());
	for (auto v: ar) {
		if (v % mn) {
			cout << -1 << endl;
			return;
		}
	}
	cout << mn << endl;
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
