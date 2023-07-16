#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

void solve() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	// y1 = k * x1 + b
	// y2 = k * x2 + b

	// y1 - y1 = k * (x1 - x2)
	// k = (y1 - y2) / (x1 - x2)

	// перенесем x1 в 0

	// y = K * x + b ~ y = K * x, x = 0 ... (x2 - x1)
	// y = (y1 - y2) / (x1 - x2) * (x2 - x1) = y2 - y1
	// (x2 - x1) = g * X'
	// y = (g * Y') / (g * X') = Y' / X' ~ 1/X'
	// c * (x2 - x1) / g <= (x2 - x1)
	// c = 0..g
	// ans = g + 1

	cout << __gcd(abs(x1 - x2), abs(y1 - y2)) + 1 << endl;
	// 1 1 2 3 5 8 13 21 34 55 89 ~ 2^n
	// O(log(MAX(A)))
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
