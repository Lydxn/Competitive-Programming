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

vector<int> adj[100001], ans;
bool vis[100001];

void dfs(int cur, int prev) {
	ans.push_back(cur);
	if (vis[cur]) {
		int st = 0;
		for (int i = 0; i < int(ans.size()); i++)
			if (ans[i] == ans.back()) { st = i; break; }
		cout << int(ans.size()) - st << '\n';
		for (int i = st; i < int(ans.size()); i++) cout << ans[i] << ' ';
		cout << '\n';
		exit(0);
	}
	vis[cur] = true;
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur);
	ans.pop_back();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i]) dfs(i, -1);
	cout << "IMPOSSIBLE\n";
	return 0;
}
