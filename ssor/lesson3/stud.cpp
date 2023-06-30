#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
//using team = pair<pair<int, int>, string>;
using ll = long long;

struct student {
	string name, surname;
	int age;
	double avg;
	string group;
};

bool cmp(const student& a, const student& b) {
	return a.avg > b.avg;
}

void print(const student& a) {
	cout << "Name: " << a.name << endl;
	cout << "avg " << a.avg << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<student> group(5);
	for (int i = 0; i < group.size(); ++i) {
		cin >> group[i].name >> group[i].surname >> group[i].age >> group[i].avg >> group[i].group;
	}
	int mn = 0;
	int mx = 0;
	for (int i = 0; i < group.size(); ++i) {
		if (group[mx].avg < group[i].avg) {
			mx = i;
		}
		if (group[mn].avg > group[i].avg) {
			mn = i;
		}
	}
	cout << "MIN:" << endl;
	print(group[mn]);
	cout << "MAX:" << endl;
	print(group[mx]);
}
