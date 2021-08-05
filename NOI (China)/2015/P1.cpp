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

unordered_map<int, int> mp;
int par[200001], sz[200001], midx;
vector<pii> E[2];

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

	int t, n, x, y; bool e;
	cin >> t;
	while (t--) {
		cin >> n; mp.clear(); E[0].clear(); E[1].clear(); midx = 0;
		while (n--) {
			cin >> x >> y >> e;
			if (!mp.count(x)) mp[x] = ++midx;
			if (!mp.count(y)) mp[y] = ++midx;
			E[e].emplace_back(mp[x], mp[y]);
		}
		for (int i = 1; i <= midx; i++) par[i] = i, sz[i] = 1;
		for (auto i : E[1]) join(i.first, i.second);
		for (auto i : E[0])
			if (find(i.first) == find(i.second))
				{ cout << "NO\n"; goto no; }
		cout << "YES\n"; no:;
	}
	return 0;
}
