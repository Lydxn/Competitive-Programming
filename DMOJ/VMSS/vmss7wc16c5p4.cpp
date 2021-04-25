#include <bits/stdc++.h>

using namespace std;

int dp[100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, vals[3];
    cin >> N >> vals[0] >> vals[1] >> vals[2];

    fill(dp + 1, dp + N + 1, INT_MIN);
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            if (i - vals[j] >= 0) {
                dp[i] = max(dp[i], dp[i - vals[j]] + 1);
            }
        }
    }

    cout << dp[N] << '\n';
    return 0;
}
