#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct dsu {
    static const int MAXN = 50000;
    int par[MAXN + 1], sz[MAXN + 1];
    dsu() { for (int i = 1; i <= MAXN; i++) par[i] = i, sz[i] = 1; }
    int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
    bool join(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return false;
        if (sz[u] < sz[v]) swap(u, v);
        par[v] = u, sz[u] += sz[v];
        return true;
    }
    bool connected(int u, int v) { return find(u) == find(v); }
};

dsu d[128];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q, u, v, k, a, b;
    cin >> N >> M >> Q;

    while (M--) {
        cin >> u >> v >> k;
        for (int i = 0; i < 128; i++) {
            if (!(k & ~i)) {
                d[i].join(u, v);
            }
        }
    }

    while (Q--) {
        cin >> a >> b; int ans = 127;
        for (int i = 7; i >= 0; i--) {
            if (d[ans & ~(1 << i)].connected(a, b)) ans &= ~(1 << i);
        }
        cout << ans << '\n';
    }
    return 0;
}
