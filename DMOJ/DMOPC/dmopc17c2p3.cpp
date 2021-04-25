#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> adj[200001];
queue<int> q;
int dist[200001], Y, ans = INT_MAX;

bool treeeeeeeeeeee(int cur, int prev) {
	if (cur == Y) return true;
	bool flag = false;
	for (int i : adj[cur]) {
		if (i != prev) flag |= treeeeeeeeeeee(i, cur);
	}
	if (flag) ans = min(ans, dist[cur]);
	return flag;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, R, a, b, r, X;
	cin >> N >> R;

	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}

	memset(dist, -1, sizeof(dist));
	while (R--) {
		cin >> r;
		q.push(r);
		dist[r] = 0;
	}

	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i : adj[cur]) {
			if (dist[i] == -1) {
				dist[i] = dist[cur] + 1;
				q.push(i);
			}
		}
	}

	cin >> X >> Y;
	treeeeeeeeeeee(X, -1);
	cout << min(ans, dist[Y]) << '\n';
	return 0;
}
