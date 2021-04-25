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
int up[200001][18], dst[200001], in[200001], out[200001], psa[400001], timer;

void dfs(int cur, int prev, int d) {
	up[cur][0] = prev, dst[cur] = d, in[cur] = ++timer;
	for (int i = 1; i <= 17; i++) up[cur][i] = up[up[cur][i - 1]][i - 1];
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur, d + 1);
	out[cur] = ++timer;
}

int lca(int a, int b) {
	if (dst[a] < dst[b]) swap(a, b);
	int diff = dst[a] - dst[b];
	for (int i = 0; i <= 17; i++)
		if (diff & (1 << i)) a = up[a][i];
	if (a == b) return a;
	for (int i = 17; i >= 0; i--)
		if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
	return up[a][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	while (m--) {
		cin >> a >> b;
		int ab = lca(a, b);
		++psa[in[a]], --psa[in[ab]], ++psa[in[b]], --psa[in[up[ab][0]]];
	}
	for (int i = 1; i <= 2 * n; i++) psa[i] += psa[i - 1];
	for (int i = 1; i <= n; i++) cout << psa[out[i]] - psa[in[i] - 1] << ' ';
	cout << '\n';
	return 0;
}
