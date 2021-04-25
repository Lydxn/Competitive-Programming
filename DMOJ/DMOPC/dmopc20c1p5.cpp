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

int c[500001], dep[500001], up[500001][19];
int euler[1000001], in[1000001], out[1000001], eidx;
vector<int> vals[500001];

void dfs(int cur, int prev, int d) {
	up[cur][0] = prev, dep[cur] = d;
	for (int i = 1; i <= 18; i++)
		up[cur][i] = up[up[cur][i - 1]][i - 1];

	euler[++eidx] = cur;
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur, d + 1);
	euler[++eidx] = cur;
}

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 18; i >= 0; i--)
		if (diff & (1 << i)) u = up[u][i];
	if (u == v) return u;
	for (int i = 18; i >= 0; i--)
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, M, a, b, op;
	cin >> N >> K >> M;
	for (int i = 1; i <= N; i++) cin >> c[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	dfs(1, 1, 0); memset(in, INF, sizeof(in));
	for (int i = 1; i <= eidx; i++)
		in[euler[i]] = min(in[euler[i]], i), out[euler[i]] = i;
	for (int i = 1; i <= N; i++)
		 vals[c[i]].push_back(i);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j < int(vals[i].size()); j++)


	while (M--) {
		cin >> op;
		if (op == 1) {
			cin >> a >> b;
		} else {
			cin >> a;
		}
	}
	return 0;
}
