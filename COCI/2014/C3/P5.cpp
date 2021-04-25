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

int mp[300001], up[300001][20], dep[300001];

int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	int diff = dep[u] - dep[v];
	for (int i = 19; i >= 0; i--)
		if (diff & (1 << i))
			u = up[u][i];

	if (u == v) return u;

	for (int i = 19; i >= 0; i--)
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, v, w; char op;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> op >> v;
		if (op == 'a') {
			mp[i] = i, dep[i] = dep[mp[v]] + 1, up[i][0] = mp[v];
			for (int j = 1; j <= 19; j++) up[i][j] = up[up[i][j - 1]][j - 1];
		}
		else if (op == 'b') cout << mp[v] << '\n', mp[i] = up[mp[v]][0];
		else cin >> w, mp[i] = mp[v], cout << dep[lca(mp[i], mp[w])] << '\n';
	}
	return 0;
}
