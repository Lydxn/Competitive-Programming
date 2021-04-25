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

vector<pii> adj[1000001];
ll ans; int n;

int dfs(int cur, int prev, int c) {
	int w = 1;
	for (auto i : adj[cur])
		if (i.first != prev) w += dfs(i.first, cur, i.second);
	ans += (ll) abs(2 * w - n) * c;
	return w;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c), adj[b].emplace_back(a, c);
	}

	dfs(1, -1, 0);
	cout << ans << '\n';
	return 0;
}
