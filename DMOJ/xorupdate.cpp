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

int v[200001], q[200001], up[200001][18], h[200001];
vector<int> adj[200001], order;

void dfs(int cur, int prev) {
	h[cur] = h[prev] + 1, up[cur][0] = prev;
	for (int i = 1; i <= 17; i++)
		up[cur][i] = up[up[cur][i - 1]][i - 1];
	for (auto i : adj[cur])
		if (i != prev) dfs(i, cur);
	order.push_back(cur);
}

int lca(int u, int v) {
	if (h[u] < h[v]) swap(u, v);
	int diff = h[u] - h[v];
	for (int i = 0; i <= 17; i++)
		if (diff & (1 << i)) u = up[u][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y, a, b, c;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> v[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		adj[x].push_back(y), adj[y].push_back(x);
	}

	dfs(1, 0);
	while (Q--) {
		cin >> a >> b >> c;
		int ab = lca(a, b);
		q[a] ^= c, q[(h[a] + h[b]) % 2 ? up[b][0] : b] ^= c;
		if ((h[a] - h[ab]) % 2 == 0) v[ab] ^= c;
	}

	for (int i : order) q[up[i][1]] ^= q[i];

	for (int i = 1; i <= N; i++)
		cout << (q[i] ^ v[i]) << ' ';
	cout << '\n';
	return 0;
}
