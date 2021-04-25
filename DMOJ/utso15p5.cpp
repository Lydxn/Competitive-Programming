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

struct edge {
	int a, b, c;
	bool operator< (const edge &e) { return c < e.c; }
} e[100001];
vector<pii> adj[50001];
int par[50001], sz[50001], h[50001], up[50001][16], cand[100000], cidx;
pii mx[50001][16];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
bool join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return false;
	if (sz[u] < sz[v]) swap(u, v);
	par[v] = u, sz[u] += sz[v];
	return true;
}

pii max2(pii a, pii b) {
	pii res = a;
	if (b.first > res.first) res = {b.first, a.first};
	else if (b.first < res.first && b.first > res.second) res = {a.first, b.first};
	if (b.second > res.second) res.second = b.second;
	return res;
}

void dfs(int cur, int prev, int d) {
	h[cur] = h[prev] + 1, up[cur][0] = prev, mx[cur][0] = {d, 0};
	for (int i = 1; i < 16; i++) {
		int u = up[cur][i - 1];
		up[cur][i] = up[u][i - 1];
		mx[cur][i] = max2(mx[cur][i - 1], mx[u][i - 1]);
	}

	for (auto i : adj[cur])
		if (i.first != prev) dfs(i.first, cur, i.second);
}

pii f(int u, int v) {
	pii ans = {0, 0};
	if (h[u] < h[v]) swap(u, v);
	int diff = h[u] - h[v];
	for (int i = 15; i >= 0; i--)
		if (diff & (1 << i))
			ans = max2(ans, mx[u][i]), u = up[u][i];
	if (u == v) return ans;
	for (int i = 15; i >= 0; i--)
		if (up[u][i] != up[v][i])
			ans = max2(ans, max2(mx[u][i], mx[v][i])), u = up[u][i], v = up[v][i];
	return max2(ans, max2(mx[u][0], mx[v][0]));
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
		cin >> e[i].a >> e[i].b >> e[i].c;
	for (int i = 1; i <= N; i++)
		par[i] = i, sz[i] = 1;

	sort(e, e + M); int mst = 0, cnt = 0;
	for (int i = 0; i < M; i++) {
		if (join(e[i].a, e[i].b)) {
			adj[e[i].a].emplace_back(e[i].b, e[i].c), adj[e[i].b].emplace_back(e[i].a, e[i].c);
			mst += e[i].c, ++cnt;
		} else cand[cidx++] = i;
	}

	if (cnt != N - 1) {
		cout << "-1\n";
		return 0;
	}

	dfs(1, 1, 0); int ans = INT_MAX;
	for (int i = 0; i < cidx; i++) {
		int idx = cand[i];
		pii ab = f(e[idx].a, e[idx].b);
		if (ab.first != e[idx].c) ans = min(ans, mst + e[idx].c - ab.first);
		else if (ab.second) ans = min(ans, mst + e[idx].c - ab.second);
	}
	cout << (ans == INT_MAX ? -1 : ans) << '\n';
	return 0;
}
