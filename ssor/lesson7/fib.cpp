#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int fib(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}

void solve() {
	// dp
	int n;
	cin >> n;
	// O(2^n)
	cout << fib(n) << endl;
	vector<int> fibAr(n + 1);
	fibAr[0] = 0;
	fibAr[1] = 1;
	// O(n)
	for (int i = 2; i <= n; ++i) {
		fibAr[i] = fibAr[i - 1] + fibAr[i - 2];
	}
	cout << fibAr[n] << endl;
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
