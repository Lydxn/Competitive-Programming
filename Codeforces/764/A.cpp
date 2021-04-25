#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, z, ans = 0;
    cin >> n >> m >> z;
    
    for (int i = 1; i <= z; i++)
    {
        if (i % n == 0 && i % m == 0) ++ans;
    }
    
    cout << ans << '\n';
    return 0;
}
