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

int p[1001], par[1001], mp[1001];
bool vis[1001];
vector<int> adj[1001], adj2[1001], order, vp, vn, tmp;
vector<pii> ans;

void dfs(int cur) {
	vis[cur] = true;
	for (int i : adj[cur])
		if (!vis[i]) dfs(i), adj2[cur].push_back(i), adj2[i].push_back(cur), par[i] = cur;
	order.push_back(cur), vp.push_back(p[cur]);
}

void dfs2(int cur, int prev) {
	for (int i : adj2[cur])
		if (i != prev) dfs2(i, cur), par[i] = cur;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> p[i];
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		if (vis[i]) continue;
		order.clear(), vp.clear(), dfs(i), vn = order;
		sort(vp.begin(), vp.end()), sort(vn.begin(), vn.end());
		for (int j = 0; j < int(vn.size()); j++) mp[vn[j]] = vp[j];
		for (int j : order) {
			dfs2(j, par[j] = -1);
			
			int s = -1;
			for (int k = 1; k <= N; k++)
				if (p[k] == mp[j]) s = k;
			for (; par[s] != -1; s = par[s])
				ans.emplace_back(s, par[s]), swap(p[s], p[par[s]]);
		}
	}

	cout << ans.size() << '\n';
	for (int i = 1; i <= N; i++) cout << p[i] << ' ';
	cout << '\n';
	for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
	return 0;
}
