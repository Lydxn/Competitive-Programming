#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int a1, a2, mins = 0;
    cin >> a1 >> a2;
    
    while (++mins)
    {
        if      (a1 > 2) a1 -= 2, ++a2;
        else if (a2 > 2) a2 -= 2, ++a1;
        else             break;
    }
    
    cout << (a1 > 1 || a2 > 1 ? mins : 0) << '\n';
    return 0;
}
