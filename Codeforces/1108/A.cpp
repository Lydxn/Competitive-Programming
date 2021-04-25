#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int q, l1, r1, l2, r2;
    cin >> q;
    
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        if      (l1 != l2) cout << l1 << ' ' << l2 << '\n';
        else if (l1 != r2) cout << l1 << ' ' << r2 << '\n';
        else if (r1 != l1) cout << r1 << ' ' << l1 << '\n';
        else if (r1 != r2) cout << r1 << ' ' << r2 << '\n';
    }
    return 0;
}
