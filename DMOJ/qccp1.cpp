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

unordered_map<char, int> col = {{'r', 0}, {'o', 1}, {'y', 2}, {'g', 3}, {'b', 4}, {'i', 5}, {'v', 6}};
vector<pii> adj[100001];
int dp[100001][128], m;

int dfs(int cur, int msk) {
	if (msk == m || adj[cur].empty()) return 0;
	if (dp[cur][msk] != -1) return dp[cur][msk];
	bool res = false;
	for (auto i : adj[cur]) res |= !dfs(i.first, msk | (1 << i.second));
	return dp[cur][msk] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, u, v; char c;
	cin >> N >> M;
	while (M--) {
		cin >> u >> v >> c;
		adj[u].emplace_back(v, col[c]), m |= 1 << col[c];
	}
	memset(dp, -1, sizeof(dp));
	cout << (dfs(1, 0) ? "piddddgy" : "deruikong") << '\n';
	return 0;
}
