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

vector<int> adj[100001], top;
bool vis[100001];
int dp[100001], p[100001];

void dfs(int cur) {
	if (vis[cur]) return;
	vis[cur] = true;
	for (int i : adj[cur]) dfs(i);
	top.push_back(cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while (m--) cin >> a >> b, adj[a].push_back(b);
	for (int i = 1; i <= n; i++) dfs(i);
	memset(p, -1, sizeof(p)); dp[1] = 1;
	for (int i = n - 1; i; i--)
		for (int j : adj[top[i]])
			if (dp[top[i]] && dp[top[i]] + 1 > dp[j])
				dp[j] = dp[top[i]] + 1, p[j] = top[i];
	if (!dp[n]) { cout << "IMPOSSIBLE\n"; return 0; }
	cout << dp[n] << '\n';
	vector<int> ans;
	for (int cur = p[n]; cur != -1; cur = p[cur]) ans.push_back(cur);
	for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
	cout << n << '\n';
	return 0;
}
