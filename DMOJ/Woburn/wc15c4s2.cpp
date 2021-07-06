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

vector<int> adj[500001], radj[500001], ord;
bool vis[500001];
int comp[500001], ans[500001];

void dfs(int cur) {
	if (vis[cur]) return;
	vis[cur] = true;
	for (int i : adj[cur]) dfs(i);
	ord.push_back(cur);
}

void dfs2(int cur, int rep) {
	if (vis[cur]) return;
	vis[cur] = true, comp[cur] = rep;
	for (int i : radj[cur]) dfs2(i, rep);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, C;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> C;
		adj[i].push_back(C), radj[C].push_back(i);
	}
	for (int i = 1; i <= N; i++) dfs(i);
	memset(vis, false, sizeof(vis));
	for (int i = N - 1; i >= 0; i--) dfs2(ord[i], ord[i]);
	for (int i = 1; i <= N; i++) ++ans[comp[i]];
	for (int i = 0; i < N; i++)
		for (int j : radj[ord[i]])
			if (comp[ord[i]] != comp[j])
				ans[comp[j]] += ans[comp[ord[i]]];
	for (int i = 1; i <= N; i++) cout << ans[comp[i]] << '\n';
	return 0;
}
