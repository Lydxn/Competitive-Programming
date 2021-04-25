#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
int adj[1401][1401], dist[1401], cnt[1401];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, d, t;
	cin >> N;

	memset(adj, INF, sizeof(adj));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> d;
			adj[i][j] = adj[j][i] = adj[N + i][N + j] = adj[N + j][N + i] = d;
		}
		adj[i][i] = adj[N + i][N + i] = INF;
	}

	cin >> M;
	while (M--) {
		cin >> t;
		adj[t][N + t] = 0;
		for (int i = 1; i <= N; i++) adj[t][i] = INF;
	}

	memset(dist, INF, sizeof(dist));
	pq.emplace(0, 1); dist[1] = 0, cnt[1] = 1;
	while (!pq.empty()) {
		int cv = pq.top().second, cw = pq.top().first; pq.pop();
		if (cw > dist[cv]) continue;

		for (int i = 1; i <= 2 * N; i++) {
			if (adj[cv][i] != INF) {
				int nw = dist[cv] + adj[cv][i];
				if (nw < dist[i]) {
					dist[i] = nw, cnt[i] = cnt[cv];
					pq.emplace(nw, i);
				} else if (nw == dist[i]) cnt[i] = (cnt[i] + cnt[cv]) % 1000000;
			}
		}
	}

	cout << dist[2 * N] << ' ' << cnt[2 * N] << '\n';
	return 0;
}
