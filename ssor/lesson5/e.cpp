#include <bits/stdc++.h>

using namespace std;

int ask(int m, int a, int b) {
	return m / a + m / b;
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	n--;
	int l = 0;
	int r = 1e9 + 100;
	while (l < r) {
		int m = (l + r) / 2;
		if (ask(m, a, b) < n) {
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << min(a, b) + l << endl;


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
