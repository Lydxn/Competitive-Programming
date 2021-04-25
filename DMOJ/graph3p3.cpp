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

struct edge {
	int a, b, c, d;
	bool operator< (edge e) { return (d << 16 | c) < (e.d << 16 | e.c); }
} edges[10000];
int par[101], sz[101];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
bool join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b, c, d;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> d;
		edges[i] = {a, b, c, d};
	}

	sort(edges, edges + M);
	for (int i = 1; i <= N; i++) par[i] = i, sz[i] = 1;

	int ans0 = 0, ans1 = 0, sz = 0;
	for (int i = 0; i < M; i++) {
		if (sz > N) break;
		if (join(edges[i].a, edges[i].b)) ans0 += edges[i].d, ans1 += edges[i].c, ++sz;
	}
	cout << ans0 << ' ' << ans1 << '\n';
	return 0;
}
