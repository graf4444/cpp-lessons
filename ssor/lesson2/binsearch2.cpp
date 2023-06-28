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
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}
	sort(ar.begin(), ar.end());
	int cnt = 1;
	int ans = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (ar[i] == ar[i + 1]) {
			cnt++;
		} else {
			ans += cnt;
			int need = ar[i + 1] * cnt;
			if (k < need) {
				break;
			}
			k -= need;
			cnt = 1;
		}
	}
	int need = ar[0] * cnt;
	if (k >= need) {
		ans += cnt;
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
