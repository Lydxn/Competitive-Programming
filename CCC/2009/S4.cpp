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
	int parent[MAXV + 1];

	void add(int u, int v, T w) { adj[u].emplace_back(v, w); }

	void add_bi(int u, int v, T w) { add(u, v, w); add(v, u, w); }

	void min_path(int v, int V = MAXV)
	{
		priority_queue<Node>().swap(pq);
		fill(dist, dist + V + 1, INF);
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

	void clear() { for (int i = 0; i <= MAXV; i++) adj[i].clear(); }
};

const int MAXN = 5000;
Dijkstra<MAXN, int> dijkstra;
int pencils[MAXN + 1];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int N, T, x, y, c, K, z, P, D, min_cost = INT_MAX;
    cin >> N >> T;
    
    while (T--)
    {
        cin >> x >> y >> c;
        dijkstra.add_bi(x, y, c);
    }
    
    cin >> K;
    while (K--)
    {
        cin >> z >> P;
        pencils[z] = P;
    }
    
    cin >> D;
    dijkstra.min_path(D);
    for (int i = 1; i <= N; i++) dijkstra.dist[i] += pencils[i];
    
    for (int i = 1; i <= N; i++)
    {
        if (pencils[i]) min_cost = min(min_cost, dijkstra.dist[i]);
    }
    
    cout << min_cost << '\n';
    return 0;
}
