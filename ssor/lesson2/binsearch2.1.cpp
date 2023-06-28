#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//#define endl '\n'

int ask(int m) {
	cout << m << endl;
	char res;
	cin >> res;
	if (res == '<') return -1;
	else if (res == '>') return 1;
	return 0;
}

void solve() {
	int n, k;
	cin >> n >> k;
	map<int, int> mp;
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		mp[-v] += v; // O(log(SZ)) <= O(log(n))
	}
	int ans = 0;
	for (auto p: mp) {
		if (k >= p.second) {
			k -= p.second;
			ans += -p.second / p.first;
		} else {
			break;
		}
	}
	cout << ans << endl;
}
// O(nlogn)
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}


// N items
// ci - cost
// K - amount of money
