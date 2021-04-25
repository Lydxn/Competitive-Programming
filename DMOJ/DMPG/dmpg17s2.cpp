#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

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

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, x, y; char op;
	cin >> N >> Q;

	dsu.init(N);
	while (Q--) {
		cin >> op >> x >> y;
		if (op == 'A') dsu.join(x, y);
		else cout << (dsu.connected(x, y) ? 'Y' : 'N') << '\n';
	}
	return 0;
}
