#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	/*
	 * Кузнечик стоит на числовой прямой в точке 0 и может прыгать только направо максимум на k клеток.
	 * В каждой клетке записано число сколько денег получает кузнечик, но это колво может быть и отрицательным.
	 * Какое максимальное кол-во монет получит кузнечик если выберет оптимальный путь до n?
	 */
	int n, k;
	cin >> n >> k;
	vector<int> ar(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> ar[i];
	}
	const int INF = 1e9;
	vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i) {
		// i - k, i - k + 1, ..., i - 1
		for (int j = max(0, i - k); j < i; ++j) {
			dp[i] = max(dp[i], dp[j] + ar[i]);
			// dp[1] = max(dp[0], dp[0] + ar[1])
			// dp[1] = max(-INF, 0 - 10) = -10
		}
	}
	// O(nk)

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < min(i + k, n); ++j) {
			dp[j] = max(dp[j], dp[i] + ar[j]);
		}
	}

	cout << dp[n] << endl;
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
