#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct node { int x, y, dx, dy; };
bool grid[16][16];
int dist[16][16][7][7];
queue<node> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, X, Y, P, sx, sy, ex, ey, x1, x2, y1, y2;
	cin >> N;

	while (N--) {
		cin >> X >> Y >> sx >> sy >> ex >> ey >> P;
		memset(grid, true, sizeof(grid)); memset(dist, -1, sizeof(dist));

		while (P--) {
			cin >> x1 >> x2 >> y1 >> y2;
			for (int i = x1; i <= x2; i++) {
				for (int j = y1; j <= y2; j++) {
					grid[i][j] = false;
				}
			}
		}

		q = {}, q.push({sx, sy, 0, 0}), dist[sx][sy][3][3] = 0;
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					int nx = cur.x + cur.dx + i, ny = cur.y + cur.dy + j, ndx = cur.dx + i, ndy = cur.dy + j;
					if (nx >= 0 && nx < X && ny >= 0 && ny < Y && ndx >= -3 && ndx <= 3 && ndy >= -3 && ndy <= 3
					 && grid[nx][ny] && dist[nx][ny][ndx + 3][ndy + 3] == -1) {
							q.push({nx, ny, ndx, ndy});
							dist[nx][ny][ndx + 3][ndy + 3] = dist[cur.x][cur.y][cur.dx + 3][cur.dy + 3] + 1;
					}
				}
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i <= 6; i++) {
			for (int j = 0; j <= 6; j++) {
				if (dist[ex][ey][i][j] != -1)
					ans = min(ans, dist[ex][ey][i][j]);
			}
		}

		if (ans == INT_MAX) cout << "No solution.\n";
		else cout << "Optimal solution takes " << ans << " hops.\n";
	}
	return 0;
}
