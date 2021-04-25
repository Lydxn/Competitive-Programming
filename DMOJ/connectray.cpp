#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

unordered_set<ll> seen;
vector<int> adj[400001];
bool vis[400001];

void dfs(int x) {
	vis[x] = true;
	for (int i : adj[x])
		if (!vis[i])
			dfs(i);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, Q, a, b, x, y; char op;
	cin >> N >> M >> Q;
	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	dfs(1);
	while (Q--) {
		cin >> op;
		if (op == '?') cin >> x, cout << (vis[x] ? "YES" : "NO") << '\n';
		else {
			cin >> x >> y;
			if (!seen.count(x * 400001LL + y)) adj[x].push_back(y);
			else seen.insert(x * 400001LL + y);

			if (vis[x] && !vis[y]) dfs(y);
		}
	}
	return 0;
}
