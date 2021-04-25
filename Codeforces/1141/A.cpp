#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    if (m % n) cout << -1 << '\n';
    else
    {
        int div = m / n, res = 0;
        
        for (; div % 2 == 0; div /= 2, res++);
        for (; div % 3 == 0; div /= 3, res++);
        
        cout << (div == 1 ? res : -1) << '\n';
    }
    return 0;
}
