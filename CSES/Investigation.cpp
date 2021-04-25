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
ll d[100001];
int cnt[100001], mn[100001], mx[100001];

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b, c;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c);
	}

	memset(d, INFL, sizeof(d));
	d[1] = 0, cnt[1] = 1, pq.emplace(0, 1);
	while (!pq.empty()) {
		ll w = pq.top().first; int v = pq.top().second; pq.pop();
		if (d[v] < w) continue;
		for (auto i : adj[v]) {
			ll nw = w + i.second;
			if (d[i.first] > nw) {
				pq.emplace(d[i.first] = nw, i.first);
				cnt[i.first] = cnt[v];
				mn[i.first] = mn[v] + 1;
				mx[i.first] = mx[v] + 1;
			} else if (d[i.first] == nw) {
				cnt[i.first] = (cnt[i.first] + cnt[v]) % MOD;
				mn[i.first] = min(mn[i.first], mn[v] + 1);
				mx[i.first] = max(mx[i.first], mx[v] + 1);
			}
		}
	}
	cout << d[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n] << '\n';
	return 0;
}
