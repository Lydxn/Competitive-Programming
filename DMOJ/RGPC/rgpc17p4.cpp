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

int dist[1001], len[1001], in[1001], top[1001], tidx;
vector<pii> adj[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b, d;
	cin >> N >> M;
	while (M--) {
		cin >> a >> b >> d;
		adj[a].emplace_back(b, d), ++in[b];
	}

	for (int i = 1; i <= N; i++)
		if (!in[i]) top[tidx++] = i;
	len[1] = 1;
	for (int i = 0; i < tidx; i++) {
		int v = top[i];
		for (auto j : adj[v]) {
			int nv = j.first;
			if (--in[nv] == 0) top[tidx++] = nv;
			int nd = dist[v] + j.second;
			if (nd > dist[nv]) dist[nv] = nd, len[nv] = len[v] + 1;
			else if (nd == dist[nv] && len[nv] < len[v] + 1) len[nv] = len[v] + 1;
		}
	}
	if (tidx == N) cout << dist[N] << ' ' << len[N] << '\n';
	else cout << "-1\n";
	return 0;
}
