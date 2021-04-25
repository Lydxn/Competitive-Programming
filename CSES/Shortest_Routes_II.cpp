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

ll adj[501][501];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, q, a, b, c;
	cin >> n >> m >> q;
	memset(adj, INFL, sizeof(adj));
	for (int i = 1; i <= n; i++) adj[i][i] = 0;
	while (m--) {
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], (ll) c);
		adj[b][a] = min(adj[b][a], (ll) c);
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	while (q--) {
		cin >> a >> b;
		cout << (adj[a][b] == INFL ? -1 : adj[a][b]) << '\n';
	}
	return 0;
}
