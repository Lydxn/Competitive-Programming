#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool vis[2001][2001], add[2001][2001];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
pii dir2[5] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {0, 0}};
queue<pii> q;

int adj(int x, int y) {
	int res = 0;
	for (pii d : dir) res += vis[x + d.first][y + d.second] || add[x + d.first][y + d.second];
	return res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int N, x, y, ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x >> y; x += 1000, y += 1000;
		vis[x][y] = true;

		for (pii d : dir2)
			if (vis[x + d.first][y + d.second] || add[x + d.first][y + d.second])
				q.emplace(x + d.first, y + d.second);
				
		while (!q.empty()) {
			int cx = q.front().first, cy = q.front().second; q.pop();
			if (adj(cx, cy) != 3) continue;
			for (pii d : dir) {
				int nx = cx + d.first, ny = cy + d.second;
				if (!vis[nx][ny] && !add[nx][ny]) {
					add[nx][ny] = true, ++ans;
					for (pii e : dir2)
						if (vis[nx + e.first][ny + e.second] || add[nx + e.first][ny + e.second])
							q.emplace(nx + e.first, ny + e.second);
					break;
				}
			}
		}
		
		if (add[x][y]) add[x][y] = false, --ans;
		cout << ans << '\n';
	}
}