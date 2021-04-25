#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, val, ans = 0;
    cin >> N;
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> val;
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + val;
        }
    }
    
    for (int i = 1; i <= N; i++) ans = max(ans, dp[N][i]);
    cout << ans << '\n';
    return 0;
}
