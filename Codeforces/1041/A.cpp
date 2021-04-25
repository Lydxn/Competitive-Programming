#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, a, min_idx = INT_MAX, max_idx = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        min_idx = min(min_idx, a);
        max_idx = max(max_idx, a);
    }
    
    cout << max(0, max_idx - min_idx - n + 1) << '\n';
    return 0;
}
