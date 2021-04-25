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

int f[1000001], rep[1000001], ord[1000000], oidx;
ll sf[1000001], ans[1000001];
vector<int> adj[1000001], radj[1000001], cadj[1000001];
bool vis[1000001];

void dfs1(int cur) {
	vis[cur] = true;
	for (int i : adj[cur])
		if (!vis[i]) dfs1(i);
	ord[oidx++] = cur;
}

void dfs2(int cur, int s) {
	vis[cur] = true, rep[cur] = s;
	for (int i : radj[cur])
		if (!vis[i]) dfs2(i, s);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, S, E, a, b;
	cin >> N >> M >> S >> E;
	for (int i = 1; i <= N; i++) cin >> f[i];
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b), radj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		if (!vis[i]) dfs1(i);

	memset(vis, false, sizeof(vis));
	while (oidx--) {
		int v = ord[oidx];
		if (!vis[v]) dfs2(v, v);
	}

	for (int i = 1; i <= N; i++) {
		sf[rep[i]] += f[i];
		for (int j : adj[i])
			if (rep[i] != rep[j]) cadj[rep[i]].push_back(rep[j]);
	}

	ans[rep[S]] = sf[rep[S]];
	for (int i = rep[S]; i <= rep[E]; i++) {
		for (int j : cadj[rep[i]])
			ans[j] = max(ans[j], ans[rep[i]] + sf[j]);
	}
	cout << ans[rep[E]] << '\n';
	return 0;
}
