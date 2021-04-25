#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, a, b, c, d, k, x, y;
    cin >> t;
    
    while (t--)
    {
        cin >> a >> b >> c >> d >> k;
        
        x = (a + c - 1) / c, y = (b + d - 1) / d;
        
        if (x + y <= k) cout << x << ' ' << y << '\n';
        else            cout << "-1\n";
    }
    return 0;
}
