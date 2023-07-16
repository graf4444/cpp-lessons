#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> ar(n, 0);
	for (int i = 2; i <= n; ++i) {
		for (int j = i - 1; j < n; j += i) {
			ar[j] = !ar[j];
		}
		for (auto v: ar) {
			cout << v;
		}
		cout << endl;
	}

	// n - [sqrt(n)]
}