#include <bits/stdc++.h>

using namespace std;

int dp[1000001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M;
    cin >> N >> M;
    
    queue<int> q;
    fill(dp, dp + 1000001, INT_MAX);
    
    q.push(N);
    dp[N] = 0;
    
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        
        if (n == M) break;
        if (3 * n <= 1000000 && dp[3 * n] == INT_MAX) { dp[3 * n] = 1 + dp[n]; q.push(3 * n); }
        if (n > 1 && dp[n - 1] == INT_MAX) { dp[n - 1] = 1 + dp[n]; q.push(n - 1); }
        if (n > 3 && dp[n - 3] == INT_MAX) { dp[n - 3] = 1 + dp[n]; q.push(n - 3); }
        if (n % 2 == 0 && dp[n / 2] == INT_MAX) { dp[n / 2] = 1 + dp[n]; q.push(n / 2); }
    }
    
    cout << dp[M] << '\n';
    return 0;
}
