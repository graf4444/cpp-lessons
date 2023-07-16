#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 10 << endl;
		return;
	}
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	vector<int> ar;
	for (int i = 9; i > 1; --i) {
		while (n % i == 0) {
			ar.push_back(i);
			n /= i;
		}
	}
	if (n > 1) {
		cout << -1 << endl;
		return;
	}
	reverse(ar.begin(),  ar.end());
	for (int v: ar) {
		cout << v;
	}
	cout << endl;
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
