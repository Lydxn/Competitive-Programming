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

vector<int> adj[101];
int adist[101], dist[101];
queue<int> q;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, X, Y, W, w;
	cin >> N >> M;
	while (M--) {
		cin >> X >> Y;
		adj[X].push_back(Y), adj[Y].push_back(X);
	}

	memset(adist, INF, sizeof(adist));
	memset(dist, INF, sizeof(dist));

	cin >> W;
	while (W--) {
		cin >> w;
		adist[w] = 0, q.push(w);
	}

	while (!q.empty()) {
		int cv = q.front(); q.pop();
		for (int i : adj[cv])
			if (adist[i] == INF)
				adist[i] = adist[cv] + 4, q.push(i);
	}

	q = {}; q.push(1); dist[1] = 0;
	while (!q.empty()) {
		int cv = q.front(); q.pop();
		for (int i : adj[cv])
			if (dist[i] == INF && dist[cv] < adist[i])
				dist[i] = dist[cv] + 1, q.push(i);
	}

	if (dist[N] == INF) cout << "sacrifice bobhob314\n";
	else cout << dist[N] << '\n';
	return 0;
}
