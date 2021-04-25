#include <bits/stdc++.h>

using namespace std;

bool dp[100][8];
string ans[100][8];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    string n;
    cin >> n;

    dp[0][0] = true, dp[0][(n[0] - '0') % 8] = true;
    ans[0][0] = "", ans[0][(n[0] - '0') % 8] = n[0];
    
    for (int i = 1; i < n.size(); i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (dp[i - 1][j])
            {
                ans[i][j] = ans[i - 1][j];
                ans[i][(j * 10 + n[i] - '0') % 8] = ans[i - 1][j] + n[i];
            }
            
            dp[i][j] |= dp[i - 1][j];
            dp[i][(j * 10 + n[i] - '0') % 8] |= dp[i - 1][j];
        }
    }

    for (int i = 0; i < n.size(); i++)
    {
        if (dp[i][0] && !ans[i][0].empty())
        {
            cout << "YES\n" << ans[i][0] << '\n';
            return 0;
        }
    }
    
    cout << "NO\n";
    return 0;
}
