#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ar(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        ar[a].push_back(i);
        ar[b].push_back(i);
    }
    vector<int> st(m);
    long long ans = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        for (int v: ar[i]) {
            while (st[v]) {
                for (auto v2: ar[l]) {
                    st[v2]--;
                }
                l++;
            }
            st[v]++;
        }
        // [l, i]
        ans += i - l + 1;
    }
    cout << ans << endl;
    // O(n + mlogm)
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
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