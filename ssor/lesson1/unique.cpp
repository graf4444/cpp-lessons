#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'

void solve() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
// 1 1 2 3 5 5 5 7
// 1 2 3 5 7
// 1 2 3 4 1 2 3 4

	sort(ar.begin(),  ar.end());
	ar.erase(unique(ar.begin(),  ar.end()), ar.end());
	cout << ar.size() << endl;
	for (auto v: ar) {
		cout << v << " ";
	}
	cout << endl;
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