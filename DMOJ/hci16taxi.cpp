#include <bits/stdc++.h>

using namespace std;

template <const int MAXV, typename T>
struct Dijkstra
{
	struct Node
	{
		int v; T w;

		Node(int v, T w) : v(v), w(w) {}

		bool operator < (const Node& n) const { return n.w < w; }
	};

	const T INF = numeric_limits<T>::max();
	vector<Node> adj[MAXV + 1];
	priority_queue<Node> pq;
	T dist[MAXV + 1];
	int parent[MAXV + 1], _V;

	void add(const int u, const int v, const T w) { adj[u].emplace_back(v, w); }

	void add_bi(const int u, const int v, const T w) { add(u, v, w); add(v, u, w); }

	void min_path(const int v, const int V = MAXV)
	{
		_V = V;
		priority_queue<Node>().swap(pq);
		fill(dist, dist + _V + 1, INF);
		memset(parent, -1, sizeof(parent));

		pq.emplace(v, 0);
		dist[v] = 0;

		while (!pq.empty())
		{
			int cv = pq.top().v, cw = pq.top().w;
			pq.pop();

			if (cw > dist[cv]) continue;

			for (const auto& i : adj[cv])
			{
				T d = i.w + dist[cv];
				if (dist[i.v] > d)
				{
					parent[i.v] = cv;
					dist[i.v] = d;
					pq.emplace(i.v, dist[i.v]);
				}
			}
		}
	}

	vector<int> get_path(int v)
	{
		vector<int> res;
		for (; v != -1; v = parent[v]) res.push_back(v);
		reverse(res.begin(), res.end());
		return res;
	}

	void clear() { for (int i = 0; i <= _V; i++) adj[i].clear(); }
};

Dijkstra<100000, int> dijkstra;

inline int cost(int x) {
    return x <= 10 ? 2 * x + 3 : x + 13;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int V, E, P, D, R, A, B, C;
    cin >> V >> E >> P >> D >> R;
    
    while (E--) {
        cin >> A >> B >> C;
        dijkstra.add_bi(A, B, C);
    }
    
    dijkstra.min_path(P);
    if (dijkstra.dist[D] == INT_MAX) cout << "Nooooooooo!!!\n";
    else if (dijkstra.dist[R] == INT_MAX) cout << cost(dijkstra.dist[D]) << "\nYippee!!!\n";
    else {
        int temp = dijkstra.dist[D];
        dijkstra.min_path(D);
        cout << cost(temp + dijkstra.dist[R]) << '\n';
    }
    return 0;
}
