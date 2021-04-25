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

int p[100001], uu[100000], vv[100000], qa[100001], qb[100001], qk[100001], ans[100001];
int par[100001], sz[100001], dep[100001], up[100001][17], mx[100001][17];
bool rm[100001];
vector<int> adj[100001];
pii r[100000];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v], par[v] = u;
}

void dfs(int cur, int prev) {
	up[cur][0] = prev, mx[cur][0] = p[cur], dep[cur] = dep[prev] + 1;
	for (int i = 1; i < 17; i++) {
		up[cur][i] = up[up[cur][i - 1]][i - 1];
		mx[cur][i] = max(mx[cur][i - 1], mx[up[cur][i - 1]][i - 1]);
	}
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur);
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	int diff = dep[a] - dep[b];
	for (int i = 0; i < 17; i++)
		if (diff & (1 << i)) a = up[a][i];
	if (a == b) return a;
	for (int i = 16; i >= 0; i--)
		if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
	return up[a][0];
}

int query(int a, int b, int k) {
	int ab = lca(a, b);

	int diffa = dep[a] - dep[ab];
	for (int i = 16; i >= 0; i--)
		if ((1 << i) <= diffa && mx[a][i] < k) a = up[a][i], diffa -= 1 << i;
	if (p[a] >= k) return a;

	// plz tell me there's a better way to binary lift backwards
	int diffb = dep[b] - dep[ab], lg = __lg(diffb), c = b;
	for (int i = lg - 1; i >= 0; i--)
		if (diffb & (1 << i)) c = up[c][i];
		
	for (int i = lg - 1; i >= 0; i--)
		if (mx[up[c][i]][i] >= k) c = up[c][i];
	if (p[c] >= k) return c;
	
	for (int i = lg - 1; i >= 0; i--)
		if (mx[up[b][i]][i] >= k) b = up[b][i];
	if (p[b] >= k) return b;

	return -1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, R;
	cin >> N >> Q >> R;
	for (int i = 1; i <= N; i++) cin >> p[i], par[i] = i, sz[i] = 1;
	for (int i = 1; i < N; i++) {
		cin >> uu[i] >> vv[i];
		adj[uu[i]].push_back(vv[i]), adj[vv[i]].push_back(uu[i]);
	}

	for (int i = 0; i < R; i++) cin >> r[i].first >> r[i].second, rm[r[i].second] = true;
	sort(r, r + R);
	for (int i = 1; i < N; i++)
		if (!rm[i]) join(uu[i], vv[i]);

	dfs(1, 0);
	for (int i = 1; i <= Q; i++) cin >> qa[i] >> qb[i] >> qk[i];
	for (int i = Q, j = R - 1; i; i--) {
		while (j >= 0 && r[j].first == i) join(uu[r[j].second], vv[r[j].second]), --j;
		ans[i] = find(qa[i]) == find(qb[i]) ? query(qa[i], qb[i], qk[i]) : -1;
	}

	for (int i = 1; i <= Q; i++) cout << ans[i] << '\n';
	return 0;
}
