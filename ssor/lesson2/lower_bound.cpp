#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//#define endl '\n'

void solve() {
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
		cin >> v;
	}
	sort(ar.begin(),  ar.end());

	int k;
	cin >> k;
	// O(n)
	{
		auto it = find(ar.begin(), ar.end(), k);
		if (it == ar.end()) {
			cout << "Not found" << endl;
		} else {
			cout << (it - ar.begin()) << endl;
		}
	}
	cout << "lower_bound" << endl;
	//O(logn)
	{
		auto it = lower_bound(ar.begin(), ar.end(), k);
		cout << "found " << *it << endl;
		if (it == ar.end()) {
			cout << "Not found" << endl;
		} else {
			cout << (it - ar.begin()) << endl;
		}
	}

	cout << "upper_bound" << endl;
	//O(logn)
	{
		auto it = upper_bound(ar.begin(), ar.end(), k);
		cout << "found " << *it << endl;
		if (it == ar.end()) {
			cout << "Not found" << endl;
		} else {
			cout << (it - ar.begin()) << endl;
		}
	}

	cout << "binsearch" << endl;
	//O(logn)
	{
		bool res = binary_search(ar.begin(), ar.end(), k);
		if (!res) {
			cout << "Not found" << endl;
		} else {
			cout << "found!))" << endl;
		}
	}

	map<int, int> mp;
	mp.lower_bound(k);
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