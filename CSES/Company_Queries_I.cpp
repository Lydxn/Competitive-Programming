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

vector<int> adj[200001];
int up[200001][18];

void dfs(int cur, int prev) {
	up[cur][0] = prev;
	for (int i = 1; i <= 17; i++) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for (int i : adj[cur]) dfs(i, cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, q, e, x, k;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) cin >> e, adj[e].push_back(i);
	dfs(1, 0);
	while (q--) {
		cin >> x >> k;
		int ans = x;
		for (int i = 0; i <= 17; i++)
			if (k & (1 << i)) ans = up[ans][i];
		cout << (ans == 0 ? -1 : ans) << '\n';
	}
	return 0;
}
