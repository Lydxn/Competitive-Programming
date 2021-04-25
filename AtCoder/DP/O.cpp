#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
ll dp[1 << 21];
bool a[21][21];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }
    
    dp[0] = 1;
    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < N; j++) {
            if (a[__builtin_popcount(i)][j] && !(i & 1 << j)) {
                dp[i | 1 << j] = (dp[i | 1 << j] + dp[i]) % MOD;
            }
        }
    }
    
    cout << dp[(1 << N) - 1] << '\n';
    return 0;
}
