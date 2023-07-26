#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

// void solve()
// {
//     int n, k;
//     cin >> n >> k;

//     cout << k + (k-1)/(n-1) << endl;
// }

void solve(vector<int>& v1, vector<int>& v2, int q, int n)
{
//	int l = 0;
//	int r = n - 1;
//
//	while (l < r - 1)
//	{
//		int mid = (l + r) / 2;
//
//		if (v1[mid] <= q)
//		{
//			l = mid;
//		}
//		else
//		{
//			r = mid;
//		}
//	}
//	if (v1[l] >= q) {
//		r = l;
//	}
//
//	cout << r + 1 << endl;
//	return;
	cout << (lower_bound(v1.begin(),  v1.end(), q) - v1.begin()) + 1 << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v1(n);
	vector<int> v2(n);

	int a1;
	cin >> a1;
	v1[0] = a1;
	v2[0] = a1;

	for (int i = 1; i < n; ++i)
	{
		int a;
		cin >> a;
		v1[i] = v1[i-1] + a;
		v2[i] = a;
	}

	// for (int i = 0; i < n; ++i)
	// {
	//     cout << v1[i] << " ";
	// }
	// cout << endl;
	// for (int i = 0; i < n; ++i)
	// {
	//     cout << v2[i] << " ";
	// }

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int q;
		cin >> q;

		solve(v1, v2, q, n);

		// for (int j = 0; j < n; ++j)
		// {
		//     if (q <= v1[0])
		//     {
		//         cout << 1 << endl;
		//         break;
		//     }

		//     if (q <= v1[j])
		//     {
		//         cout << j + 1 << endl;
		//         break;
		//     }
		// }



		// while(t--)
		// {
		//     solve();
		// }

	}
	return 0;
}