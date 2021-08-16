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

vector<pii> adj[101];
unordered_map<string, int> mp;
queue<int> q;
int dst[101], cost[101], midx;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, c; string s, a, b;
	cin >> n >> m;
	mp["English"] = 0;
	for (int i = 0; i < n; i++) cin >> s, mp[s] = ++midx;
	while (m--) {
		cin >> a >> b >> c;
		adj[mp[a]].emplace_back(mp[b], c), adj[mp[b]].emplace_back(mp[a], c);
	}
	memset(cost, INF, sizeof(cost));
	q.push(0); cost[0] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (auto i : adj[cur]) {
			int nxt = i.first, cc = i.second;
			if (dst[nxt] == dst[cur] + 1 || dst[nxt] == 0) {
				q.push(nxt), dst[nxt] = dst[cur] + 1;
				cost[nxt] = min(cost[nxt], cc);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= midx; i++) {
		if (cost[i] == INF) { cout << "Impossible\n"; return 0; }
		ans += cost[i];
	}
	cout << ans << '\n';
	return 0;
}
