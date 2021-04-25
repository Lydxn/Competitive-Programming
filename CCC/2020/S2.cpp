#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

queue<pii> q;
vector<pii> adj[1000001];
bool vis[1001][1001];
int grid[1001][1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> grid[i][j];
			adj[i * j].emplace_back(i, j);
		}
	}

	q.emplace(1, 1); vis[1][1] = true;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur.first == M && cur.second == N) {
			cout << "yes\n";
			return 0;
		}

		for (auto p : adj[grid[cur.first][cur.second]]) {
			if (!vis[p.first][p.second]) {
				vis[p.first][p.second] = true;
				q.emplace(p.first, p.second);
			}
		}
	}

	cout << "no\n";
	return 0;
}
