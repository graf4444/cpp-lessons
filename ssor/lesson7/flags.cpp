#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
/*
 * Флаг из n частей, каждая часть может быть одного из трех цветов(белый, синий, красный), но запрещено иметь два синих подряд.
 * Сколько различных флагов можно сшить?
 */

	int n;
	cin >> n;
	if (n == 1) {
		cout << 3 << endl;
		return;
	}
//	[n - 1] * 3 - конец не синий
//	[n - 2] * 2
//	+

	// dp[i] - ? сколько флагов можно сделать чтобы последний был не синий
	vector<int> dp(n);
	dp[0] = 1;
	dp[1] = 2;

	for (int i = 2; i < n; ++i) {
		dp[i] = dp[i - 1] * 2 + dp[i - 2] * 2;
	}

	cout << dp[n - 1] * 3 + dp[n - 2] * 2 << endl;
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
