#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
	// d - gcd, a | d and b | d, a > b
	// (a - b) | d?
	// (x * d - y * d) = d * (x - y)

	// (a - b) < a
	// gcd(a - b, b)

	// d, d
	// (d - d) = 0 | d
	if (a == b) return a;

	if (a < b) swap(a, b);
	return gcd(a - b, b);
}

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int lcm(int a, int b) {
	return 1ll * a * (b / gcd(a, b));
}

// lcm(10^18, 10^18)
// 1 1 2 3 5 8 13 21 ~ 2^n => O(log(MAX(a)))

void solve() {
	int a, b;
	cin >> a >> b;
	cout << __gcd(a, b) << endl;
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
