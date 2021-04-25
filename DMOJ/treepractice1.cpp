#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> adj[500001];
int par[500001], dist[500001];

void dfs(int cur, int prev, int d, int& mx, int& mi) {
	par[cur] = prev;
	if (mx < d) mx = d, mi = cur;
	for (auto i : adj[cur])
		if (i.first != prev)
			dist[i.first] = i.second, dfs(i.first, cur, d + i.second, mx, mi);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, u, v, w;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w), adj[v].emplace_back(u, w);
	}

	int mx = 0, mi = 1, rad = INT_MAX;
	dfs(mi, mi, 0, mx, mi);
	dfs(mi, mi, 0, mx = 0, mi);
	for (int i = mi, sum = 0; i != par[i]; sum += dist[i], i = par[i])
		rad = min(rad, max(sum, mx - sum));

	cout << mx << '\n' << rad << '\n';
	return 0;
}
