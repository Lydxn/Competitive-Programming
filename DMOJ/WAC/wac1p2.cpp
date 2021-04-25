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

template <const int MAXN, const int INDEXING>
struct DSU {
	int par[MAXN + INDEXING], sz[MAXN + INDEXING];
	void init(int N = MAXN) { for (int i = 0; i < N + INDEXING; i++) par[i] = i, sz[i] = 1; }
	int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
	bool join(int u, int v) {
		if ((u = find(u)) == (v = find(v))) return false;
		if (sz[u] < sz[v]) std::swap(u, v);
		par[v] = u, sz[u] += sz[v];
		return true;
	}
	bool connected(int u, int v) { return find(u) == find(v); }
	int size(int v) { return sz[find(v)]; }
};

DSU<100000, 1> dsu;
int cnt[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, u, v, move = 0;
	cin >> N >> M >> K;

	dsu.init(N);
	while (M--) {
		cin >> u >> v;
		move += !dsu.join(u, v);
	}

	unordered_set<int> comp;
	for (int i = 1; i <= N; i++) comp.insert(dsu.find(i));
	cout << max(0, int(comp.size()) - 1 - min(K, move)) << '\n';
	return 0;
}
