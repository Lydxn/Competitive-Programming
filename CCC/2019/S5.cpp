#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, dp[3000][3000];

void solve(int K) {
    if (K > 1) {
        int k = K * 2 / 3 + (K % 3 && K > 2); solve(k);
        for (int i = 0; i <= N - K; i++) {
            for (int j = 0; j <= i; j++) {
                dp[i][j] = max(dp[i][j], max(dp[i + K - k][j], dp[i + K - k][j + K - k]));
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int K; ll ans = 0;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> dp[i][j];
        }
    }
    
    solve(K);
    for (int i = 0; i <= N - K; i++) {
        for (int j = 0; j <= i; j++) {
            ans += dp[i][j];
        }
    }
    
    cout << ans << '\n';
    return 0;
}
