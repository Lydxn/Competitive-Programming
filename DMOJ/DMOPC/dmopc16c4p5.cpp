#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> adj[200001];
priority_queue<pii, vector<pii>, less<pii>> pq;
int dist[200001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b, p;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> p;
		adj[a].emplace_back(b, p); adj[b].emplace_back(a, p);
	}

	dist[1] = INT_MAX; pq.emplace(INT_MAX, 1);
	while (!pq.empty()) {
		auto cv = pq.top().second, cw = pq.top().first; pq.pop();
		if (cw != dist[cv]) continue;

		for (const auto& i : adj[cv]) {
			int nw = min(cw, i.second);
			if (nw > dist[i.first]) {
				dist[i.first] = nw;
				pq.emplace(nw, i.first);
			}
		}
	}

	cout << "0\n";
	for (int i = 2; i <= N; i++) cout << dist[i] << '\n';
	return 0;
}
