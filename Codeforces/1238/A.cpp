#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    long long x, y;
    while (t--)
    {
        cin >> x >> y;
        cout << (x - y != 1 ? "YES" : "NO") << '\n';
    }
    return 0;
}
