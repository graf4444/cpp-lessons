#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<string>> g(n);
	vector<string> names(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> names[i] >> k;
		for (int j = 0; j < k; ++j) {
			string name;
			cin >> name;
			g[i].push_back(name);
		}
	}
	map<string, int> mp;
	for (int i = 0; i < n; ++i) {
		mp[names[i]] = i;
	}
	vector<vector<int>> gg(n);
	for (int i = 0; i < n; ++i) {
		for (auto& s: g[i]) {
			gg[i].push_back(mp[s]);
		}
	}
	vector<bool> used(n);
	vector<int> order;
	function<void(int)> dfs = [&](int cur) {
		if (used[cur]) {
			return;
		}
		used[cur] = true;
		for (auto to: gg[cur]) {
			dfs(to);
		}
		order.push_back(cur);
	};
	string target;
	cin >> target;
	dfs(mp[target]);
//	for (int i = 0; i < n; ++i) {
//		dfs(i);
//	}
	for (auto id: order) {
		cout << names[id] << " ";
	}
	cout << endl;
	// O(nlogn + n + sum(k))
}
