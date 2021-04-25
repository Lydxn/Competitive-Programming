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

vector<pii> adj[100001];
priority_queue<plli, vector<plli>, greater<plli>> pq;
ll d[100001][10];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, k, a, b, c;
	cin >> n >> m >> k;
	while (m--) cin >> a >> b >> c, adj[a].emplace_back(b, c);

	memset(d, INFL, sizeof(d)); pq.emplace(d[1][0] = 0, 1);
	while (!pq.empty()) {
		ll w = pq.top().first; int v = pq.top().second; pq.pop();
		if (d[v][k - 1] < w) continue;
		for (auto i : adj[v]) {
			if (w + i.second < d[i.first][k - 1]) {
				pq.emplace(d[i.first][k - 1] = w + i.second, i.first);
				int t = k - 1;
				while (t && d[i.first][t] < d[i.first][t - 1])
					swap(d[i.first][t], d[i.first][t - 1]), --t;
			}
		}
	}

	for (int i = 0; i < k; i++) cout << d[n][i] << ' ';
	cout << '\n';
	return 0;
}
