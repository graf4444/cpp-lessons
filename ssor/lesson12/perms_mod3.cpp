#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int MAX_FACT = 10;
vector<int> fact(MAX_FACT);

int calc(int a) {
	map<int, int> mp;
	int len = 0;
	while (a) {
		mp[a % 10]++;
		a /= 10;
		len++;
	}
	int ans = fact[len];
	for (auto [_, v]: mp) {
		ans /= fact[v];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	const int MAX = 1e6 + 2;
	fact[0] = 1;
	for (int i = 1; i < MAX_FACT; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	vector<ll> pref(MAX);
	pref[0] = 0;
	for (int i = 1; i < MAX; ++i) {
		pref[i] = pref[i - 1];
		if (i % 3) continue;
		pref[i] += fact[calc(i)];
	}
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l > r) {
			cout << 0 << endl;
			continue;
		}
		cout << pref[r] - pref[l - 1] << endl;
	}
}
