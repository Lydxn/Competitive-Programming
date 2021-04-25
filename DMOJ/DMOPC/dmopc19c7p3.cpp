#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll w[1000001], K, sum;
bool vis[1000001];
vector<int> adj[1000001], ans;

void dfs(int cur) {
	if (vis[cur]) return;
	if (sum >= K && sum <= 2 * K) {
		cout << ans.size() << '\n';
		for (int a : ans) cout << a << ' ';
		cout << '\n';
		exit(0);
	}

	vis[cur] = true, ans.push_back(cur), sum += w[cur];
	for (auto i : adj[cur]) dfs(i);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x, y;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> w[i];

	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		if (w[x] <= 2 * K && w[y] <= 2 * K)
			adj[x].push_back(y), adj[y].push_back(x);
	}

	for (int i = 1; i <= N; i++) {
		if (!vis[i]) ans.clear(), sum = 0, dfs(i);
	}

	cout << "-1\n";
	return 0;
}
