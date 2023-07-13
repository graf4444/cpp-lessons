#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll get(ll t, const vector<int>& ar) {
	multiset<ll> st;
	// (t_new, t_work)
	// (t_new + t_work, t_work)
	st.insert(0);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int start = *st.begin();
		st.erase(st.begin());
		ans += (t - start) / ar[i];
	}
	return ans;
}

void solve() {
	ll n, k;
	cin >> n >> k;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	sort(ar.begin(),  ar.end());
	//binsearch

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
