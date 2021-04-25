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
const int MOD = 1e9;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

vector<int> adj[10001], order;
bool good[10001], vis[10001], stk[10001];
int dp[10001];

int dfs1(int cur) {
	if (vis[cur]) return good[cur];
	vis[cur] = true;
	if (cur == 2) good[cur] = true;
	for (int i : adj[cur])
		good[cur] |= dfs1(i);
	return good[cur];
}

void dfs2(int cur) {
	vis[cur] = stk[cur] = true;
	for (int i : adj[cur]) {
		if (!good[i]) continue;
		if (!vis[i]) dfs2(i);
		else if (stk[i]) { cout << "inf\n"; exit(0); }
	}
	stk[cur] = false, order.push_back(cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B;
	cin >> N >> M;
	while (M--) {
		cin >> A >> B;
		adj[A].push_back(B);
	}

	dfs1(1); memset(vis, false, sizeof(vis)); dfs2(1);
	reverse(order.begin(), order.end());
	dp[1] = 1;
	bool pad = false;
	for (int i : order) {
		for (int j : adj[i]) {
			dp[j] += dp[i];
			if (dp[j] >= MOD) pad = true, dp[j] -= MOD;
		}
	}

	if (pad) cout << setfill('0') << setw(9) << dp[2] << '\n';
	else cout << dp[2] << '\n';
	return 0;
}
