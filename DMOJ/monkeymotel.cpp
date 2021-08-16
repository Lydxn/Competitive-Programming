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

vector<int> adj[300001];
set<int> ss[300001];
int mex[300001], sz[300001];
ll ans[300002];

void dfs(int cur, int prev) {
	mex[cur] = sz[cur] = 1;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur);
		if (ss[cur].size() < ss[i].size()) swap(ss[cur], ss[i]);
		ss[cur].insert(ss[i].begin(), ss[i].end()), ss[i].clear();
		mex[cur] = max(mex[cur], mex[i]), sz[cur] += sz[i];
	}
	while (ss[cur].count(mex[cur])) ++mex[cur];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, X, a, u, v;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> a, ss[i].insert(a);
	for (int i = 0; i < N - 1; i++) {
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	dfs(1, 0); memset(ans, INF, (N + 2) << 3);
	for (int i = 1; i <= N; i++) ans[mex[i]] = min(ans[mex[i]], (ll) sz[i] << 19 | i);
	for (int i = N; i; i--) ans[i] = min(ans[i], ans[i + 1]);
	while (Q--) cin >> X, cout << (X > N + 1 || ans[X] == INFL ? -1 : ans[X] & 524287) << '\n';
}