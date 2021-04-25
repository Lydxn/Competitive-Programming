#include <bits/stdc++.h>

using namespace std;

template <const int MAXV, typename T>
struct Dijkstra {
	struct Node {
		int v; T w;
		Node(int v, T w) : v(v), w(w) {}
		bool operator < (const Node& n) const { return n.w < w; }
	};

	const T INF = 999999999;
	vector<Node> adj[MAXV + 1];
	priority_queue<Node> pq;
	T dist[MAXV + 1];
	int parent[MAXV + 1], _V;

	void add(const int u, const int v, const T w) {
		adj[u].emplace_back(v, w);
	}

	void add_bi(const int u, const int v, const T w) {
		add(u, v, w); add(v, u, w);
	}

	void min_path(const int v, const int V = MAXV) {
		_V = V;
		priority_queue<Node>().swap(pq);
		fill(dist, dist + _V + 1, INF);
		memset(parent, -1, sizeof(parent));
		pq.emplace(v, 0);
		dist[v] = 0;
		while (!pq.empty()) {
			int cv = pq.top().v, cw = pq.top().w;
			pq.pop();
			if (cw > dist[cv]) continue;
			for (const auto& i : adj[cv]) {
				T d = i.w + dist[cv];
				if (dist[i.v] > d) {
					parent[i.v] = cv;
					dist[i.v] = d;
					pq.emplace(i.v, dist[i.v]);
				}
			}
		}
	}

	vector<int> get_path(int v) {
		vector<int> res;
		for (; v != -1; v = parent[v]) res.push_back(v);
		reverse(res.begin(), res.end());
		return res;
	}

	void clear() {
		for (int i = 0; i <= _V; i++) adj[i].clear();
	}
};

Dijkstra<500000, int> dijkstra1, dijkstra2;
int dist1[500001], dist2[500001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, M, D, a, b, k, g;
    cin >> N >> M;
    
    while (M--) {
        cin >> a >> b >> k;
        dijkstra1.add(a, b, k);
        dijkstra2.add(b, a, k);
    }
    
    dijkstra1.min_path(1, N);
    memcpy(dist1, dijkstra1.dist, sizeof(dist1));
    dijkstra2.min_path(N, N);
    memcpy(dist2, dijkstra2.dist, sizeof(dist2));
    
    int ans = dist1[N];
    cin >> D;
    for (int i = 0; i < D; i++) {
        cin >> a >> b >> g;
        ans = min(ans, dist1[a] + g + dist2[b]);
    }
    
    cout << (ans == dijkstra1.INF ? -1 : ans) << '\n';
    return 0;
}
