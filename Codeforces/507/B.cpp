#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    double r, x, y, xp, yp;
    cin >> r >> x >> y >> xp >> yp;
    
    cout << ceil(sqrt((x - xp) * (x - xp) + (y - yp) * (y - yp)) / (2 * r)) << '\n';
    return 0;
}
