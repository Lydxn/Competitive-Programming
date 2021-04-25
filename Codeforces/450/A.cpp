#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, a, ans = 0, idx;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        a = (a + m - 1) / m;
        
        if (ans <= a) ans = a, idx = i;
    }
    
    cout << idx << '\n';
    return 0;
}
