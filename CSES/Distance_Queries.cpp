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

vector<int> adj[200001];
int up[200001][18], dist[200001];

void dfs(int cur, int prev, int d) {
	up[cur][0] = prev, dist[cur] = d;
	for (int i = 1; i <= 17; i++) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur, d + 1);
}

int lca(int a, int b) {
	if (dist[a] < dist[b]) swap(a, b);
	int diff = dist[a] - dist[b];
	for (int i = 0; i <= 17; i++)
		if (diff & (1 << i)) a = up[a][i];
	if (a == b) return a;
	for (int i = 17; i >= 0; i--)
		if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
	return up[a][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, a, b;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	while (q--) {
		cin >> a >> b;
		cout << dist[a] + dist[b] - 2 * dist[lca(a, b)] << '\n';
	}
	return 0;
}
