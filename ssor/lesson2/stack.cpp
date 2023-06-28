#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//#define endl '\n'

void solve() {
	// array
	// list
	// stack
	// queue
	// deque

	// FILO - first in, last out
	stack<int> st;
	st.push(65);
	cout << st.size() << endl;
	if (!st.empty()) {
		cout << st.top() << endl;
	} else {
		cout << "empty!" << endl;
	}
	st.pop();

	// FIFO - first in, first out
	queue<int> q;
	q.push(65);
	cout << q.size() << endl;
	if (!q.empty()) {
		cout << q.front() << endl;
	} else {
		cout << "empty!" << endl;
	}
	q.pop();

	// haos, lol kek
	deque<int> d;
	d.push_front(65);
	d.push_back(67);
	cout << d.size() << endl;
	if (!d.empty()) {
		cout << d.front() << endl;
		cout << d.back() << endl;
	} else {
		cout << "empty!" << endl;
	}
	d.pop_front();
	d.pop_back();

	list<int> l;
	auto it = l.begin();
	it++;
	it++;
	// advance(it, 2);
	cout << *it << endl;
	l.erase(it);
	l.insert(it, 5);
	l.insert(l.end(), 7);
//	l.push_back(7);
	l.insert(l.begin(), 9);
//	l.push_front(9);
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
