#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[20];
int n, dp[18][262144];

int dfs(int curr, int mask) {
    if (dp[curr][mask] != -1) return dp[curr][mask];
    if (curr == n - 1) return dp[curr][mask] = 0;
    
    int ans = INT_MIN;
    for (auto i : adj[curr]) {
        if (!(mask & (1 << curr))) {
            ans = max(ans, dfs(i.first, mask | (1 << curr)) + i.second);
        }
    }
    return dp[curr][mask] = ans;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int m, s, d, l;
    cin >> n >> m;
    
    while (m--) {
        cin >> s >> d >> l;
        adj[s].emplace_back(d, l);
    }
    
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0) << '\n';
    return 0;
}
