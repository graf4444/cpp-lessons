#include <bits/stdc++.h>

using namespace std;

vector<bool> used;

// dfs O(n + m)
bool go(const vector<vector<int>>& g, int cur, int finish, vector<int>& ans) {
    used[cur] = true;
    if (cur == finish) {
        ans.push_back(cur);
        return true;
    }
    for (int to: g[cur]) {
        if (used[to]) continue;
        if (go(g, to, finish, ans)) {
            ans.push_back(cur);
            return true;
        }
    }
    return false;
}

int calcD(const vector<vector<int>>& g, int cur, int from) {
    int ans = 0;
    for (int to: g[cur]) {
        if (to == from) continue;
        ans = max(ans, calcD(g, to, cur) + 1);
    }
    return ans;
}

// bfs O(n + m)
bool go2(const vector<vector<int>>& g, int start, int finish, vector<int>& ans) {
    queue<int> q;
    int n = g.size();
    const int INF = 1e9;
    vector<int> d(n, INF);
    vector<int> from(n);
    q.push(start);
    d[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == finish) break;
        for (int to: g[cur]) {
            if (d[to] < INF) continue;
            d[to] = d[cur] + 1;
            from[to] = cur;
            q.push(to);
        }
    }
    if (d[finish] == INF) return false;
    int cur = finish;
    while (cur != start) {
        ans.push_back(cur);
        for (int from: g[cur]) {
            if (d[from] + 1 == d[cur]) {
                cur = from;
                break;
            }
        }
    }
    ans.push_back(start);
    return true;
}

vector<int> used;
// 0 - не посещали вообще
// 2 - посетили всех соседей и вышли
// 1 - обошли еще не все(на пути)

// O(n + m)
bool checkCycle(const vector<vector<int>>& g, int cur, int from, vector<int>& ans) {
    if (used[cur] == 2) {
        return false;
    }
    if (used[cur] == 1) {
        ans.push_back(cur);
        return true;
    }
    used[cur] = 1;
    for (int to: g[cur]) {
        if (go(g, to, cur)) {
            if ( == ans[0])
            ans.push_back(cur);
            return true;
        }
    }
    used[cur] = 2;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    used.assign(n, false);
    // матрица смежности
    // nxn 0 - нет ребра, 1 есть

    // списки смежности
    // для каждой вершины храним куда есть ребро
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        // g[b].push_back(a);
    }

    int start, finish;
    cin >> start >> finish;
    cout << start << " " << finish << endl;
    start--;
    finish--;
    vector<int> ans;
    if (!go(g, start, finish, ans)) {
        cout << "LOSE" << endl;
        return 0;
    }
    cout << "WIN" << endl;
    reverse(ans.begin(), ans.end());
    for (auto v: ans) {
        cout << v + 1 << " ";
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        if (used[i]) continue;
        cnt++;
        bfs/dfs
    }
}


// (n < 10^5, m < 10^5)
// 4 5 
// 1 2
// 2 2
// 2 3
// 1 3
// 3 4

дерево
// n n - 1 связный
// n вершин связный без циклов
// n вершин и мин колво ребер так чтобы был связный

компоненты связности
