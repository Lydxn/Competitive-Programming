#include <bits/stdc++.h>

using namespace std;

int pins[30000], adj[30000], dp[501][30000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, k, w;
    cin >> t;
    
    while (t--) {
        cin >> n >> k >> w;
        for (int i = 0; i < n; i++) cin >> pins[i];
        memset(adj, 0, sizeof(adj)); memset(dp, 0, sizeof(dp));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < w && i >= j; j++) {
                adj[i] += pins[i - j];
            }
        }
        
        for (int i = 1; i <= k; i++) {
            dp[i][0] = pins[0];
            for (int j = 1; j < n; j++) {
                dp[i][j] = max((j >= w ? dp[i - 1][j - w] : 0) + adj[j], dp[i][j - 1]);
            }
        }
        
        cout << dp[k][n - 1] << '\n';
    }
    return 0;
}
