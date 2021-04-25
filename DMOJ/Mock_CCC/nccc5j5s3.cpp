#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[51];
vector<pii> edges;
bool vis[51];

void dfs(int cur, int prev) {
	if (vis[cur]) return;
	vis[cur] = true;
	for (auto e : adj[cur]) if (e != prev) dfs(e, cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, s, t;
	cin >> N >> M;
	while (M--) cin >> s >> t, adj[s].push_back(t), edges.emplace_back(s, t);

	for (auto e : edges) {
		adj[e.first].erase(remove(adj[e.first].begin(), adj[e.first].end(), e.second), adj[e.first].end());
		memset(vis, false, sizeof(vis));
		dfs(1, -1);
		cout << (vis[N] ? "YES" : "NO") << '\n';
		adj[e.first].push_back(e.second);
	}
	return 0;
}
