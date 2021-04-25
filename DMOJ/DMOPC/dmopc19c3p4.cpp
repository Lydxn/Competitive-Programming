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

vector<int> adj[300001];
bool C[300001];
int dp[300001], ans;

void dfs(int cur, int prev, bool c) {
	int res = 1;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur, c);
		res = 1LL * res * (dp[i] + 1) % MOD;
		if (c != C[cur]) ans = (ans - dp[i] + MOD) % MOD;
	}
	dp[cur] = res - (c != C[cur]), ans = (ans + dp[cur]) % MOD;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, u, v; char ch;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> ch, C[i] = ch == 'B';
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(1, 0, false);
	memset(dp, 0, sizeof(dp));
	dfs(1, 0, true);
	cout << ans << '\n';
	return 0;
}
