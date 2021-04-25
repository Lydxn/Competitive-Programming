#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> adj[19];
int N, M, A, B, V, bestd = INT_MAX, ans = INT_MAX;
bool dp[19][1 << 19];

void dfs(int cur, int vis, int d) {
	if (cur == B) {
		int temp = abs(V - d);
		if (temp < bestd) bestd = temp, ans = d;
		else if (temp == bestd) ans = min(ans, d);
		return;
	}

	if (dp[cur][vis]) return;
	dp[cur][vis] = true;

	for (int i : adj[cur]) {
		if (!(vis & (1 << i))) dfs(i, vis | (1 << i), d + 1);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> N >> M >> A >> B >> V;

	while (M--) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}

	dfs(A, 1 << A, 0);
	cout << ans << '\n';
	return 0;
}
