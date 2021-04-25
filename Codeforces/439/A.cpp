#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, d, t, sum = 0;
    cin >> n >> d;
    
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        sum += t;
    }
    
    cout << (sum + 10 * (n - 1) <= d ? (d - sum) / 5 : -1) << '\n';
    return 0;
}
