#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
	map<int, int> mp;
	mp[5] = 3;

	{
		// no element
		auto it = mp.find(4);
	}

	{
		auto it = mp.find(5);
		it->first; // == 5
		it->second = 42;
		(*it).second = 42;
	}

// mp.erase
// mp.find
// mp[5] = 5

	mp.clear();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		mp[a]++;
 	}
	for (auto [k, v]: mp) {
		cout << k << " " << v << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}