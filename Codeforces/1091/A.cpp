#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int y, b, r;
    cin >> y >> b >> r;
    
    cout << min(y + 2, min(b + 1, r)) * 3 - 3 << '\n';
    return 0;
}
