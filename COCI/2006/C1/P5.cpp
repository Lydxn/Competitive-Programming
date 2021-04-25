#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 20;
int bond[MAXN][MAXN];
double dp[1 << MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> bond[i][j];
        }
    }
    
    dp[0] = 1;
    for (int i = 0; i < (1 << N); i++)
    {
        int sz = __builtin_popcount(i);
        for (int j = 0; j < N; j++)
        {
            if ((i & (1 << j)) == 0) dp[i | (1 << j)] = max(dp[i | (1 << j)], dp[i] * bond[sz][j] / 100);
        }
    }
    
    cout << fixed << setprecision(6);
    cout << 100 * dp[(1 << N) - 1] << '\n';
    return 0;
}
