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

vector<int> adj[5001];
int N, S, q[5000], par[5001], bidx, fidx;
bool vis[5001];

void bfs(int x) {
	q[fidx++] = x, vis[x] = true, par[x] = x;
	while (bidx < N) {
		int v = q[bidx++];
		for (int i : adj[v])
			if (!vis[i]) vis[i] = true, par[i] = v, q[fidx++] = i;
	}
}

void dfs(int cur, int prev, int d) {
	vis[cur] = true;
	if (d == 0) return;

	for (int i : adj[cur])
		if (i != prev)
			dfs(i, cur, d - 1);
}

bool f(int D) {
	memset(vis, false, sizeof(vis));
	for (int i = bidx - 1, cnt = 0; i >= 0; i--) {
		if (!vis[q[i]]) {
			if (++cnt > S) return false;

			int s = q[i];
			for (int j = 0; j < D; j++) s = par[s];
			dfs(s, -1, D);
		}
	}
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int u, v;
	cin >> N >> S;
	for (int i = 0; i < N - 1; i++) cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);

	bfs(1);
	int l = 0, r = N / 2, m;
	while (l < r) {
		m = (l + r) >> 1;
		if (f(m)) r = m;
		else l = m + 1;
	}

	cout << l << '\n';
	return 0;
}
