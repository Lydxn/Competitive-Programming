#include <bits/stdc++.h>

using namespace std;

int psa[401][401];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int R, C, ans = 0;
    cin >> R >> C;
    
    char ch;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> ch;
            psa[i][j] += psa[i][j - 1] + (ch == '.');
        }
    }
    
    for (int i = 1; i <= C; i++)
    {
        for (int j = i; j <= C; j++)
        {
            int cur = 0, consec = 0, len = j - i + 1;
            for (int k = 1; k <= R; k++)
            {
                if (psa[k][j] - psa[k][i - 1] == len) cur = max(cur, ++consec);
                else consec = 0;
            }
            
            if (cur) ans = max(ans, (cur + len) << 1);
        }
    }
    
    cout << ans - 1 << '\n';
    return 0;
}
