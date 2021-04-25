#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <const int MAXN>
struct DisjointSet
{
    int parent[MAXN + 1], sz[MAXN + 1];

    void init(const int N = MAXN) {
        for (int i = 1; i <= N; i++) parent[i] = i, sz[i] = 1;
    }

    int find(const int v) {
    	return v == parent[v] ? v : parent[v] = find(parent[v]);
    }

    bool join(int v, int w) {
        if ((v = find(v)) == (w = find(w))) return false;
        if (sz[v] < sz[w]) swap(v, w);
        parent[w] = v;
        sz[v] += sz[w];
        return true;
    }

    bool connected(const int v, const int w) {
    	return find(v) == find(w);
    }

    int size(const int v) {
    	return sz[find(v)];
    }
};

DisjointSet<100000> ds;
unordered_set<int> sz;
int deg[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b, x, odds = 0;
	cin >> N >> Q;

	ds.init(N);
	for (int i = 0; i < Q; i++) {
		cin >> a >> b >> x;
		deg[a] += x, deg[b] += x;
		odds += (deg[a] % 2 - (deg[a] - x) % 2) + (deg[b] % 2 - (deg[b] - x) % 2);
		ds.join(a, b); sz.insert(a); sz.insert(b);
		cout << (ds.size(a) == int(sz.size()) && (odds == 0 || odds == 2) ? "YES" : "NO") << '\n';
	}
	return 0;
}
