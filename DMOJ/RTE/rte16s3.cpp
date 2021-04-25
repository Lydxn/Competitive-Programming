#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <const int MAXV, const int MAXQ, typename T, const int INDEXING>
struct TarjanLCA {
	std::vector<std::pair<int, T>> adj[MAXV]; std::vector<std::pair<int, int>> query[MAXV];
	std::pair<int, T> ans[MAXQ]; T dist[MAXV]; bool vis[MAXV]; int anc[MAXV], par[MAXV], sz[MAXV], idx = 0;
	void add(int u, int v, T w) { u -= INDEXING, v -= INDEXING; adj[u].emplace_back(v, w); adj[v].emplace_back(u, w); }
	void add_query(int u, int v) { u -= INDEXING, v -= INDEXING; query[u].emplace_back(v, idx); query[v].emplace_back(u, idx++); }
	void dfs(int cur, int prev, T d) {
		dist[cur] = d, anc[cur] = cur, vis[cur] = true;
		for (auto &i : adj[cur]) if (i.first != prev) { dfs(i.first, cur, d + i.second); join(cur, i.first); anc[find(cur)] = cur; }
		for (auto &i : query[cur]) if (vis[i.first]) { int a = anc[find(i.first)]; ans[i.second] = {a, dist[cur] + dist[i.first] - 2 * dist[a]}; }
	}
	void process(int root, int V = MAXV) { std::fill(vis, vis + V, false); for (int i = 0; i < V; i++) par[i] = i, sz[i] = 1; dfs(root -= INDEXING, -1, 0); }
private:
	int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
	bool join(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (sz[u] < sz[v]) std::swap(u, v);
		par[v] = u, sz[u] += sz[v];
		return true;
	}
};

TarjanLCA<6000, 1000000, ll, 0> lca;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b, u, v, w;
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> a >> b >> w, lca.add(a, b, w);
	cin >> Q;
	for (int i = 0; i < Q; i++) cin >> u >> v, lca.add_query(u, v);

	lca.process(0);
	for (int i = 0; i < Q; i++) cout << lca.ans[i].second << '\n';
	return 0;
}
