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

vector<pii> adj[1 << 18];
int mx;

void dfs(int cur, int s = 0) {
	mx = max(mx, s);
	for (auto [v, w]: adj[cur])
		dfs(v, s + w);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, R, u, v, w, D;
	cin >> N >> R;
	for (int i = 0; i < (1 << N) - 1; i++) {
		cin >> u >> v >> w >> D;
		adj[u].emplace_back(v, D), adj[u].emplace_back(w, 0);
	}
	dfs(1);
	cout << R + mx << '\n';
	return 0;
}