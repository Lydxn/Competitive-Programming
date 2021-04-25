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

vector<int> adj[100001];
ll BIT[200001];
int euler[200001], in[200001], out[200001], eidx;
int up[100001][18], dep[100001], cost[100001], N;

void dfs(int cur, int prev, int d) {
	euler[++eidx] = cur, dep[cur] = d, up[cur][0] = prev;
	for (int i = 1; i < 18; i++)
		up[cur][i] = up[up[cur][i - 1]][i - 1];

	for (auto i : adj[cur])
		if (i != prev) dfs(i, cur, d + 1);
	euler[++eidx] = cur;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 17; i >= 0; i--)
		if (diff & (1 << i)) u = up[u][i];
	if (u == v) return u;
	for (int i = 17; i >= 0; i--)
		if (up[u][i] != up[v][i]) u = up[u][i], v = up[v][i];
	return up[u][0];
}

void update(int i, int v) {
	for (; i <= 2 * N; i += i & -i) BIT[i] += v;
}

ll query(int i) {
	ll res = 0;
	for (; i; i -= i & -i) res += BIT[i];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, A, B, X, Y; char T;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		adj[A].push_back(B), adj[B].push_back(A);
	}

	dfs(1, 0, 0);
	memset(in, INF, sizeof(in));
	for (int i = 1; i <= eidx; i++)
		in[euler[i]] = min(in[euler[i]], i), out[euler[i]] = i;

	cin >> M;
	while (M--) {
		cin >> T >> X >> Y;
		if (T == 'T') {
			int v = Y - cost[X];
			update(in[X], v), update(out[X], -v);
			cost[X] = Y;
		} else {
			int XY = lca(X, Y);
			cout << query(in[X]) + query(in[Y]) - 2 * query(in[XY]) + cost[XY] - cost[X] - cost[Y] << '\n';
		}
	}
	return 0;
}
