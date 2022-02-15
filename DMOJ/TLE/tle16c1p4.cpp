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

int adj[101][101], m[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, u, v, d;
	cin >> N >> M >> K;
	memset(adj, INF, sizeof(adj));
	for (int i = 1; i <= N; i++) cin >> m[i];
	while (M--) cin >> u >> v >> d, adj[u][v] = adj[v][u] = d;

	for (int i = 1; i <= N; i++) adj[i][i] = 0;
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < i; j++) {
			for (int k = 1; k < j; k++) {
				int cur = 0;
				for (int l = 1; l <= N; l++)
					if (adj[i][l] <= K || adj[j][l] <= K || adj[k][l] <= K)
						cur += m[l];
				ans = max(ans, cur);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
