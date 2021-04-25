#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin >> t;
    
    long long sum, pow2;
    while (t--)
    {
        cin >> n;
        sum = (long long) n * (n + 1) / 2;
        
        pow2 = 1;
        while (pow2 <= n) sum -= pow2 << 1, pow2 <<= 1;
        
        cout << sum << '\n';
    }
    return 0;
}
