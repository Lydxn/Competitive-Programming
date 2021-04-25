#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[400001];
ll cnt = 0, dp2[400001]; int len = 0, dp1[400001];

void dfs(int cur, int prev) {
	for (int i : adj[cur]) {
		if (i != prev) {
			dfs(i, cur);
			if (dp1[cur] + dp1[i] + 1 == len) cnt += dp2[cur] * dp2[i];
			else if (dp1[cur] + dp1[i] + 1 > len) len = dp1[cur] + dp1[i] + 1, cnt = dp2[cur] * dp2[i];
			if (dp1[cur] == dp1[i] + 1) dp2[cur] += dp2[i];
			else if (dp1[cur] < dp1[i] + 1) dp1[cur] = dp1[i] + 1, dp2[cur] = dp2[i];
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b;
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	fill(dp2 + 1, dp2 + N + 1, 1);
	dfs(1, -1);
	cout << len + 1 << ' ' << cnt << '\n';
	return 0;
}
