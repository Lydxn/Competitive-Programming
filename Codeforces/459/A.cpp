#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int x1, x2, y1, y2, xdiff, ydiff;
    cin >> x1 >> y1 >> x2 >> y2;
    
    xdiff = abs(x1 - x2), ydiff = abs(y1 - y2);
    
    if      (x1 == x2)       cout << x1 + ydiff << ' ' << y1 << ' ' << x2 + ydiff << ' ' << y2 << '\n';
    else if (y1 == y2)       cout << x1 << ' ' << y1 + xdiff << ' ' << x2 << ' ' << y2 + xdiff << '\n';
    else if (xdiff == ydiff) cout << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << '\n';
    else                     cout << -1 << '\n';
    return 0;
}
