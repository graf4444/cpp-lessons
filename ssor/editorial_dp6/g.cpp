#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1'000'000'007;

bool isOk(int a, int b) {
	auto s1 = to_string(a);
	auto s2 = to_string(b);
	for (int i = 0; i < s1.size(); ++i) {
		for (int j = 0; j < s2.size(); ++j) {
			if (s1[i] == s2[j]) {
				return false;
			}
		}
	}
	return true;
}

void solve(const vector<vector<int>>& dp) {
	const int MAXK = 999;
	vector<vector<bool>> ok(MAXK + 1, vector<bool>(MAXK + 1));
	for (int i = 1; i <= MAXK; ++i) {
		ok[i][i] = false;
		for (int j = i + 1; j <= MAXK; ++j) {
			ok[i][j] = ok[j][i] = isOk(i, j);
		}
	}

	// dp[len][last] - колво сопособов набрать массив длины len если последнее число last
	// dp[1][i] = 1

	// for len
	//   for last
	//     for current

	// dp[len][current] += dp[len - 1][last] if ok

	// ans = sum(dp[n][i]) i from 1 to k

	// O(k^2 + nk^2 + k) = O(nk^2) ~ 2e8
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve(dp);
	}
}
