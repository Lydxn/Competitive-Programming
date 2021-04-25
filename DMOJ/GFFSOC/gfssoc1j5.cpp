#include <bits/stdc++.h>

using namespace std;

template <const int MAXV>
struct BFS
{
	vector<int> adj[MAXV + 1];
	queue<int> q;
	int dist[MAXV + 1], parent[MAXV + 1], _V;

	void add(const int u, const int v) { adj[u].push_back(v); }

	void add_bi(const int u, const int v) { add(u, v); add(v, u); }

	void min_path(const int v, const int V = MAXV)
	{
		_V = V;
		queue<int>().swap(q);
		fill(dist, dist + _V + 1, INT_MAX);
		memset(parent, -1, sizeof(parent));

		q.push(v);
		dist[v] = 0;

		while (!q.empty())
		{
			int curr = q.front();
			q.pop();

			for (int i : adj[curr])
			{
				if (dist[i] == INT_MAX)
				{
					parent[i] = curr;
					dist[i] = dist[curr] + 1;
					q.push(i);
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

BFS<1000> bfs;
int ans[1001][1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M, T, Q, a, b;
    cin >> N >> M >> T;
    
    while (M--) {
        cin >> a >> b;
        bfs.add(a, b);
    }
    
    for (int i = 1; i <= N; i++) {
        bfs.min_path(i, N);
        memcpy(ans[i], bfs.dist, (N + 1) << 2);
    }
    
    cin >> Q;
    while (Q--) {
        cin >> a >> b;
        if (ans[a][b] == INT_MAX) cout << "Not enough hallways!\n";
        else cout << ans[a][b] * T << '\n';
    }
    return 0;
}
