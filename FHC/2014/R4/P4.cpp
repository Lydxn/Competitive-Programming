// pretty implementation heavy, but doesn't seem TOO difficult
// find bridges + compress nodes + lca + fenwick tree

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

vector<int> adj[100001], cadj[100001];
bool vis[100001];
int BIT[200001], up[100001][17], dep[100001], bye[100001], C;
int comp[100001], comp2[100001], in[100001], out[100001], low[100001], timer;
unordered_set<ll> b;

void dfs1(int cur, int prev) {
	vis[cur] = true, in[cur] = low[cur] = ++timer;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		if (vis[i]) low[cur] = min(low[cur], in[i]);
		else {
			dfs1(i, cur), low[cur] = min(low[cur], low[i]);
			if (low[i] > in[cur]) b.insert((ll) min(cur, i) << 20 | max(cur, i));
		}
	}
}

void dfs2(int cur, int c) {
	comp[cur] = c;
	for (int i : adj[cur])
		if (!comp[i] && !b.count((ll) min(cur, i) << 20 | max(cur, i)))
			dfs2(i, c);
}

void dfs3(int cur, int prev, int d, int c) {
	vis[cur] = true;
	in[cur] = ++timer, dep[cur] = d, up[cur][0] = prev, comp2[cur] = c;
	for (int i = 1; i <= 16; i++)
		up[cur][i] = up[up[cur][i - 1]][i - 1];
	for (int i : cadj[cur])
		if (i != prev && !vis[i]) dfs3(i, cur, d + 1, c);
	out[cur] = ++timer;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 16; i >= 0; i--)
		if (diff & (1 << i)) u = up[u][i];
	if (u == v) return u;
	for (int i = 16; i >= 0; i--)
		if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}

void update(int i, int x) {
	for (; i <= 2 * C; i += i & -i) BIT[i] += x;
}

int query(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += BIT[i];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, M, D, A, B, X, Y, O, Z; char E;
	cin >> T;
	for (int _ = 1; _ <= T; _++) {
		cin >> N >> M >> D;
		for (int i = 1; i <= N; i++) adj[i].clear(), cadj[i].clear();

		while (M--) {
			cin >> A >> B;
			adj[A].push_back(B), adj[B].push_back(A);
		}

		memset(vis, false, sizeof(vis)), timer = 0;
		for (int i = 1; i <= N; i++)
			if (!vis[i]) dfs1(i, -1);

		memset(comp, 0, sizeof(comp));
		for (int i = 1; i <= N; i++)
			if (!comp[i]) dfs2(i, ++C);

		for (int i = 1; i <= N; i++)
			for (int j : adj[i])
				if (comp[i] != comp[j])
					cadj[comp[i]].push_back(comp[j]);

		memset(vis, false, sizeof(vis)), timer = 0;
		for (int i = 1, c = 0; i <= C; i++)
			if (!vis[i]) dfs3(i, -1, 0, ++c);

		memset(bye, 0, sizeof(bye)), memset(BIT, 0, sizeof(BIT));
		ll ans = 0;
		while (D--) {
			cin >> E;
			if (E == 'T') {
				cin >> X >> Y >> O, X = comp[X], Y = comp[Y];
				if (comp2[X] != comp2[Y]) continue;
				int XY = lca(X, Y);
				update(in[X], O), update(in[XY], -O);
				update(in[Y], O); if (up[XY][0] != -1) update(in[up[XY][0]], -O);
			} else {
				cin >> Z;
				int q = query(out[comp[Z]]) - query(in[comp[Z]] - 1);
				ans += q - bye[Z];
				bye[Z] = q;
			}
		}
		cout << "Case #" << _ << ": " << ans % MOD << '\n';
	}
	return 0;
}
