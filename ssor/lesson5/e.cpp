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
	int r = 1e9 + 1000;
	while (l < r - 1) {
		int m = (l + r) / 2;
		if (ask(m, a, b) < n) {
			l = m;
		} else {
			r = m;
		}
	}
	if (ask(l, a, b) >= n) r = l;
	cout << min(a, b) + r << endl;
}
//4 9
//3 18
//2 19
//1 27
//0 29

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
