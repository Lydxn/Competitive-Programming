#include <bits/stdc++.h>

using namespace std;

struct node {
    int v, w;
    node(int v, int w) : v(v), w(w) {}
    bool operator < (const node& p) const { return w > p.w; }
};

const int INF = 0x3f3f3f3f;
priority_queue<node> pq;
vector<int> adj[30001];
int dist[30001];
bitset<30001 * 30001> vis;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, B, P, d1, d2;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> B >> P;
        adj[B].push_back(P);
        
        if (i == 0) d1 = B;
        if (i == 1) d2 = B;
    }
    
    memset(dist, INF, sizeof(dist));
    dist[d1] = 0; pq.emplace(d1, 0);
    
    while (!pq.empty()) {
        int cv = pq.top().v, cw = pq.top().w; pq.pop();
        if (cw > dist[cv]) continue;
        
        for (const auto& p : adj[cv]) {
            for (int i = cv + p, j = 1; i < N; i += p, j++) {
                if (vis[i * N + p]) break;
                vis[i * N + p] = true;
                
                if (dist[cv] + j < dist[i]) {
                    dist[i] = dist[cv] + j;
                    pq.emplace(i, dist[i]);
                }
            }
            
            for (int i = cv - p, j = 1; i >= 0; i -= p, j++) {
                if (vis[i * N + p]) break;
                vis[i * N + p] = true;
                
                if (dist[cv] + j < dist[i]) {
                    dist[i] = dist[cv] + j;
                    pq.emplace(i, dist[i]);
                }
            }
        }
    }
    
    cout << (dist[d2] == INF ? -1 : dist[d2]) << '\n';
    return 0;
}
