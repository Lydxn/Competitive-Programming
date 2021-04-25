#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int T, l, r;
    cin >> T;
    
    while (T--)
    {
        cin >> l >> r;
        cout << l << ' ' << 2 * l << '\n';
    }
    return 0;
}
