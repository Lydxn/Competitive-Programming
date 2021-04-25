#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

template <const int MAXV, typename T, const int INDEXING>
struct Dijkstra {
	std::vector<std::pair<int, T>> adj[MAXV + INDEXING]; std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;
	const T INF = std::numeric_limits<T>::max(); T dist[MAXV + INDEXING]; int V;
	void add(int u, int v, T w) { adj[u].emplace_back(v, w); }
	void add_bi(int u, int v, T w) { add(u, v, w); add(v, u, w); }
	void min_path(int v, int V = MAXV) {
		this->V = V; std::fill(dist, dist + V + INDEXING, INF);
		pq.emplace(0, v); dist[v] = 0;
		while (!pq.empty()) {
			int cv = pq.top().second, cw = pq.top().first; pq.pop();
			if (cw > dist[cv]) continue;
			for (auto &i : adj[cv]) {
				T d = i.second + dist[cv];
				if (dist[i.first] > d) dist[i.first] = d, pq.emplace(d, i.first);
			}
		}
	}
	void clear() { for (int i = 0; i < V + INDEXING; i++) adj[i].clear(); }
};

const int W = 30000000;
Dijkstra<500000, ll, 1> white, black;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q, x, y, z, d; ll c; string col;
	cin >> N >> M;

	while (M--) {
		cin >> x >> y >> z;
		white.add_bi(x, y, W - z); black.add_bi(x, y, W + z);
	}

	white.min_path(1, N); black.min_path(1, N);
	cin >> Q;
	while (Q--) {
		cin >> d >> col;
		if (col[0] == 'W') c = (white.dist[d] + W - 1) / W, cout << c << ' ' << c * W - white.dist[d] << '\n';
		else c = black.dist[d] / W, cout << c << ' ' << black.dist[d] - c * W << '\n';
	}
	return 0;
}
