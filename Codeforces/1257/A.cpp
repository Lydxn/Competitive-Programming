#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, x, a, b;
    cin >> t;
    
    while (t--)
    {
        cin >> n >> x >> a >> b;
        cout << min(n - 1, abs(a - b) + x) << '\n';
    }
    return 0;
}
