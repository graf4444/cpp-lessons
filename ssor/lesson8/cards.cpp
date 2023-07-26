#include <bits/stdc++.h>

#define endl '\n'

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

vector<vector<vector<int>>> dp(201, vector<vector<int>>(201, vector<int>(201, -1)));

void go(int i, int j, int k) {
//	cout << i << " " << j << " " << k << endl;
	if (dp[i][j][k] != -1) {
		return;
	}
	dp[i][j][k] = 1;
	if (i + j + k == 1) {
		return;
	}
	if (i && j) {
		go(i - 1, j - 1, k + 1);
	}
	if (i && k) {
		go(i - 1, j + 1, k - 1);
	}
	if (k && j) {
		go(i + 1, j - 1, k - 1);
	}
	if (i > 1) {
		go(i - 1, j, k);
	}
	if (j > 1) {
		go(i, j - 1, k);
	}
	if (k > 1) {
		go(i, j, k - 1);
	}
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> cnt(3);
	for (auto c: s) {
		if (c == 'R') cnt[0]++;
		if (c == 'B') cnt[1]++;
		if (c == 'G') cnt[2]++;
	}
	dp[n][cnt[1]][cnt[2]] = 1;
	for (int total = n; total >= 1; --total) {
		for (int i = n; i >= 0; --i) {
			for (int j = n; j >= 0; --j) {
				int k = total - i - j;
				if (k < 0 || dp[total][i][j] != 1) continue;
				if (i && j) {
					dp[total - 1][i - 1][j - 1] = 1;
				}
				if (i && k) {
					dp[total - 1][i - 1][j + 1] = 1;
				}
				if (k && j) {
					dp[total - 1][i + 1][j - 1] = 1;
				}
				if (i > 1) {
					dp[total - 1][i - 1][j] = 1;
				}
				if (j > 1) {
					dp[total - 1][i][j - 1] = 1;
				}
				if (k > 1) {
					dp[total - 1][i][j] = 1;
				}
			}
		}
	}
	string ans;
//	go(cnt[1], cnt[2], cnt[0]);
//	if (dp[1][0][0] == 1) ans += 'B';
//	if (dp[0][1][0] == 1) ans += 'G';
//	if (dp[0][0][1] == 1) ans += 'R';
	if (dp[1][1][0] == 1) ans += 'B';
	if (dp[1][0][1] == 1) ans += 'G';
	if (dp[1][0][0] == 1) ans += 'R';
	cout << ans << endl;
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
