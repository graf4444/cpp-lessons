#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
using ll = long long;

vector<pair<char, char>> brackets{{'(', ')'}, {'[', ']'}, {'{', '}'}};

bool ok(stack<char>& st, char c) {
	if (st.empty()) return false;
	char top = st.top();
	for (auto [l, r]: brackets) {
		if (top == l && c == r) {
			return true;
		}
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	stack<char> st;
	for (char c: s) {
		if (c == '(' || c == '[' || c == '{') {
			st.push(c);
		} else if (ok(st, c)){
			st.pop();
		} else {
			cout << "Nein" << endl;
			return;
		}
	}
	if (st.empty()) {
		cout << "Ja" << endl;
	} else {
		cout << "Nein" << endl;
	}
	// (([]))

	// ( ( [
	// ((((((((((((((((((((((((((((((((((((((((((((((((()))))))))))))))))))))))))))))))))))))))))()
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
