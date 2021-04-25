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
int BIT[400001], euler[400001], u[200001], v[200001], in[200001], out[200001], dep[200001], p[200001], d[200001];
int eidx, bad;

int query(int i) {
	int res = 0;
	for (; i; i -= i & -i) res += BIT[i];
	return res;
}

void update(int i, int v) {
	for (; i <= 400000; i += i & -i) BIT[i] += v;
}

void dfs(int cur, int prev, int d) {
	dep[cur] = d, euler[++eidx] = cur;
	for (auto i : adj[cur])
		if (i.first != prev)
			p[i.first] = p[cur] + i.second, dfs(i.first, cur, d + 1), bad += i.second == -1;
	euler[++eidx] = cur;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, Q, a, b;
	cin >> N >> Q;
	for (int i = 1; i < N; i++) {
		cin >> u[i] >> v[i];
		adj[u[i]].emplace_back(v[i], 1), adj[v[i]].emplace_back(u[i], -1);
	}

	dfs(1, -1, 0);
	memset(in, INF, sizeof(in));
	for (int i = 1; i <= eidx; i++)
		in[euler[i]] = min(in[euler[i]], i), out[euler[i]] = i;

	for (int i = 1; i < N; i++)
		d[i] = dep[u[i]] < dep[v[i]] ? 1 : -1;

	while (Q--) {
		cin >> a >> b;
		if (a == 1) cout << bad + p[b] + query(in[b]) << '\n';
		else {
			int dir = d[b], q = dep[u[b]] < dep[v[b]] ? v[b] : u[b];
			bad += dir, update(in[q], -2 * dir), update(out[q], 2 * dir);
			d[b] *= -1;
		}
	}
	return 0;
}
