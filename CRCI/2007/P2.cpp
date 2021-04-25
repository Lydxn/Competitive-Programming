#include <bits/stdc++.h>

using namespace std;

int N, fee[1000], dp[1000][1001];

int solve(int i, int j) {
    if (i < 0 || i >= N) return INT_MAX;
    if (~dp[i][j]) return dp[i][j];
    if (i == N - 1) return fee[i];
    return dp[i][j] = fee[i] + min(solve(i - j, j), solve(i + j + 1, j + 1));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) cin >> fee[i];
    
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    cout << solve(1, 1) << '\n';
    return 0;
}
