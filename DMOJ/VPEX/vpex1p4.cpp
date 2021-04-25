#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <const int MAXV, typename T, const int INDEXING>
struct RMQLCA {
	std::vector<std::pair<int, T>> adj[MAXV]; T dist[MAXV]; int tour[MAXV], sparse[32 - __builtin_clz(2 * MAXV)][2 * MAXV], lg[2 * MAXV], idx;
	void add(int u, int v, T w) { u -= INDEXING, v -= INDEXING; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w); }
	void dfs(int cur, int prev, int d) {
		dist[cur] = d, sparse[0][tour[cur] = idx++] = cur;
		for (auto &i : adj[cur]) {
			if (i.first != prev) {
				dfs(i.first, cur, d + i.second);
				sparse[0][idx++] = cur;
			}
		}
	}
	void process(int root, int V = MAXV) {
		idx = 0; dfs(root - INDEXING, -1, 0); lg[1] = 0; for (int i = 2; i <= idx; i++) lg[i] = lg[i >> 1] + 1;
		for (int j = 0; j < lg[idx]; j++)
			for (int i = 0; i + (1 << j) < idx; i++)
				sparse[j + 1][i] = argmin(sparse[j][i], sparse[j][i + (1 << j)]);
	}
	int query(int u, int v) { u -= INDEXING, v -= INDEXING; if (tour[u] > tour[v]) std::swap(u, v); return query_(tour[u], tour[v]); }
	T distance(int u, int v) { return dist[u - INDEXING] + dist[v - INDEXING] - 2 * dist[query(u, v)]; }
private:
    int argmin(int u, int v) { return dist[u] < dist[v] ? u : v; }
    T query_(int l, int r) { int k = lg[r - l + 1]; return argmin(sparse[k][l], sparse[k][r - (1 << k) + 1]); }
};

struct dis {
    int a, b, c, d, e;
    dis() {}
    dis(int a, int b, int c, int d, int e) : a(a), b(b), c(c), d(d), e(e) {}
};

pii qu[1000000];
dis d[1000000];
ll dp1[1000000], dp2[1000000];
RMQLCA<100000, int, 1> lca;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, D, a, b, c;
    cin >> N >> D;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        lca.add(a, b, c);
    }
    lca.process(1, N);

    for (int i = 0; i < D; i++) cin >> qu[i].first >> qu[i].second;
    for (int i = 0; i < D - 1; i++) {
        int x0 = qu[i].first, y0 = qu[i].second, x1 = qu[i + 1].first, y1 = qu[i + 1].second;
        d[i] = dis(lca.distance(x0, x1), lca.distance(x0, y1), lca.distance(y0, x1), lca.distance(y0, y1), lca.distance(x1, y1));
    }

    memset(dp1, 0x3f, sizeof(dp1)); memset(dp2, 0x3f, sizeof(dp2)); dp1[D - 1] = dp2[D - 1] = 0;
    for (int i = D - 2; i >= 0; i--) {
        dp1[i] = min(d[i].a + dp2[i + 1], d[i].b + dp1[i + 1]) + d[i].e;
        dp2[i] = min(d[i].c + dp2[i + 1], d[i].d + dp1[i + 1]) + d[i].e;
    }

    cout << min(lca.distance(1, qu[0].first) + dp2[0], lca.distance(1, qu[0].second) + dp1[0]) + lca.distance(qu[0].first, qu[0].second) << '\n';
    return 0;
}
