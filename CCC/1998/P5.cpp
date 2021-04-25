#include <bits/stdc++.h>

using namespace std;

int grid[25][25], dist[25][25];
queue<pair<int, int>> q;
pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int t, n, lim;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}

		lim = grid[0][0];
		q = {}; q.emplace(0, 0);
		memset(dist, -1, sizeof(dist)); dist[0][0] = 0;

		while (!q.empty()) {
			int r = q.front().first, c = q.front().second; q.pop();
			for (const auto& d : dir) {
				int nr = r + d.first, nc = c + d.second;
				if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == -1 && abs(grid[nr][nc] - grid[r][c]) <= 2) {
					dist[nr][nc] = dist[r][c] + (grid[r][c] > lim || grid[nr][nc] > lim);
					q.emplace(nr, nc);
				}
			}
		}

		if (dist[n - 1][n - 1] == -1) cout << "CANNOT MAKE THE TRIP\n\n";
		else cout << dist[n - 1][n - 1] << "\n\n";
	}
	return 0;
}
