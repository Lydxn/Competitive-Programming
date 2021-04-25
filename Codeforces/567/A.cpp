#include <bits/stdc++.h>

using namespace std;

int x[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    
    for (int i = 0; i < n; i++)
    {
        if      (i == 0)     cout << x[1] - x[0] << ' ' << x[n - 1] - x[0] << '\n';
        else if (i == n - 1) cout << x[n - 1] - x[n - 2] << ' ' << x[n - 1] - x[0] << '\n';
        else                 cout << min(x[i] - x[i - 1], x[i + 1] - x[i]) << ' ' << max(x[i] - x[0], x[n - 1] - x[i]) << '\n';
    }
    return 0;
}
