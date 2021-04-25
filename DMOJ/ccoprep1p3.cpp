#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair<int, int> pii;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ordered_set oset[100001];
int rnk[100001], sz[100001], par[100001];

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	if ((u = find(u)) == (v = find(v))) return;
	if (sz[u] < sz[v]) swap(u, v);
	sz[u] += sz[v], par[v] = u;
	for (auto i : oset[v]) oset[u].insert(i);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, q, x, y; char op;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) cin >> rnk[i], oset[i].insert({rnk[i], i}), par[i] = i, sz[i] = 1;
	while (M--) cin >> x >> y, join(x, y);

	cin >> q;
	while (q--) {
		cin >> op >> x >> y;
		if (op == 'B') join(x, y);
		else cout << (sz[par[x]] < y ? -1 : oset[par[x]].find_by_order(y - 1)->second) << '\n';
	}
	return 0;
}
