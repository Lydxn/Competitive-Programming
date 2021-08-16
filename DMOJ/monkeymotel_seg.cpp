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

const int MN = 300001, SEG = 1 << 19;
vector<int> adj[MN];
int a[MN], seg[SEG << 1], mex[MN], sz[MN], val[MN], in[MN], r[MN], ti;
ll ans[MN + 1];

void dfs(int cur, int prev) {
	in[cur] = ++ti, val[ti] = a[cur], sz[cur] = 1;
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur), sz[cur] += sz[i];
	r[in[cur]] = ti;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, X, u, v;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a[i];
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(1, 0);
	int segz = SEG;
	while ((segz >> 1) > N + 1) segz >>= 1;
	memset(seg, INF, segz << 3);
	for (int i = N, si; i; i--) {
		if (val[i] <= N + 1)
			for (seg[si = segz - 1 + val[i]] = i; si >>= 1; seg[si] = max(seg[si << 1], seg[si << 1 | 1]));
		for (si = 1; si < segz; si = (si << 1) | (seg[si << 1] <= r[i]));
		mex[i] = si - segz + 1;
	}
	memset(ans, INF, sizeof(ans));
	for (int i = 1; i <= N; i++) ans[mex[in[i]]] = min(ans[mex[in[i]]], (ll) sz[i] << 19 | i);
	for (int i = N; i; i--) ans[i] = min(ans[i], ans[i + 1]);
	while (Q--) cin >> X, cout << (X > N + 1 || ans[X] == INFL ? -1 : ans[X] & 524287) << '\n';
	return 0;
}
