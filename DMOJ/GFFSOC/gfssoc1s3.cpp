#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
char grid[20][20];
vector<pii> hiders;
queue<pii> q;
int dist[20][20], dist2[6][6];
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, T, ans = INT_MAX;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'H') hiders.emplace_back(i, j);
			else if (grid[i][j] == 'G') hiders.emplace(hiders.begin(), i, j);
		}
	}

	for (int i = 0; i <= T; i++) {
		q = {}; memset(dist, INF, sizeof(dist));
		q.push(hiders[i]); dist[hiders[i].first][hiders[i].second] = 0;
		while (!q.empty()) {
			int cr = q.front().first, cc = q.front().second; q.pop();
			for (auto d : dir) {
				int nr = cr + d.first, nc = cc + d.second;
				if (nr >= 0 && nr < N && nc >= 0 && nc < M && dist[nr][nc] == INF && grid[nr][nc] != 'X') {
					dist[nr][nc] = dist[cr][cc] + 1;
					q.emplace(nr, nc);
				}
			}
		}
		for (int j = 0; j <= T; j++) dist2[i][j] = dist[hiders[j].first][hiders[j].second];
	}

	vector<int> perm(T + 1); iota(perm.begin(), perm.end(), 0);
	do {
		int res = 0;
		for (int i = 1; i <= T; i++) res += dist2[perm[i - 1]][perm[i]];
		ans = min(ans, res);
	} while (next_permutation(perm.begin() + 1, perm.end()));

	cout << ans << '\n';
	return 0;
}
