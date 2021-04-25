#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char grid[2000][2000];
int dp[2000][2000], N;

int solve(int i, int j) {
    if (j < 0 || j >= N || i >= N) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = grid[i][j] == '#' ? 1 + min(solve(i + 1, j - 1), min(solve(i + 1, j), solve(i + 1, j + 1))) : 0;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int cnt = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cnt += solve(i, j);
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
