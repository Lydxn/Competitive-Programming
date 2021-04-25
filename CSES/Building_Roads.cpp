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

bool vis[100001];
vector<int> adj[100001];

void dfs(int cur) {
	vis[cur] = true;
	for (int i : adj[cur])
		if (!vis[i]) dfs(i);
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

	vector<int> ans;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) ans.push_back(i), dfs(i);

	cout << ans.size() - 1 << '\n';
	for (int i = 0; i < int(ans.size()) - 1; i++)
		cout << ans[i] << ' ' << ans[i + 1] << '\n';
	return 0;
}
