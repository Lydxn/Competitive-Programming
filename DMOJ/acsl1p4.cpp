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

vector<int> adj[21], radj[21], order;
bool vis[21];

void dfs1(int cur) {
	vis[cur] = true;
	for (int i : adj[cur])
		if (!vis[i]) dfs1(i);
	order.push_back(cur);
}

void dfs2(int cur, int &sz) {
	vis[cur] = true, ++sz;
	for (int i : radj[cur])
		if (!vis[i]) dfs2(i, sz);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, a, b, sa, sb;
	cin >> N >> K;
	while (K--) {
		cin >> a >> b >> sa >> sb;
		if (sa < sb) swap(a, b);
		adj[a].push_back(b), radj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
		if (!vis[i]) dfs1(i);

	memset(vis, false, sizeof(vis));
	reverse(order.begin(), order.end());

	int ans = 0, tmp;
	for (int i : order)
		if (!vis[i]) {
			dfs2(i, tmp = 0);
			if (tmp > 1) ans += tmp;
		}
	cout << ans << '\n';
	return 0;
}
