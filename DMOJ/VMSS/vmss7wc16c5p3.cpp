#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[10001];
int mx, mi;

void dfs(int cur, int prev, int d) {
	if (d > mx) mx = d, mi = cur;
	for (int i : adj[cur]) if (i != prev) dfs(i, cur, d + 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, y;
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> x >> y, adj[x].push_back(y), adj[y].push_back(x);

	dfs(1, -1, 0); dfs(mi, -1, 0);
	cout << mx << '\n';
	return 0;
}
