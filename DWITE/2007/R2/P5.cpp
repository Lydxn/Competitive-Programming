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
		if (sz[u] < sz[v]) swap(u, v);
		par[v] = u, sz[u] += sz[v];
		return true;
	}
	bool connected(int u, int v) { return find(u) == find(v); }
	int size(int v) { return sz[find(v)]; }
};

DSU<100, 1> dsu[101];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	for (int _ = 0; _ < 5; _++) {
		int N, M, a, b, cnt = 0;
		cin >> N >> M;

		for (int i = 0; i < M; i++) dsu[i].init(N);
		for (int i = 0; i < M; i++) {
			cin >> a >> b;
			for (int j = 0; j < M; j++) if (j != i) dsu[j].join(a, b);
		}

		for (int i = 0; i < M; i++) cnt += dsu[i].size(1) != N;
		cout << cnt << '\n';
	}
	return 0;
}
