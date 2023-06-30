#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//using team = pair<pair<int, int>, string>;
using ll = long long;

struct team {
	int s;
	int p;
	string name;
};

bool cmp(const team& a, const team& b) {
	if (a.s != b.s) {
		return a.s > b.s;
	}

	if (a.p != b.p) {
		return a.p < b.p;
	}

	return a.name < b.name;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<team> ar(n);
	for (auto& p: ar) {
		cin >> p.name >> p.s >> p.p;
	}
	sort(ar.begin(), ar.end(), cmp);
	for (auto& p: ar) {
		cout << p.name << endl;
	}
}
