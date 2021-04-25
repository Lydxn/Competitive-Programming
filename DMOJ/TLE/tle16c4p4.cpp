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

vector<pii> adj[100001];
bool vis[100001];
ll dist[100001];
int par[100001];

void dfs(int v, int p, ll d, ll &mx, int &mi) {
	par[v] = p, vis[v] = true;
	if (d > mx) mx = d, mi = v;
	for (auto i : adj[v])
		if (i.first != p)
			dist[i.first] = i.second, dfs(i.first, v, d + i.second, mx, mi);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q, a, b, l, mi, ans = 0, mx; bool extra = false;
	cin >> N >> M >> Q;
	while (M--) {
		cin >> a >> b >> l;
		adj[a].emplace_back(b, l), adj[b].emplace_back(a, l);
	}

	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		mi = i, dfs(mi, -1, 0, mx = 0, mi), dfs(mi, -1, 0, mx = 0, mi);
		if (Q == 1) ans += mx + 1;
		else {
			ll r = INFL, d = 0;
			for (int j = mi; j != -1; d += dist[j], j = par[j])
				r = min(r, max(d, mx - d));
			if (r > ans) ans = r, extra = false;
			else if (r == ans) extra = true;
		}
	}

	cout << (Q == 1 ? ans - 1 : ans + extra) << '\n';
	return 0;
}
