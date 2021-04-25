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

vector<int> adj[1001];
int in[1001], low[1001], deg[1001], timer;
bool vis[1001];

void dfs(int cur, int prev) {
	vis[cur] = true, in[cur] = low[cur] = timer++;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		if (vis[i]) low[cur] = min(low[cur], in[i]);
		else {
			dfs(i, cur);
			low[cur] = min(low[cur], low[i]);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, r, v, w;
	cin >> n >> r;
	while (r--) {
		cin >> v >> w;
		adj[v].push_back(w), adj[w].push_back(v);
	}

	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		for (int j : adj[i])
			if (low[i] != low[j]) ++deg[low[i]];

	int ans = 0;
	for (int i = 1; i <= n; i++) ans += deg[i] == 1;
	cout << (ans + 1) / 2 << '\n';
	return 0;
}
