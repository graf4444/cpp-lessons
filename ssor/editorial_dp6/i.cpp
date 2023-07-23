#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

void solve() {
	// dp[i][2] - мин расстояние чтобы дойти от смаого начала пути до одного из концов отрезка i

	// dp[i + 1][0] = min(dp[i][0] + dist from i(0) to i+1(1), dp[i][1] + dist from i(1) to i+1(1)) + len(i+1)

	// dp[i + 1][1] = min(dp[i][0] + dist from i(0) to i+1(0), dp[i][1] + dist from i(1) to i+1(0)) + len(i+1)

	// задача о двух конвейерах

	// ans = min(dp[n][0], dp[n][1])
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
