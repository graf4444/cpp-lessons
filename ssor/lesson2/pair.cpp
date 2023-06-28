#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//#define endl '\n'

void solve() {
	pair<int, string> p;
	p.first = 4;
	p.second = "143223523";
	map<pair<int, int>, string> mp;
	mp[make_pair(2, 5)] = "abc";
	mp[pair<int, int>{3, 6}] = "def";
	// C++17
	mp[pair{3, 7}] = "ghi";
	for (auto p: mp) {
		cout << p.first.first << " " << p.first.second << " = " << p.second << endl;
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