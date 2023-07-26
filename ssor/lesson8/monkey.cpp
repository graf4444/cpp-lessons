#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

void solve() {
	int k, a, b;
	cin >> k >> a >> b;
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> from(n + 1, vector<int>(k + 1, -1)); // dp[i][j] - откуда я пришел если прошел уже i символов строки и при этом разбил на j кусочков
	from[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int cnt = 0; cnt < k; ++cnt) {
			if (from[i][cnt] == -1) continue;
			for (int add = a; add <= b; ++add) {
				if (i + add > n) break;
				from[i + add][cnt + 1] = i;
			}
		}
	}
	if (from[n][k] == -1) {
		cout << "No solution" << endl;
		return;
	}
	vector<string> ans;
	int cur = n;
	for (int cnt = k; cnt > 0; --cnt) {
		int prv = from[cur][cnt];
		ans.push_back(s.substr(prv, cur - prv));
		cur = prv;
	}
	reverse(ans.begin(),  ans.end());
	for (auto &s: ans) {
		cout << s << endl;
	}
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
