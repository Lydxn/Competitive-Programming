#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[400][400], a[400];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N; ll sum;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    
    for (int i = N - 1; i >= 0; i--) {
        for (int j = i; j < N; j++) {
            if (i == j) dp[i][j] = 0;
            else {
                dp[i][j] = LLONG_MAX, sum = 0;
                for (int k = i; k <= j; k++) sum += a[k];
                for (int k = i; k < j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
            }
        }
    }
    
    cout << dp[0][N - 1] << '\n';
    return 0;
}
