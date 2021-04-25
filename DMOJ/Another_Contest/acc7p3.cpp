#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

template <const int MAXV, typename T, const int INDEXING>
struct Kruskal {
	struct Edge { int u, v; T w; bool operator < (Edge &e) { return w < e.w; } };
	std::vector<Edge> adj, mst; int par[MAXV + INDEXING], sz[MAXV + INDEXING];
	void add(int u, int v, T w) { adj.push_back({u, v, w}); }
	T min_path(int V = MAXV) {
		std::sort(adj.begin(), adj.end()); for (int i = 0; i < V + INDEXING; i++) par[i] = i, sz[i] = 1;
		T ans = 0; int sz = 0;
		for (auto &i : adj) {
			if (sz > V) break;
			if (join(i.u, i.v)) mst.push_back(i), ans += i.w, ++sz;
		}
		return ans;
	}
	std::vector<Edge> get_path() { return mst; }
	void clear() { adj.clear(); mst.clear(); }
private:
	int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
	bool join(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (sz[u] < sz[v]) std::swap(u, v);
		par[v] = u, sz[u] += sz[v];
		return true;
	}
};

struct edge {
	int a, b, w;
};

Kruskal<100000, ll, 1> mst;
vector<int> adj[100001];
bool vis[100001];
int N, f[100001], comp[100001];

void dfs(int cur, int rep) {
	if (vis[cur]) return;
	vis[cur] = true, comp[cur] = rep;
	for (int i : adj[cur]) dfs(i, rep);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, x, y;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> f[i], assert(f[i - 1] < f[i]);
	while (M--) {
		cin >> x >> y;
		adj[x].push_back(y), adj[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		dfs(i, i);
	}
	
	for (int i = 1; i <= N; i++) {
		if (i != 1 && comp[i] != comp[i - 1]) mst.add(comp[i], comp[i - 1], f[i] - f[i - 1]);
		if (i != N && comp[i] != comp[i + 1]) mst.add(comp[i], comp[i + 1], f[i + 1] - f[i]);
	}

	cout << mst.min_path(N) << '\n';
	return 0;
}
