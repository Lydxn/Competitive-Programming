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

int par[100001], sz[100001], cnt, mx;

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v], par[v] = u;
	--cnt, mx = max(mx, sz[u]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
	cnt = n;
	while (m--) {
		cin >> a >> b; join(a, b);
		cout << cnt << ' ' << mx << '\n';
	}
	return 0;
}
