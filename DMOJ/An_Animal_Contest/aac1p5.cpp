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

vector<pii> adj[200001];
int N, o[200001], n[200001];
ll cnt[200001];

void dfs(int cur, int prev, int d) {
	n[cur] = 1;
	for (auto i : adj[cur]) {
		if (i.first != prev) {
			o[i.first] = o[cur] ^ (i.second % 2);
			dfs(i.first, cur, d + i.second);
			n[cur] += n[i.first];
		}
	}
	cnt[cur] = o[cur];
	for (auto i : adj[cur])
		if (i.first != prev) cnt[cur] += cnt[i.first];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int u, v, w;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	dfs(1, 0, 0);
	ll ans = abs(1LL * N * (N - 1) / 2 - cnt[1] * (N - cnt[1]) * 2);
	for (int i = 2; i <= N; i++) {
		ll x = cnt[1] + n[i] - 2 * cnt[i];
		ans = min(ans, abs(1LL * N * (N - 1) / 2 - x * (N - x) * 2));
	}
	cout << ans << '\n';
	return 0;
}