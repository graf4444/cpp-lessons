#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	const int MAXN = 1e7 + 100;
	vector<bool> prime(MAXN, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= MAXN; ++i) {
		if (!prime[i]) continue;

		for (int j = i; i * j < MAXN; ++j) {
			prime[j * i] = 0;
		}
	}
	// O(nlog(log(n)))

	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		int n;
		cin >> n;
		cout << prime[n] << endl;
	}


	vector<int> cnt(MAXN);
	for (int i = 1; i < MAXN; ++i) {
		for (int j = 1; i * j < MAXN; ++j) {
			cnt[i * j]++;
		}
	}

	vector<int> prime2(MAXN, 0);
	prime2[0] = prime2[1] = 1;
	for (int i = 2; i * i <= MAXN; ++i) {
		if (prime2[i]) continue;

		for (int j = i; i * j < MAXN; ++j) {
			prime2[j * i] = i;
		}
	}
	for (int i = 0; i < MAXN; ++i) {
		if (prime2[i] == 0) prime2[i] = i;
	}


	int n;
	cin >> n;
	int ans = 1;
	while (n > 1) {
		int cnt = 0;
		int k = prime2[n];
		while (n % k == 0) {
			cnt++;
			n /= k;
		}
		ans *= (cnt + 1);
		// (p1, cnt1),(p2, cnt2), (p3, cnt3)...
	}
	// ans ~ O(N^(1/3))


	// 100 = 2^2 * 5^2 (4)
	// 2^0 | 2^1 | 2^2
	// 5^0 | 5^1 | 5^2
	//
	// C(#, 1)
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
