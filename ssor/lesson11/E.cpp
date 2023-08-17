#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

struct event {
    int t;
    int type;
    int id;
    int cluster;
    int i;
    bool operator <(const event& other) const {
        if (t != other.t) {
            return t < other.t;
        }
        return type < other.type;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> where;
    map<int, int> cnt;
    vector<event> events;
    for (int i = 0; i < n; ++i) {
        char c;
        int t, id, cluster, type;
        string tmp;
        cin >> c >> t >> c >> c >> id >> c >> tmp;
        type = tmp[0] == 'I';
        // 0 - OUT
        // 1 - IN
        stringstream ss(tmp);
        do {
            ss >> c;
        } while (c != '_');
        ss >> cluster;
        events.push_back(event{.t = t, .type = type, .id = id, .cluster = cluster});
    }
    for (int i = 0; i < m; ++i) {
        int type;
        cin >> type;
        int id, t, cluster;
        if (type == 1) {
            cin >> id >> t;
            events.push_back(event{.t = t, .type = 2, .id = id, .i = i});
            // 2 - 1st query
        } else {
            cin >> cluster >> t;
            events.push_back(event{.t = t, .type = 3, .cluster = cluster, .i = i});
            // 3 - 2nd query
        }
    }
    sort(events.begin(), events.end());
    vector<int> ans(m);
    for (auto e: events) {
        if (e.type == 0) {
            cnt[e.cluster]--;
            where[e.id] = 0;
        } else if (e.type == 1) {
            cnt[e.cluster]++;
            where[e.id] = e.cluster;
        } else if (e.type == 2){
            ans[e.i] = where[e.id];
        } else {
            ans[e.i] = cnt[e.cluster];
        }
    }

    for (auto v: ans) {
        cout << v << " ";
    }
    cout << endl;
    // O((n + m)log(n + m) + m)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
}

/*
 * 1: 1
 * 2: 2
 * 3: 1 2
 *
 */