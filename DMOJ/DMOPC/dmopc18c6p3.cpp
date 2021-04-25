#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <const int MAXN>
struct DisjointSet
{
    int parent[MAXN + 1], sz[MAXN + 1];

    void init(const int N = MAXN) {
        for (int i = 1; i <= N; i++) parent[i] = i;
        memset(sz, 1, sizeof(sz));
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

    bool size(const int v) {
    	return sz[find(v)];
    }
};

DisjointSet<200000> ds;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b, cnt = 0;
	cin >> N >> M;

	ds.init(N);
	while (M--) {
		cin >> a >> b;
		cnt += !ds.join(a, b);
	}

	cout << (cnt <= 1 ? "YES" : "NO") << '\n';
	return 0;
}
