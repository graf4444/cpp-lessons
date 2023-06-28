#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//#define endl '\n'

int ask(int m) {
	cout << m << endl;
	char res;
	cin >> res;
	if (res == '<') return -1;
	else if (res == '>') return 1;
	return 0;
}

void solve() {
	int l = 0;
	int r = 1e9;

	while (l < r) {
		int m = (l + r) / 2;
		int res = ask(m);
		if (res < 0) {
			l = m + 1;
		} else if (res > 0){
			r = m - 1;
		} else {
			return;
		}
	}
	ask(l);
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