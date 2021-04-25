#include <bits/stdc++.h>

using namespace std;

bool seg[101];
vector<int> ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, m, l, r;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> l >> r;
        for (int i = l; i <= r; i++) seg[i] = true;
    }
    
    for (int i = 1; i <= m; i++) if (!seg[i]) ans.push_back(i);
    
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    return 0;
}
