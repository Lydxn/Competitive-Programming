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

vector<int> adj[200001];
ll bit[400001];
int n, v[200001], in[200001], out[200001], timer;

void update(int i, int x) {
	for (; i <= 2 * n; i += i & -i) bit[i] += x;
}

ll query(int i) {
	ll res = 0;
	for (; i; i -= i & -i) res += bit[i];
	return res;
}

void dfs(int cur, int prev) {
	in[cur] = ++timer;
	for (int i : adj[cur])
		if (i != prev) dfs(i, cur);
	out[cur] = ++timer;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int q, op, a, b;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> v[i];
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) update(in[i], v[i]), update(out[i], -v[i]);
	while (q--) {
		cin >> op;
		if (op == 1) cin >> a >> b, update(in[a], b - v[a]), update(out[a], v[a] - b), v[a] = b;
		else cin >> a, cout << query(in[a]) << '\n';
	}
	return 0;
}
