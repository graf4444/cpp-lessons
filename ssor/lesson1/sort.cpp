#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define endl '\n'

void sortBubble(vector<int>& ar) {
	bool was = true;
	while (was) {
		was = false;
		for (int i = 1; i < ar.size(); ++i) {
			if (ar[i] < ar[i - 1]) {
				swap(ar[i - 1], ar[i]);
				was = true;
			}
		}
	}
}

struct point{
	int x;
	int y;
	point() {}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	int len() const {
		return x * x + y * y;
	}
	bool operator < (point b) const {
		return len() < b.len();
	}
};

// s1.size() = n
// s2.size() = m
// O(min(n, m))

bool cmp(const point& a, const point& b) {
	int l1 = a.len();
	int l2 = b.len();
	return l1 < l2;
}

bool operator < (point a, point b) {
	return cmp(a, b);
}

void solve() {
	int n;
	cin >> n;
	int lol{5};
	vector<point> ar(n);

	for (int i = 0; i < n; ++i) {
	    cin >> ar[i].x >> ar[i].y;
	}
	cout << (ar[0] < ar[1]) << endl;
	// O(nlog(n)) ; log^2(n) ~ n^0.5
	sort(ar.begin(),  ar.end(), cmp);

	for (int i = 0; i < n; ++i) {
		cout << ar[i].x << " " << ar[i].y << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}