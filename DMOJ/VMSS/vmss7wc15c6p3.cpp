#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[400001];
int c[400001], ans = INT_MIN;

int dfs(int cur, int prev) {
	int t = c[cur];
	for (int i : adj[cur])
		if (i != prev)
			t += dfs(i, cur);

	ans = max(ans, t);
	return t;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) cin >> c[i];

	dfs(1, -1);
	cout << ans << '\n';
	return 0;
}
