#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//#define endl '\n'

void solve() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	ll val = 0;
	for (auto c: s) {
		val *= a;
		if ('0' <= c && c <= '9') {
			val += c - '0';
		} else {
			val += c - 'a' + 10;
		}
	}

	string res;
	while (val) {
		char c = val % b;
		if (c < 10) c += '0';
		else c += 'a' - 10;
		res += c;
		val /= b;
	}
	reverse(res.begin(),  res.end());
	if (res.empty()) res = "0";
	cout << res << endl;
}

/*
 *
 * f(x) = dx^3 + ax^2 + bx + c
 * f(10) = (dx^2 + ax + b)x + c = ((dx + a)x + b)x + c
 *
 */

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}