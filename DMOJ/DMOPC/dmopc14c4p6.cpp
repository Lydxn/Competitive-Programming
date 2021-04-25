#include <bits/stdc++.h>

using namespace std;

vector<int> adj[500001];
int dist1[500001], dist2[500001];

void dfs1(int v, int prev) {
	for (int i : adj[v]) {
		if (i != prev) {
			dist1[i] = dist1[v] + 1, dfs1(i, v);
		}
	}
}

void dfs2(int v, int prev) {
	for (int i : adj[v]) {
		if (i != prev) {
			dist2[i] = dist2[v] + 1, dfs2(i, v);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, u, v;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v); adj[v].push_back(u);
	}

	dfs1(1, -1);
	dfs2(max_element(dist1 + 1, dist1 + N + 1) - dist1, -1);
	memset(dist1, 0, sizeof(dist1));
	dfs1(max_element(dist2 + 1, dist2 + N + 1) - dist2, -1);

	for (int i = 1; i <= N; i++) cout << max(dist1[i], dist2[i]) + 1 << '\n';
	return 0;
}
