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
	int a, b, c;
	bool operator <(edge &e) const { return c > e.c; }
} e[200000];
int par[100001], sz[100001];

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

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> e[i].a >> e[i].b >> e[i].c;
	for (int i = 1; i <= N; i++) par[i] = i, sz[i] = 1;
	sort(e, e + M);
	ll ans = 0; int cnt = 0;
	for (int i = 0; i < M; i++) {
		if (join(e[i].a, e[i].b))
			ans += e[i].c, ++cnt;
		else if (e[i].c > 0)
			ans += e[i].c;
	}
	if (cnt == N - 1) cout << ans << '\n';
	else cout << "Impossible\n";
	return 0;
}
