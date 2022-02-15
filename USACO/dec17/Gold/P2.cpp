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

vector<int> adj[100001];
int col[100001]; ll dp[100001][3];

void dfs(int cur, int prev) {
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur);
	for (int c = 0; c < 3; c++) {
		if (col[cur] != -1 && col[cur] != c) continue;
		dp[cur][c] = 1;
		for (int i : adj[cur]) {
			if (i == prev) continue;
			int cnt = 0;
			for (int d = 0; d < 3; d++)
				if (c != d) cnt = (cnt + dp[i][d]) % MOD;
			dp[cur][c] = dp[cur][c] * cnt % MOD;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);

	int N, K, x, y, b, c;
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		adj[x].push_back(y), adj[y].push_back(x);
	}
	memset(col, -1, sizeof(col));
	while (K--) cin >> b >> c, col[b] = c - 1;
	dfs(1, -1);
	cout << (dp[1][0] + dp[1][1] + dp[1][2]) % MOD << '\n';
	return 0;
}
