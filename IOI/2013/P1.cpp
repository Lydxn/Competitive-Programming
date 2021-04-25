#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> adj[100000];
int par[100000], dist[100000], rad[100000], ridx = 0;
bool vis[100000];

void dfs(int cur, int prev, int d, int& mx, int& mi) {
	par[cur] = prev;
	if (mx < d) mx = d, mi = cur;
	for (auto i : adj[cur])
		if (i.first != prev)
			dist[i.first] = i.second, vis[i.first] = true, dfs(i.first, cur, d + i.second, mx, mi);
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]) {
	for (int i = 0; i < M; i++)
		adj[A[i]].emplace_back(B[i], T[i]), adj[B[i]].emplace_back(A[i], T[i]);
	memset(par, -1, sizeof(par));

	int md = 0;
	for (int i = 0; i < N; i++) {
		if (!vis[i]) {
			int mx = 0, mi = i;
			dfs(mi, -1, 0, mx, mi); dfs(mi, -1, 0, mx = 0, mi);

			int r = mx;
			for (int j = mi, sum = 0; j != -1; sum += dist[j], j = par[j])
				r = min(r, max(sum, mx - sum));
			rad[ridx++] = r, md = max(md, mx);
		}
	}

	sort(rad, rad + ridx, greater<int>());
	return max(md, ridx == 1 ? 0 : max(rad[0] + rad[1] + L, ridx == 2 ? 0 : rad[1] + rad[2] + 2 * L));
}
