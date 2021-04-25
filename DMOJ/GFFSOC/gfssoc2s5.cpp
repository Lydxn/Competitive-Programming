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

int N, V[500001], TV[500001], comp[500001], dp1[500001][2], dp2[500001][2];
vector<int> adj[500001], radj[500001], adj2[500001], order;
bool vis[500001];

void dfs1(int cur) {
	vis[cur] = true;
	for (int i : adj[cur])
		if (!vis[i]) dfs1(i);
	order.push_back(cur);
}

void dfs2(int cur, int rep) {
	vis[cur] = true, comp[cur] = rep;
	for (int i : radj[cur])
		if (!vis[i]) dfs2(i, rep);
}

pii dfs3(int cur, int take) {
	if (cur == comp[N]) return make_pair(take ? TV[cur] : 0, 1);
	if (dp1[cur][take] != -1) return make_pair(dp1[cur][take], dp2[cur][take]);

	int mx = 0, cnt = 1;
	for (int i : adj2[cur]) {
		pii nxt_take = dfs3(i, true), nxt_notake = dfs3(i, false);
		nxt_notake.first += TV[cur];

		if (mx < nxt_take.first) mx = nxt_take.first, cnt = nxt_take.second;
		else if (mx == nxt_take.first) cnt = (cnt + nxt_take.second) % MOD;

		if (take) {
			if (mx < nxt_notake.first) mx = nxt_notake.first, cnt = nxt_notake.second;
			else if (mx == nxt_notake.first) cnt = (cnt + nxt_notake.second) % MOD;
		}
	}
	return make_pair(dp1[cur][take] = mx, dp2[cur][take] = cnt);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> V[i];
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b), radj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		if (!vis[i]) dfs1(i);

	memset(vis, false, sizeof(vis));
	reverse(order.begin(), order.end());
	for (int i : order)
		if (!vis[i]) dfs2(i, i);

	for (int i = 1; i <= N; i++)
		for (int j : adj[i])
			if (comp[i] != comp[j])
				adj2[comp[i]].push_back(comp[j]);

	for (int i = 1; i <= N; i++)
		TV[comp[i]] += V[i];

	memset(dp1, -1, sizeof(dp1));
	pii ans = dfs3(comp[1], true);
	cout << ans.first << ' ' << ans.second << '\n';
	return 0;
}
