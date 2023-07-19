#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> matr;
ll ans = 0;

void updRes(vector<int>& perm) {
	ll cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += matr[i][perm[i]];
	}
	ans = max(ans, cur);
}

void go(vector<int>& perm, vector<bool>& used, int n) {
	if (perm.size() == n) {
		updRes(perm);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (used[i]) continue;
		perm.push_back(i);
		used[i] = true;
		go(perm, used, n);
		used[i] = false;
		perm.pop_back();
	}
}

void solve() {
	int n;
	cin >> n;
	matr.resize(n);
	for (int i = 0; i < n; ++i) {
		matr[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> matr[i][j];
		}
	}
	vector<int> perm;
	vector<bool> used(n);
	go(tmp, used, n);
	cout << ans << endl;
}

void solve2() {
	int n;
	cin >> n;
	matr.resize(n);
	for (int i = 0; i < n; ++i) {
		matr[i].resize(n);
		for (int j = 0; j < n; ++j) {
			cin >> matr[i][j];
		}
	}
	vector<int> perm(n);
	// fill vector with 0, 1, 2, ..., n - 1
	iota(perm.begin(),  perm.end(), 0);
	do {
		updRes(perm);
	} while (next_permutation(perm.begin(),  perm.end()));
	cout << ans << endl;
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
