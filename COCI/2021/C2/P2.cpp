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

int par[1001], sz[1001];

int find(int u) { return u == par[u] ? u : par[u] = find(par[u]); }
bool join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v], par[v] = u;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, q, p, a, b;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
	while (m--)
		for (int i = 1; i <= n; i++)
			cin >> p, join(i, p);
	while (q--) {
		cin >> a >> b;
		cout << (find(a) == find(b) ? "DA" : "NE") << '\n';
	}
	return 0;
}