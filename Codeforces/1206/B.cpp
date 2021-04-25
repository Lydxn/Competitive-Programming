#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, a;
    cin >> n;
    
    bool neg = false, zero = false;
    long long ans = 0;
    while (n--)
    {
        cin >> a;
        if (a == 0)     ++ans, zero = true;
        else if (a > 0) ans += a - 1;
        else            ans += -a - 1, neg ^= true;
    }
    
    cout << ans + 2 * neg * !zero;
    return 0;
}
