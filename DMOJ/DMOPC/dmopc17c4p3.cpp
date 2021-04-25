#include <bits/stdc++.h>
#define getmax maxv = 0; for (int i = 1; i <= N; i++) if (maxv < dist[i]) maxv = dist[i], maxi = i
#define getans for (int i = 1; i <= N; i++) if (i != maxi) ans = max(ans, dist[i]);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> adj[100001];
ll dist[100001];

void dfs(int cur, int prev = -1, ll d = 0) {
	dist[cur] = d; for (const auto& i : adj[cur]) if (i.first != prev) dfs(i.first, cur, d + i.second);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b, c, maxi = -1; ll ans = 0, maxv;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c); adj[b].emplace_back(a, c);
	}

	dfs(1); getmax;
	dfs(maxi); getmax; getans;
	dfs(maxi); getmax; getans;

	cout << ans << '\n';
	return 0;
}
