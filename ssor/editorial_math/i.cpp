#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios :: sync_with_stdio(0); cin.tie(0);
	int t;

	long long ans = 1;
	long long m; cin >> m;
	vector<int> prime(m + 1, 0);
	prime[0] = prime[1] = 1;
	for (long long i = 2; i * i <= m; ++i) {
		if (prime[i]) continue;

		for (long long j = i; i * j <= m; ++j) {
			prime[j * i] = i;
		}
	}
	//cout << "here" << endl;
	for (long long i = 0; i < m + 1; ++i) {
		if (prime[i] == 0) prime[i] = i;
	}
	/*for(auto& x : prime)
	{
		cout << x << ' ';
	}*/
	while(m > 1)
	{
		int p = prime[m];
		//cout << p << endl;
		int k = 0;
		while(m % p == 0)
		{
			k++; m /= p;
		}
		ans *= (k + 1);
	}
	cout << ans;
	return 0;
}