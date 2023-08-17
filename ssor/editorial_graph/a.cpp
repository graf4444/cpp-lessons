#include <bits/stdc++.h>

using namespace std;

vector<char> letters;
map<int, vector<int>> mp;

// 00000000000000000000
// 26

int go(const vector<vector<int>>& g, int cur, int from) {
	int rs = (1 << (letters[cur] - 'a'));
	for (auto to: g[cur]) {
		if (to == from) continue;
		rs |= go(g, to, cur);
	}
	mp[rs].push_back(cur);
	return rs;
}

vector<int> memo;
void dfs(...) {
	if (memo[cur] != -1) {
		return;
	}
	for (auto to: ar[cur]) {
		dfs(to);
	}
	order.push_back(cur);
	memo[cur] = 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
//	memo.assign(n, -1);
//	int ans = 0;
//	for (int i = 0; i < n; ++i) {
//		dfs(i);
//	}
//	cout << ...



//	const vector<pair<int, int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
//
//	queue<pair<int, int>> q;
//	q.push({x, y});
//
//	while (!q.empty()) {
//		auto [x, y] = q.front();
//		q.pop();
//		for (auto [dx, dy]: moves) {
//			int nx = x + dx;
//			int ny = y + dy;
//			if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == '#') {
//				continue;
//			}
//			if (d[nx][ny] != -1) continue;
//			d[nx][ny] = d[x][y] + 5;
//			q.push({nx, ny});
//		}
//	}

	int n;
	cin >> n;
	letters.resize(n);
	for (auto& c: letters) {
		cin >> c;
	}
	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	go(g, 0, -1);
	for (auto& [k, v]: mp) {
		if (v.size() < 2) continue;
		cout << v[0] + 1 << " " << v[1] + 1 << endl;
		return 0;
	}
	cout << "-1 -1" << endl;
}
