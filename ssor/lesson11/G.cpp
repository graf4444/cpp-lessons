#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9 + 7;
//#define endl '\n'

void solve() {
    int n;
    cin >> n;
//    n = 100;
    vector<vector<int>> ok(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ok[i][j];
//            ok[i][j] = 1;
        }
    }
    int m;
    cin >> m;
//    m = 3000;
    // m + 1
    // X----------X
    // dp[i][j] - сделал i шагов и нахожусь в j-ой вершине = кол-во способов
    int ans = 0;
    for (int start = 0; start < n; ++start) {
        vector<vector<int>> dp(m + 1, vector<int>(n));
        dp[0][start] = 1;
        for (int len = 0; len < m; ++len) {
            for (int cur = 0; cur < n; ++cur) {
                for (int nxt = 0; nxt < n; ++nxt) {
                    if (!ok[cur][nxt]) continue;
                    dp[len + 1][nxt] += dp[len][cur];
                    dp[len + 1][nxt] -= (dp[len + 1][nxt] >= MOD) * MOD;
                }
            }
        }
        ans += dp[m][start];
        ans %= MOD;
        // 1 2 1
    }
    cout << ans << endl;
    //O(n * m * n * n) = 10^6 * 3000 = 3e9
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

