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

priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<pii> adj[1001];
int g[1001], r[1001], dst[1001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, K, s, e, t;
	cin >> N >> K;
	while (N--) {
		cin >> s >> e >> t;
		adj[s].emplace_back(e, t), adj[e].emplace_back(s, t);
	}
	for (int i = 1; i <= K; i++) cin >> g[i] >> r[i];
	memset(dst, INF, sizeof(dst));
	pq.emplace(0, 1); dst[1] = 0;
	while (!pq.empty()) {
		int cw = pq.top().first, cv = pq.top().second; pq.pop();
		if (cw > dst[cv]) continue;
		for (auto i : adj[cv]) {
			int nw = cw + i.second;
			int am = i.first == 1 || i.first == K ? -1 : nw % (g[i.first] + r[i.first]);
			if (am >= g[i.first]) nw += g[i.first] + r[i.first] - am;
			if (dst[i.first] > nw)
				pq.emplace(dst[i.first] = nw, i.first);
		}
	}
	cout << dst[K] << '\n';
	return 0;
}
