#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
		cin >> v;
	}
	const int INF = 1e9;
	vector<int> d(n + 1, INF);
	d[0] = -INF;
	vector<int> pos(n + 1);
	vector<int> prv(n);
	for (int i = 0; i < n; ++i) {
		int idx = upper_bound(d.begin(),  d.end(), ar[i]) - d.begin();
		// для строго возрастания проверяем предыдущий, если нестрогое то не проверяем))
		if (d[idx - 1] == ar[i]) continue;
		d[idx] = ar[i];
		pos[idx] = i;
		prv[i] = pos[idx - 1];
		for (auto v: d) {
			if (v < INF) {
				cout << v << " ";
			}
		}
		cout << endl;
	}
	int ans;
	for (int i = 0; i <= n; ++i) {
		if (d[i] < INF) {
			ans = i;
		} else {
			break;
		}
	}
	cout << ans << endl;
	vector<int> seq;
	int last = pos[ans];
	while (ans--) {
		seq.push_back(ar[last]);
		last = prv[last];
	}
	reverse(seq.begin(),  seq.end());
	for (auto v: seq) {
		cout << v << " ";
	}
	cout << endl;
}
