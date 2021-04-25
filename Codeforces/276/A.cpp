#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, k, f, t, max_joy = INT_MIN;
    cin >> n >> k;
    
    for (int i = 0; i < n; i++)
    {
        cin >> f >> t;
        max_joy = max(max_joy, t <= k ? f : f - (t - k));
    }
    
    cout << max_joy << '\n';
    return 0;
}
