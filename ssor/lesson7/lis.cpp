#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
	// Longest Increasing Subsequence
	// Наибольшая возрастающая подпоследовательность
	int n;
	cin >> n;
	vector<int> ar(n);
	for (auto& v: ar) {
	    cin >> v;
	}

	const int MAX_VALUE = 1e5;
	vector<int> dp(MAX_VALUE + 1);
	vector<int> from(n, -1);

	// dp[i] - ? длина нвп которая заканчивается числом i
	// dp[i][j][k] - сколько денег ты получишь если сейчас i-й лунный день, длина волос у тебя j см, под окном стоит k машин

	// идем по массиву и пробуем приписать куда-то ar[i]
	for (int i = 0; i < n; ++i) {
		// выбираем куда припишем, а именно какой там был последний элемент
		for (int last = 0; last < ar[i]; ++last) {
			// либо оставляем то что было, либо берем эту подпоследовательность и дописываем ar[i]
			if (dp[last] + 1 >= dp[ar[i]]) {
				dp[ar[i]] = dp[last] + 1;
				from[i] = last;
			}
		}
	}
	// O(n * max(ar[i]))
	auto it = max_element(dp.begin(),  dp.end());
	int ansLen = *it;
	cout << "ans is " << ansLen << endl;
	vector<int> ans;
	int cur = it - dp.begin();
	for (int i = n - 1; i >= 0 && ans.size() < ansLen; --i) {
		if (ar[i] != cur) continue;
		ans.push_back(cur);
		cur = from[i];
	}
	reverse(ans.begin(),  ans.end());
	for (auto v: ans) {
		cout << v << " ";
	}
	cout << endl;
}

// [0, 1, 2, 3, 4, 5, 6, 0, 7, 0, 3, 4, 5, 6, 7, 0]

// 8

// 1 2 10 11 12 3 4 13 14 5 5 6 8 - ar
// 0 1 2  10 11 2 3 12 13 4 4 5 6 - from

// lis: 1 2 3 4 5 6 7 8
// Ans = 8

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}
