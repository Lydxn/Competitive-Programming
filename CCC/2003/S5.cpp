#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> adj[10001];
queue<pair<int, int>> q;
int dist[10001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int c, r, d, dest, x, y, w, ans = INT_MAX;
    cin >> c >> r >> d;
    
    while (r--) {
        cin >> x >> y >> w;
        adj[x].emplace_back(y, w); adj[y].emplace_back(x, w);
    }
    
    q.emplace(1, INT_MAX);
    while (!q.empty()) {
        int n = q.front().first, d = q.front().second;
        q.pop();
        
        dist[n] = max(dist[n], d);
        for (auto i : adj[n]) {
            int m = min(d, i.second);
            if (dist[i.first] < m) q.emplace(i.first, m);
        }
    }
    
    while (d--) {
        cin >> dest;
        ans = min(ans, dist[dest]);
    }
    
    cout << ans << '\n';
    return 0;
}
