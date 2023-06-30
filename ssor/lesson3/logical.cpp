#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//using team = pair<pair<int, int>, string>;
using ll = long long;

bool f1() {
	cout << "f1" << endl;
	return true;
}

bool f2() {
	cout << "f2" << endl;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> ar(10);
	int i;
	cin >> i;
	if (f1() || f2()) {
		cout << "!!!" << endl;
	} else {
		cout << "(((" << endl;
	}
}
