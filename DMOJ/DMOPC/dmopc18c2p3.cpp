#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

template <const int MAXV, const int INDEXING>
struct BFS {
	std::vector<int> adj[MAXV + INDEXING]; std::queue<int> q; int dist[MAXV + INDEXING], par[MAXV + INDEXING], V;
	void add(int u, int v) { adj[u].push_back(v); }
	void add_bi(int u, int v) { add(u, v); add(v, u); }
	void min_path(int v, int V = MAXV) {
		this->V = V; q = {}; std::fill(dist, dist + V + INDEXING, INT_MAX); std::fill(par, par + V + INDEXING, -1);
		q.push(v); dist[v] = 0;
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int i : adj[cur]) {
				if (dist[i] == INT_MAX) {
					dist[i] = dist[cur] + 1, par[i] = cur;
					q.push(i);
				}
			}
		}
	}
	std::vector<int> get_path(int v) {
		std::vector<int> res;
		for (; v != -1; v = par[v]) res.push_back(v);
		std::reverse(res.begin(), res.end()); return res;
	}
	void clear() { for (int i = 0; i < V + INDEXING; i++) adj[i].clear(); }
};

BFS<100000, 1> bfsa, bfsb;
int s[100000];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, A, B, a, b, ans = INT_MAX;
	cin >> N >> M >> K >> A >> B;
	for (int i = 0; i < K; i++) cin >> s[i];

	while (M--) {
		cin >> a >> b;
		bfsa.add_bi(a, b); bfsb.add_bi(a, b);
	}

	bfsa.min_path(A, N); bfsb.min_path(B, N);
	for (int i = 0; i < K; i++) ans = min(ans, bfsa.dist[s[i]] + bfsb.dist[s[i]]);

	cout << ans << '\n';
	return 0;
}
