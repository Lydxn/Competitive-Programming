#include <bits/stdc++.h>

using namespace std;

int a[150000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, ans, min_a;
    cin >> t;
    
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        
        ans = 0, min_a = INT_MAX;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > min_a) ++ans;
            min_a = min(min_a, a[i]);
        }
        
        cout << ans << '\n';
    }
    return 0;
}
