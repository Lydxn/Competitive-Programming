#include <bits/stdc++.h>

#define add_mod(a, b) a += b; if (a >= MOD) a -= MOD

using namespace std;

typedef long long ll;

const int MOD = 1000000007;
int n, k, d;
ll dp[101][2];

int solve(int weight, bool yes)
{
    if (weight == n && yes) return 1;
    if (weight > n)         return 0;
    if (~dp[weight][yes])   return dp[weight][yes];
    
    ll ans = 0;
    for (int i = 1; i <= k; i++) add_mod(ans, solve(weight + i, i >= d || yes));
    return dp[weight][yes] = ans % MOD;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k >> d;
    
    memset(dp, -1, sizeof(dp));
    cout << solve(0, false) << '\n';
    return 0;
}
