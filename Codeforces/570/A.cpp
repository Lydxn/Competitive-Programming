#include <bits/stdc++.h>

using namespace std;

int cand[101];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, max, idx;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        max = idx = -1;
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            if (max < a) max = a, idx = j;
        }
        ++cand[idx];
    }
    
    max = idx = -1;
    for (int i = 1; i <= n; i++)
    {
        if (max < cand[i])
        {
            max = cand[i];
            idx = i;
        }
    }
    
    cout << idx << '\n';
    return 0;
}
