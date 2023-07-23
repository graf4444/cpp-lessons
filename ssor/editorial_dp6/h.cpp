#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

void solve() {

	vector<vector<vector<int>>> ar(n, m);
	// dp[len][last] - колво сопособов набрать массив длины len если последнее число last
	// dp[1][i] = 1

	// dp[i][j - 1][g] где = 1, ставим dp[i][j][gcd(g, ar[i][j])] = 1
	// dp[i - 1][j][g] где = 1, ставим dp[i][j][gcd(g, ar[i][j])] = 1


	// для g из dp[i][j - 1], кладем gcd(g, ar[i][j]) в dp[i][j]
	// для g из dp[i - 1][j], кладем gcd(g, ar[i][j]) в dp[i][j]

	// dp[n][m][g] -> max(g) где 1

	// n * m * MAXA^(1/3) * log(MAXA^(1/3)) ~ 10^6 * 2 * 3.5 = 7*10^6

	// другой вариант
	// dp[i][j] = 0|1
	// dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) если они делятся на ответ


	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i && ar[i - 1][j] % ans == 0) {
				dp[i][j] = max(...)
			}
			if (j && ar[i][j - 1] % ans == 0) {
				dp[i][j] = max(...)
			}
		}
	}
	dp[n][m] - ?
	// O(MAXA^(1/3) * n * m)
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
