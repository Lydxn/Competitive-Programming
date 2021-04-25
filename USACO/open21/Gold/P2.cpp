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
	int u, v, w;
	bool operator< (const edge &e) const { return w < e.w; }
} e[300001];
int sz[200001], par[200001], eidx;

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
bool join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v], par[v] = u;
	return true;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, c, p1, p2, p3, p4;
	cin >> N;
	for (int i = 1; i <= 2 * N; i++) par[i] = i, sz[i] = 1;
	for (int i = 1; i <= N; i++) {
		cin >> c >> p1 >> p2 >> p3 >> p4;
		e[eidx++] = {p1, p2, 0}, e[eidx++] = {p3, p4, 0}, e[eidx++] = {p1, p4, c};
	}
	sort(e, e + eidx);
	ll ans = 0;
	for (int i = 0; i < eidx; i++)
		if (join(e[i].u, e[i].v)) ans += e[i].w;
	cout << ans << '\n';
	return 0;
}
