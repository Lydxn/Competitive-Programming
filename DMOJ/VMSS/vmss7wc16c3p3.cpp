#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
vector<pii> adj[2001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dist[2001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, B, Q, X, Y, Z, A;
	cin >> N >> M >> B >> Q;
	while (M--) cin >> X >> Y >> Z, adj[X].emplace_back(Y, Z), adj[Y].emplace_back(X, Z);

	memset(dist, INF, sizeof(dist));
	dist[B] = 0, pq.emplace(0, B);
	while (!pq.empty()) {
		int cv = pq.top().second, cw = pq.top().first; pq.pop();
		if (cw > dist[cv]) continue;

		for (auto i : adj[cv]) {
			int nw = cw + i.second;
			if (nw < dist[i.first]) {
				dist[i.first] = nw;
				pq.emplace(nw, i.first);
			}
		}
	}

	while (Q--) {
		cin >> A;
		cout << (dist[A] == INF ? -1 : dist[A]) << '\n';
	}
	return 0;
}
