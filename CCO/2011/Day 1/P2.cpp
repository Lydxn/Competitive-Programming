#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef pair<int, ll> pill;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

struct edge {
	int v, d, up;
};

vector<edge> adj[1600];
int dist[3601][1600];
priority_queue<piii, vector<piii>, greater<piii>> pq;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int S, N, E, s, t, d, u;
	cin >> S >> N >> E;
	while (E--) {
		cin >> s >> t >> d >> u;
		adj[s].push_back({t, d, u}), adj[t].push_back({s, d, u});
	}

	memset(dist, INF, sizeof(dist));
	pq.push({{0, 0}, 0}); dist[0][0] = 0;
	while (!pq.empty()) {
		int cs = pq.top().first.first, cd = pq.top().first.second, cv = pq.top().second; pq.pop();
		if (cs > S || cd > dist[cs][cv]) continue;
		for (auto e : adj[cv]) {
			int ns = cs + e.d * e.up, nd = cd + e.d, nv = e.v;
			if (ns <= S && nd < dist[ns][nv])
				dist[ns][nv] = nd, pq.push({{ns, nd}, nv});
		}
	}

	int mn = INF;
	for (int i = 0; i <= S; i++) mn = min(mn, dist[i][N - 1]);
	cout << (mn == INF ? -1 : mn) << '\n';
	return 0;
}
