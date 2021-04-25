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

struct node {
	int v, t, c;
	bool operator< (node n) { return c > n.c || (c == n.c && t > n.t); }
};

int N;
vector<node> adj[2001];
set<plli> pq;
ll fdist[2001], tdist[2001], cdist[2001];
bool vis[2001];

void dijkstra(int x) {
	memset(tdist, INFL, sizeof(tdist)); memset(cdist, INFL, sizeof(cdist));
	pq = {}, pq.insert({0, 1}), tdist[1] = cdist[1] = 0;
	while (!pq.empty()) {
		int cv = pq.begin()->second; pq.erase(pq.begin());
		for (auto i : adj[cv]) {
			ll w = tdist[i.v] * x + cdist[i.v] * (2000 - x), nw = (tdist[cv] + i.t) * x + (cdist[cv] + i.c) * (2000 - x);
			if (nw < w) {
				pq.erase({w, i.v});
				tdist[i.v] = tdist[cv] + i.t, cdist[i.v] = cdist[cv] + i.c;
				pq.insert({nw, i.v});
			}
		}
	}

	for (int i = 2; i <= N; i++)
		if (tdist[i] != INFL && cdist[i] != INFL)
			fdist[i] = min(fdist[i], tdist[i] * cdist[i]);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int M, A, B, T, C;
	cin >> N >> M;
	while (M--) {
		cin >> A >> B >> T >> C;
		adj[A].push_back({B, T, C}), adj[B].push_back({A, T, C});
	}

	memset(fdist, INFL, sizeof(fdist));
	for (int i = 0; i <= 2000; i++) dijkstra(i);
	for (int i = 2; i <= N; i++) cout << (fdist[i] == INFL ? -1 : fdist[i]) << '\n';
	return 0;
}
