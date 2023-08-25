#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<string> ar(2);
	for (auto& s: ar) {
		cin >> s;
		s = "1" + s;
	}
	int x = 0;
	int y = 0;
	while (x <= n) {
		if (ar[y][x] < '3') {
			x++;
		} else {
			if (ar[y ^ 1][x] < '3') {
				cout << "NO" << endl;
				return;
			}
			x++;
			y ^= 1;
		}
	}
	if (y == 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	{
		vector<vector<int>> dp(2, vector<int>(n + 1, 0));
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < 2; ++j) {
				if (!dp[i][j]) continue;
				if (ar[j][i] < '3') {
					dp[j][i + 1] = 1;
				} else {
					if (ar[j ^ 1][i] >= '3') {
						ar[j ^ 1][i + 1] = 1;
					}
				}
			}
		}
		if (dp[1][n]) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
