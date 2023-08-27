#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> ans;
	ans.push_back(n);
	int d = 1; // 1 | 10 | 100
	while (d < n) {
		if (n & d) {
			n -= d;
			ans.push_back(n);
		}
		d *= 2;
	}
	while (n > 1) {
		n /= 2;
		ans.push_back(n);
	}
	cout << ans.size() << endl;
	for (auto v: ans) {
		cout << v << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
