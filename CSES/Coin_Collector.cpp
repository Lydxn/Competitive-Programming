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

vector<int> adj[100001], radj[100001], ord;
int k[100001], comp[100001];
ll nk[100001], dp[100001];
bool vis[100001];

void dfs1(int cur) {
	if (vis[cur]) return;
	vis[cur] = true;
	for (int i : adj[cur]) dfs1(i);
	ord.push_back(cur);
}

void dfs2(int cur, int c) {
	if (vis[cur]) return;
	vis[cur] = true, comp[cur] = c;
	for (int i : radj[cur]) dfs2(i, c);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> k[i];
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b), radj[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) dfs1(i);
	memset(vis, false, sizeof(vis));
	for (int i = n - 1; i >= 0; i--)
		if (!vis[ord[i]]) dfs2(ord[i], ord[i]);
	for (int i = 1; i <= n; i++) dp[comp[i]] = nk[comp[i]] += k[i];
	for (int i = n - 1; i >= 0; i--) {
		for (int j : adj[ord[i]])
			if (comp[ord[i]] != comp[j])
				dp[comp[j]] = max(dp[comp[j]], dp[comp[ord[i]]] + nk[comp[j]]);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
	cout << ans << '\n';
	return 0;
}
