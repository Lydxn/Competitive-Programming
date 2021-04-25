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

const int LG = 16;
vector<pii> adj[100001];
int dep[100001], up[100001][LG + 1], mx[100001][LG + 1], mx2[100001][LG + 1];

void dfs(int cur, int w, int prev, int d) {
	dep[cur] = d, up[cur][0] = prev, mx[cur][0] = w;
	for (int i = 1; i <= LG; i++) {
		up[cur][i] = up[up[cur][i - 1]][i - 1];
		int a = mx[cur][i - 1], b = mx[up[cur][i - 1]][i - 1],
			a2 = mx2[cur][i - 1], b2 = mx2[up[cur][i - 1]][i - 1];
		if (a < b) mx[cur][i] = b, mx2[cur][i] = max(a, b2);
		else       mx[cur][i] = a, mx2[cur][i] = max(a2, b);
	}

	for (auto i : adj[cur])
		if (i.first != prev)
			dfs(i.first, i.second, cur, d + 1);
}

int query(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	int diff = dep[a] - dep[b], ans = 0, ans2 = 0;
	for (int i = LG; i >= 0; i--)
		if (diff & (1 << i)) {
			if (ans < mx[a][i]) ans2 = max(ans, mx2[a][i]), ans = mx[a][i];
			else                ans2 = max(ans2, mx[a][i]);
			a = up[a][i];
		}

	if (a == b) return ans2;

	for (int i = LG; i >= 0; i--)
		if (up[a][i] != up[b][i]) {
			if (ans < mx[a][i]) ans2 = max(ans, mx2[a][i]), ans = mx[a][i];
			else                ans2 = max(ans2, mx[a][i]);
			if (ans < mx[b][i]) ans2 = max(ans, mx2[b][i]), ans = mx[b][i];
			else                ans2 = max(ans2, mx[b][i]);
			a = up[a][i], b = up[b][i];
		}

	// copy paste galore
	if (ans < mx[a][0]) ans2 = max(ans, mx2[a][0]), ans = mx[a][0];
	else                ans2 = max(ans2, mx[a][0]);
	if (ans < mx[b][0]) ans2 = max(ans, mx2[b][0]), ans = mx[b][0];
	else                ans2 = max(ans2, mx[b][0]);
	return ans2;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b, w, s, t;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> w;
		adj[a].emplace_back(b, w), adj[b].emplace_back(a, w);
	}

	dfs(1, 0, 1, 0);

	cin >> Q;
	while (Q--) {
		cin >> s >> t;
		int qu = query(s, t);
		cout << (qu == 0 ? -1 : qu) << '\n';
	}
	return 0;
}
