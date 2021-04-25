#include <bits/stdc++.h>

using namespace std;

int p[2001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, groups = 0, count;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    
    for (int i = 1; i <= n; i++)
    {
        count = 0;
        for (int curr = p[i]; curr != -1; count++) curr = p[curr];
        groups = max(groups, count);
    }
    
    cout << groups + 1 << '\n';
    return 0;
}
