#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dpc[10001], dpv[10001], ans, C, K;
vector<pii> adj[10001];

void solve(int cur, int prev) {
	for (auto i : adj[cur]) {
		if (i.first != prev) {
			solve(i.first, cur);
			dpc[cur] += dpc[i.first], dpv[cur] += dpv[i.first] + i.second;
			if (dpc[i.first] >= C && dpv[i.first] + i.second <= K) ++ans;
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b, k;
	cin >> N >> C >> K;
	for (int i = 1; i <= N; i++) cin >> dpc[i];
	for (int i = 0; i < N - 1; i++) cin >> a >> b >> k, adj[a].emplace_back(b, k), adj[b].emplace_back(a, k);

	solve(1, -1);
	cout << ans << '\n';
	return 0;
}
