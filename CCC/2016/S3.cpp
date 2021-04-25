#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100000];
bool path[100000];
int dist[100000];

void dfs1(int cur, int prev) { for (int i : adj[cur]) if (i != prev) dfs1(i, cur), path[cur] |= path[i]; }
void dfs2(int cur, int prev, int dep) { dist[cur] = dep; for (int i : adj[cur]) if (i != prev && path[i]) dfs2(i, cur, dep + 1); }

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b, p, sz = 0, mx = 0, mi = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> p, path[p] = true;
	for (int i = 0; i < N - 1; i++) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	dfs1(p, -1);
	for (int i = 0; i < N; i++) sz += path[i];

	dfs2(p, -1, 0);
	for (int i = 0; i < N; i++) if (dist[i] > mx) mx = dist[i], mi = i;
	memset(dist, 0, sizeof(dist)); mx = 0; dfs2(mi, -1, 0);
	for (int i = 0; i < N; i++) if (dist[i] > mx) mx = dist[i];

	cout << 2 * (sz - 1) - mx << '\n';
	return 0;
}
