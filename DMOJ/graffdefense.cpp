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

int vv[2000001], vcur[1000001], vnxt[2000001], vidx = 1;
int in[1000001], low[1000001], par[1000001], sz[1000001], cnt[1000001], timer;
bool vis[1000001];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
}

void dfs(int cur, int prev) {
	vis[cur] = true, in[cur] = low[cur] = timer++;
	for (int i = vcur[cur]; i; i = vnxt[i]) {
		int v = vv[i];
		if (v == prev) continue;
		if (vis[v]) low[cur] = min(low[cur], in[v]);
		else {
			dfs(v, cur);
			low[cur] = min(low[cur], low[v]);
			if (low[v] <= in[cur]) join(cur, v);
		}
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, A, B;
	cin >> N >> M;
	while (M--) {
		cin >> A >> B;
		vv[vidx] = B, vnxt[vidx] = vcur[A], vcur[A] = vidx++;
		vv[vidx] = A, vnxt[vidx] = vcur[B], vcur[B] = vidx++;
	}

	for (int i = 1; i <= N; i++) par[i] = i, sz[i] = 1;
	dfs(1, -1);

	ll ans = 0;
	for (int i = 1; i <= N; i++) ++cnt[find(i)];
	for (int i = 1; i <= N; i++) ans += (ll) cnt[i] * (N - cnt[i]);

	cout << fixed << setprecision(5) << (double) ans / ((ll) N * (N - 1)) << '\n';
	return 0;
}
