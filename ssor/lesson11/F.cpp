#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> need(k), ar(n);
    for (auto& v: need) {
        cin >> v;
    }
    for (auto& v: ar) {
        cin >> v;
    }
    map<int, int> mp;
    for (int i = 0; i < k; ++i) {
        mp[need[i]]--;
    }
    for (int i = 0; i < k; ++i) {
        mp[ar[i]]++;
    }
    int bad = 0;
    for (auto [_, v]: mp) {
        if (v != 0) {
            bad++;
        }
    }
    int ans = (bad == 0);
    // < 0 need
    // > 0 dont need
    // == 0 OK
    for (int i = k; i < n; ++i) {
        if (mp[ar[i]] == 0) {
            bad++;
        }
        mp[ar[i]]++;
        if (mp[ar[i]] == 0) {
            bad--;
        }
        if (mp[ar[i - k]] == 0) {
            bad++;
        }
        mp[ar[i - k]]--;
        if (mp[ar[i - k]] == 0) {
            bad--;
        }
        ans += bad == 0;
    }
    cout << ans << endl;
    // O((n + k)log(n + k))
    // O(nlogn + klogk + (n - k) * (k))
    // n = 1e5, k = 5e4
    // 1 2 3 4 5 6 7 ... n/2 1 2 3 4 ... n/2
    // 10^10 / 4 = 25 * 10^8
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

