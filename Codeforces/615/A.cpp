#include <bits/stdc++.h>

using namespace std;

bool bulbs[101];

bool all_on(int m)
{
    for (int i = 1; i <= m; i++) if (!bulbs[i]) return false;
    return true;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x, y;
    cin >> n >> m;
    
    while (n--)
    {
        cin >> x;
        while (x--)
        {
            cin >> y;
            bulbs[y] = true;
        }
    }
    
    cout << (all_on(m) ? "YES" : "NO") << '\n';
    return 0;
}
