#include <bits/stdc++.h>
#define dim(i, j) (1 << (i * n + j))

using namespace std;

const int MAXN = 1 << 20;
int dist[MAXN];
vector<int> adj[MAXN];
queue<int> q;
pair<int, int> dir[8] = {{1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int m, n, a, b, c, gen = 0; char ch;
	cin >> m >> n >> a >> b >> c;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> ch;
			if (ch == '*') gen |= dim(i, j);
		}
	}

	for (int i = 0; i < 1 << (m * n); i++) {
		int nxt = i;
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				int cnt = 0;
				for (const auto& d : dir) {
					int nj = j + d.first, nk = k + d.second;
					if (nj >= 0 && nj < m && nk >= 0 && nk < n && (i & dim(nj, nk))) ++cnt;
				}

				if ((i & dim(j, k)) && (cnt < a || cnt > b)) nxt &= ~dim(j, k);
				else if ((i & ~dim(j, k)) && cnt > c) nxt |= dim(j, k);
			}
		}
		if (nxt != i) adj[nxt].push_back(i);
	}

	memset(dist, -1, sizeof(dist));
	q.push(gen); dist[gen] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (adj[cur].empty()) {
			cout << dist[cur] << '\n';
			return 0;
		}

		for (int i : adj[cur]) {
			if (dist[i] == -1) {
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}

	cout << "-1\n";
	return 0;
}
