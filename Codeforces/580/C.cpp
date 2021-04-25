#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100001];
bool cat[100001], visited[100001];
int res = 0;

void dfs(int curr, int consec, int m)
{
    visited[curr] = true;
    if (cat[curr]) ++consec;
    else           consec = 0;
    
    if (consec > m) return;

    bool is_leaf = true;
    for (const auto& v : adj[curr])
    {
        if (!visited[v])
        {
            dfs(v, consec, m);
            is_leaf = false;
        }
    }
    
    if (is_leaf) ++res;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, x, y;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) cin >> cat[i];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1, 0, m);
    cout << res << '\n';
    return 0;
}
