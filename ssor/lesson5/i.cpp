#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 100;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> per(n);
	vector<int> used(n+1);

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		per[i] = x;
		if (per[i])
		{
			if (x > n || used[x]) {
				cout << -1 << endl;
				return 0;
			}
			used[x] = 1;
		}
	}
	int p = 1;
	int complexity = 0;
	for (int i = 0; i < n; ++i) {
		complexity += 3;
		if (per[i]) continue;
		while (p <= n && used[p])
		{
			p++;
			complexity += 3;
		}
		complexity += 2;
		per[i] = p;
		used[p] = 1;
	}

	for (auto v: per) {
		cout << v << " ";
	}
	cout << endl;
}