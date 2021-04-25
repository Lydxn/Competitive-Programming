#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int t, a, b, k;
    cin >> t;
    
    while (t--)
    {
        cin >> a >> b >> k;
        cout << (long long) (a - b) * (k / 2) + a * (k % 2) << '\n';
    }
    return 0;
}
