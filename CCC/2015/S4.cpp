#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct edge {
    int a, b, c;
    edge(int a, int b, int c) : a(a), b(b), c(c) {}
};

const int INF = 0x3f3f3f3f;
vector<edge> adj[2001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[2001][200];
bool inq[2001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int K, N, M, A, B, a, b, t, h, ans = INT_MAX;
    cin >> K >> N >> M;
    
    while (M--) {
        cin >> a >> b >> t >> h;
        adj[a].emplace_back(b, t, h);
        adj[b].emplace_back(a, t, h);
    }
    
    cin >> A >> B;
    memset(dist, INF, sizeof(dist));
    dist[A][0] = 0, inq[A] = true;
    pq.emplace(0, A);
    
    while (!pq.empty()) {
        int curr = pq.top().second; pq.pop();
        inq[curr] = false;
        
        for (auto i : adj[curr]) {
            for (int j = 0; j + i.c < K; j++) {
                int d = dist[curr][j] + i.b;
                if (d < dist[i.a][j + i.c]) {
                    dist[i.a][j + i.c] = d;
                    if (!inq[i.a]) {
                        inq[i.a] = true;
                        pq.emplace(d, i.a);
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < K; i++) ans = min(ans, dist[B][i]);
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}
