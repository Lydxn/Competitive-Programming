#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, a, b, c, d, thomas, ans = 1;
    cin >> n;
    
    cin >> a >> b >> c >> d;
    thomas = a + b + c + d;
    
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c >> d;
        if (a + b + c + d > thomas) ++ans;
    }
    
    cout << ans << '\n';
    return 0;
}
