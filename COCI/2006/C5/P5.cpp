#include <bits/stdc++.h>

using namespace std;

int odds[200], dp[200][200];

int start(int i, int j) {
    if (~dp[i][j]) return dp[i][j];
    if (i == j) return dp[i][j] = odds[i];
    return dp[i][j] = max(odds[i] - start(i + 1, j), odds[j] - start(i, j - 1));
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, cnt = 0;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> odds[i];
        odds[i] &= 1, odds[i + N] = odds[i];
    }
    
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < N; i++) {
        if (odds[i] - start(i + 1, i + N - 1) > 0) ++cnt;
    }
    cout << cnt << '\n';
    return 0;
}
