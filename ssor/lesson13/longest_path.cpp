#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
	}
	vector<int> ans(n, -1);
	vector<int> nxt(n, -1);
	function<int(int)> go = [&](int cur) {
		if (ans[cur] != -1) {
			return ans[cur];
		}
		int mx = 0;
		for (auto to: g[cur]) {
			int len = go(to) + 1;
			if (len > mx) {
				mx = len;
				nxt[cur] = to;
			}
		}
		return ans[cur] = mx;
	};
	int mx = 0;
	int from;
	for (int i = 0; i < n; ++i) {
		int len = go(i);
		if (len > mx) {
			mx = len;
			from = i;
		}
	}
	vector<int> path;
	while (nxt[from] != -1) {
		path.push_back(from);
		from = nxt[from];
	}
	path.push_back(from);
	cout << path.size() << endl;
	for (auto v: path) {
		cout << v + 1 << " ";
	}
	cout << endl;
	// O(n + m)
}
