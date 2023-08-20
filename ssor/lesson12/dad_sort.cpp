#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	// [1 2][7 3 7 2 9 3][10 11 23]
	// 1 2 2 3 3 7 7 9 10 11 23
	// находим отрезки которые надо сортить как в сравнении мультисетов


	// (l1, r1), (l2, r2), ... (lm, rm)
	// (l1, r3)

	//	m > k (((

	//	dp[i][cnt] - посорчены уже i отрезков, звал папу cnt раз = мин сумме длин запросов
	ans = sum(r[i] - l[i] + 1); // добавляем в ответ то что в любом случае сортить надо
	dp[i + 1][cnt + 1] = min(dp[i + 1][cnt + 1], dp[i][cnt]); // сортим сейчас если cnt + 1 <= k
	dp[i + 1][cnt] = min(dp[i + 1][cnt], dp[i][cnt] + l[i + 1] - r[i] - 1); // ждем

	// последний точно сортим, ждать нельзя
	cout << ans + min(dp[m][i])
}

multiset<int> ok;
multiset<int> bad;
for (int i = 0; i < n; ++i) {
	if (*ok.begin() < ar[i] && *bad.begin() >= ar[i]) {
		ans++;
		bad.insert(ar[i]);
	}
	if (ar[i] < *ok.begin()) {
		ok.insert(ar[i]);
	}
}