#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int grid[1000][1000], dist[1000][1000];
queue<pii> q;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> grid[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
	q.emplace(0, 0); dist[0][0] = 0;

	while (!q.empty()) {
		int cr = q.front().first, cc = q.front().second; q.pop();
		for (auto d : dir) {
			int nr = (cr + grid[cr][cc] * d.first % R + R) % R, nc = (cc + grid[cr][cc] * d.second % C + C) % C;
			if (dist[nr][nc] == -1) dist[nr][nc] = dist[cr][cc] + 1, q.emplace(nr, nc);
		}
	}

	if (dist[R - 1][C - 1] == -1) cout << "FOREVER\n";
	else cout << dist[R - 1][C - 1] << '\n';
	return 0;
}
