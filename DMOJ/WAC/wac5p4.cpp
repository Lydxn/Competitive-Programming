#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> adj[200001];
int dep[200001], up[200001][19];

void dfs(int cur, int prev, int d) {
	dep[cur] = d, up[cur][0] = prev;
	for (int i = 1; i <= 18; i++)
		up[cur][i] = up[up[cur][i - 1]][i - 1];

	for (int i : adj[cur])
		if (i != prev)
			dfs(i, cur, d + 1);
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 18; i >= 0; i--)
		if (diff & (1 << i))
			u = up[u][i];

	if (u == v) return u;

	for (int i = 18; i >= 0; i--)
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y, a, b, c, d;
	cin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		adj[x].push_back(y), adj[y].push_back(x);
	}

	dfs(1, 1, 0);

	while (Q--) {
		cin >> a >> b >> c >> d;

		int lca0 = lca(a, c);
		int md = dep[a] + dep[c] - 2 * dep[lca0], m = dep[a] < dep[c] ? c : a;

		if (md & 1) {
			cout << "-1\n";
			continue;
		}

		md >>= 1;
		for (int i = 18; i >= 0; i--)
			if (md & (1 << i))
				m = up[m][i];

		int lca1 = lca(a, m), lca2 = lca(b, m), lca3 = lca(c, m), lca4 = lca(d, m), lca5 = lca(a, b), lca6 = lca(c, d);
		bool atob = m == lca5 || (lca1 == m && lca2 == lca5) || (lca2 == m && lca1 == lca5);
		bool ctod = m == lca6 || (lca3 == m && lca4 == lca6) || (lca4 == m && lca3 == lca6);
		cout << (m != b && m != d && atob && ctod ? md : -1) << '\n';
	}
	return 0;
}
