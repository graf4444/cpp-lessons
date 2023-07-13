#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// ax + by = g
? (a, b)
//
+ (a%b, b)
...
+ (g, 0)
// 1 * g + 0 * 0 = g

// (b%a)x1 + ay1 = g
// ax + by = g

//b%a = b - [b/a] * a
// (b - [b/a] * a)x1 + ay1 = g
// bx1 + a(y1 - [b/a]x1) = g

// 512351534
// a b



int gcd(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0;
		y = 1;
		return b;
	}
	int x1, y1;
	int g = gcd(b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return g;
}

void solve() {

	// x * a + y * b = g

	int a, b;
	cin >> a >> b;
	int x, y;
	int g = gcd(a, b, x, y);
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


// ax + by = c

// ax + by = g | * c/g