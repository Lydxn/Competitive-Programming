#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

struct edge {
    int v, i; ll w;
    edge(int v, int i, ll w) : v(v), i(i), w(w) {}
};

vector<edge> adj[100001];
priority_queue<pli, vector<pli>, greater<pli>> pq;
ll dist[100001], C; int N, A, B;

bool solve(int M) {
    pq = {}; pq.emplace(0, A);
    fill(dist, dist + N + 1, LLONG_MAX);
    dist[A] = 0;
    
    while (!pq.empty()) {
        ll cw = pq.top().first; int cv = pq.top().second; pq.pop();
        if (cw > dist[cv]) continue;
        
        for (auto i : adj[cv]) {
            if (i.i > M) break;
            int nw = i.w + dist[cv];
            if (nw < dist[i.v]) {
                dist[i.v] = nw;
                pq.emplace(nw, i.v);
            }
        }
    }
    return dist[B] <= C;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int M, a, b, c, l, r, m;
    cin >> N >> M;
    
    for (int i = 1; i <= M; i++) {
        cin >> a >> b >> c;
        adj[a].emplace_back(b, i, c); adj[b].emplace_back(a, i, c);
    }
    
    cin >> A >> B >> C;
    l = 0, r = M;
    while (l <= r) {
        m = (l + r) >> 1;
        if (solve(m)) r = m - 1;
        else l = m + 1;
    }
    
    cout << (l <= M ? l : -1) << '\n';
    return 0;
}
