#include <bits/stdc++.h>

using namespace std;

int a[100], dp[100][3];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    fill(&dp[0][0], &dp[0][0] + 300, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
        if (a[i] == 2 || a[i] == 3) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        if (a[i] == 1 || a[i] == 3) dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    }
    
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << '\n';
    return 0;
}
