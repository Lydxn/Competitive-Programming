#include <bits/stdc++.h>

using namespace std;

int val[1001], dp[1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> val[i];
    
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i] = max(dp[i], dp[i - j] + val[j]);
        }
    }
    
    cout << dp[N] << '\n';
    return 0;
}
