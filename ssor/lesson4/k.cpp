#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	sort(ar.begin(),  ar.end());
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l > r) swap(l, r);
		auto it1 = upper_bound(ar.begin(),  ar.end(), l);
		auto it2 = upper_bound(ar.begin(),  ar.end(), r);
		cout << it2 - it1 << endl;
	}
}

// -1 2 5
// [0, 3]

//