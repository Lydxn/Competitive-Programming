#include <bits/stdc++.h>

using namespace std;

int t[100000];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, sum = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i];
    
    sort(t, t + n);
    
    for (int i = 0; i < n; i++)
    {
        if (sum <= t[i])
        {
            sum += t[i];
            ++ans;
        }
    }
    
    cout << ans << '\n';
    return 0;
}
