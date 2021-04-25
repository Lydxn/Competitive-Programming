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

vector<int> adj[100001], radj[100001], order;
int comp[100001];
bool vis[100001], in[100001];

void dfs1(int cur) {
	vis[cur] = true;
	for (int i : adj[cur])
		if (!vis[i])
			dfs1(i);
	order.push_back(cur);
}

void dfs2(int cur, int rep) {
	vis[cur] = true, comp[cur] = rep;
	for (int i : radj[cur])
		if (!vis[i])
			dfs2(i, rep);
}

void solve() {
	int N;
	cin >> N;

	order.clear();
	for (int i = 1; i <= N; i++) adj[i].clear(), radj[i].clear();
	for (int i = 1, b; i <= N; i++) cin >> b, adj[b].push_back(i), radj[i].push_back(b);

	memset(vis, false, sizeof(vis));
	for (int i = 1; i <= N; i++)
		if (!vis[i]) dfs1(i);

	memset(vis, false, sizeof(vis));
	reverse(order.begin(), order.end());
	for (int i : order)
		if (!vis[i]) dfs2(i, i);

	memset(in, false, sizeof(in));
	for (int i = 1; i <= N; i++)
		for (int j : adj[i])
			if (comp[i] != comp[j]) in[comp[j]] = true;

	int cnt = 0;
	for (int i = 1; i <= N; i++)
		if (i == comp[i])
			cnt += !in[comp[i]];
	cout << cnt << ' ';
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 2; _++) solve();
	return 0;
}
