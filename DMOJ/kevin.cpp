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

vector<pii> adj[100001];
int dep[100001], up[100001][17];
ll hsh[100001], rhsh[100001], p[100001], rp[100001];

void dfs(int cur, int prev, int d) {
	dep[cur] = d, up[cur][0] = prev;
	for (int i = 1; i <= 16; i++)
		up[cur][i] = up[up[cur][i - 1]][i - 1];

	for (auto i : adj[cur]) {
		if (i.first != prev) {
			hsh[i.first] = (hsh[cur] * 31 + i.second) % MOD;
			rhsh[i.first] = (rhsh[cur] + p[d] * i.second) % MOD;
			dfs(i.first, cur, d + 1);
		}
	}
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 16; i >= 0; i--)
		if (diff & (1 << i)) u = up[u][i];

	if (u == v) return u;

	for (int i = 16; i >= 0; i--)
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

ll f0(int l, int r) { return (hsh[r] - hsh[l] * p[dep[r] - dep[l]] % MOD + MOD) % MOD; }
ll f1(int l, int r) { return (rhsh[r] - rhsh[l] + MOD) % MOD * rp[dep[l]] % MOD; }
ll cc(ll h1, ll h2, int h2len) { return (h1 * p[h2len] + h2) % MOD; }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, u, v, w, n, m;
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}

	p[0] = rp[0] = 1;
	for (int i = 1; i < N; i++)
		p[i] = p[i - 1] * 31 % MOD, rp[i] = rp[i - 1] * 129032259 % MOD;
	dfs(1, 1, 0);

	while (Q--) {
		cin >> u >> v >> n >> m;
		int uv = lca(u, v), nm = lca(n, m);
		if (dep[u] + dep[v] - 2 * dep[uv] != dep[n] + dep[m] - 2 * dep[nm]) cout << "F\n";
		else cout << "FT"[cc(f1(uv, u), f0(uv, v), dep[v] - dep[uv]) == cc(f1(nm, n), f0(nm, m), dep[m] - dep[nm])] << '\n';
	}
	return 0;
}
