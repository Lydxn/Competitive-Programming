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

vector<pill> adj1[100001], adj2[100001];
int a[200001], b[200001], c[200001]; ll d1[100001], d2[100001];
priority_queue<plli, vector<plli>, greater<plli>> pq;

void solve(int s, vector<pill> adj[100001], ll d[100001]) {
	d[s] = 0, pq.emplace(0LL, s);
	while (!pq.empty()) {
		ll cw = pq.top().first; int cv = pq.top().second; pq.pop();
		if (cw > d[cv]) continue;
		for (auto i : adj[cv]) {
			ll nw = cw + i.second;
			if (nw < d[i.first]) d[i.first] = nw, pq.emplace(nw, i.first);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		adj1[a[i]].emplace_back(b[i], c[i]), adj2[b[i]].emplace_back(a[i], c[i]);
	}

	memset(d1, INFL, sizeof(d1)); memset(d2, INFL, sizeof(d2));
	solve(1, adj1, d1), solve(n, adj2, d2);
	ll ans = INFL;
	for (int i = 0; i < m; i++) ans = min(ans, d1[a[i]] + c[i] / 2 + d2[b[i]]);
	cout << ans << '\n';
	return 0;
}
