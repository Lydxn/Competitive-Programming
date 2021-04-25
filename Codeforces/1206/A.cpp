#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, a_max = 0, b_max = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        a_max = max(a_max, a);
    }
    
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        b_max = max(b_max, b);
    }
    
    cout << a_max << ' ' << b_max << '\n';
    return 0;
}
