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

vector<int> adj[300];
int w[300], b[300], dp[300][601];

void dfs1(int v) { for (int i : adj[v]) dfs1(i), w[v] += w[i], b[v] += b[i]; }
int dfs2(int v, int d) {
	if (d < -300 || d > 300) return INF;
	int &p = dp[v][d + 300];
	if (p != -1) return p;
	if (d == 0) return p = 0;
	if (w[v] - b[v] == d) return p = 1;
	if (adj[v].size() == 0) return p = INF;
	if (adj[v].size() == 1) return p = dfs2(adj[v][0], d);
	
	int res = INF;
	for (int i = -300; i <= 300; i++)
		res = min(res, dfs2(adj[v][0], i) + dfs2(adj[v][1], d - i));
	return p = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, D, id, c, C, x;
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> id >> c >> C, ++(c ? w : b)[id];
		while (C--) cin >> x, adj[id].push_back(x);
	}

	memset(dp, -1, sizeof(dp)); dfs1(0);
	int ans = dfs2(0, w[0] - b[0] - D);
	cout << (ans == INF ? -1 : ans) << '\n';
	return 0;
}
