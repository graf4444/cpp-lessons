#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
using ll = long long;

int main() {
	int n;
	cin >> n;
	ll a, m, k, mod;
	cin >> a >> m >> k >> mod;
	vector<int> cnt(mod);
	for (int i = 0; i < n; ++i){
		cnt[a]++;
		a = (a * m + k) % mod;
	}

	int idx = 0;
	ll ans = 0;
	for (int i = 0; i < mod; ++i) {
		while (cnt[i]) {
			cnt[i]--;
			ans += 1ll*(idx + 1) * i;
			ans %= MOD;
			idx++;
		}
	}
	cout << ans << endl;
}

// 3 1 3
// 0 1 0 2 0 ...

// 1

// 1 3 3