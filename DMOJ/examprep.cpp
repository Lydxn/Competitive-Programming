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

int sz[1000001], par[1000001];
ll r[1000001];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v], r[u] += r[v];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, op, a, b;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> r[i], sz[i] = 1, par[i] = i;
	while (Q--) {
		cin >> op;
		if (op == 1) cin >> a >> b, join(a, b);
		else if (op == 2) cin >> a, cout << sz[find(a)] << '\n';
		else cin >> a, cout << r[find(a)] << '\n';
	}
	return 0;
}
