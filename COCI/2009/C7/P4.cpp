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

struct pt {
	int x, y, z, i;
} p[100001];
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

	int N, ans = 0; vector<pt> uf;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> p[i].x >> p[i].y >> p[i].z, p[i].i = i;
	for (int i = 1; i <= N; i++) par[i] = i, sz[i] = 1;
	sort(p + 1, p + N + 1, [&] (pt &a, pt &b) { return a.x < b.x; });
	for (int i = 1; i < N; i++) uf.push_back({p[i].i, p[i + 1].i, p[i + 1].x - p[i].x});
	sort(p + 1, p + N + 1, [&] (pt &a, pt &b) { return a.y < b.y; });
	for (int i = 1; i < N; i++) uf.push_back({p[i].i, p[i + 1].i, p[i + 1].y - p[i].y});
	sort(p + 1, p + N + 1, [&] (pt &a, pt &b) { return a.z < b.z; });
	for (int i = 1; i < N; i++) uf.push_back({p[i].i, p[i + 1].i, p[i + 1].z - p[i].z});
	sort(uf.begin(), uf.end(), [&] (pt &a, pt &b) { return a.z < b.z; });
	for (auto u : uf)
		if (join(u.x, u.y))
			ans += u.z;
	cout << ans << '\n';
	return 0;
}
