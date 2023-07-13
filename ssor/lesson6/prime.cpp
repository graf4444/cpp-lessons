#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isPrime(int n) {
	if (n < 2) return false;

	for (int i = 2; i * i <= n; ++i) {
		if (n % i) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	// n = 25
	// sqrt(25) = 4.999999999999999999999999999999999999999999999999999

	vector<int> d;
	for (int i = 1; i * i <= n; ++i) {
		if (n % i) continue;
		d.push_back(i);
		if (i * i != n) {
			d.push_back(n / i);
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		cout << isPrime(n) << endl;
	}
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
