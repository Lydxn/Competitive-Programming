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
	int a, b; double w;
	bool operator< (const edge &e) const { return w < e.w; }
} e[1000000];
int x[751], y[751], par[751], sz[751], eidx;

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

	int N, M, a, b;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> x[i] >> y[i];
	for (int i = 1; i <= N; i++) par[i] = i, sz[i] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			e[eidx++] = {i, j, sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]))};
	sort(e, e + eidx);
	cin >> M;
	while (M--) cin >> a >> b, join(a, b);
	double s = 0; vector<int> ans;
	for (int i = 0; i < eidx; i++)
		if (join(e[i].a, e[i].b))
			s += e[i].w, ans.push_back(i);
	cout << fixed << setprecision(2) << s << '\n';
	for (int i : ans) cout << e[i].a << ' ' << e[i].b << '\n';
	return 0;
}
