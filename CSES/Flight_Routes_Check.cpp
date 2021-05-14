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

vector<int> adj[100001], radj[100001];
bool vis[100001];

void dfs(int cur, vector<int> a[100001]) {
	if (vis[cur]) return;
	vis[cur] = true;
	for (int i : a[cur]) dfs(i, a);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b), radj[b].push_back(a);
	}
	dfs(1, adj);
	for (int i = 2; i <= n; i++)
		if (!vis[i]) { cout << "NO\n" << 1 << ' ' << i << '\n'; return 0; }
	memset(vis, false, sizeof(vis));
	dfs(1, radj);
	for (int i = 2; i <= n; i++)
		if (!vis[i]) { cout << "NO\n" << i << ' ' << 1 << '\n'; return 0; }
	cout << "YES\n";
	return 0;
}
