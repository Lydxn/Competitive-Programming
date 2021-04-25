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

vector<int> adj[100001];
int clr[100001];

void dfs(int cur, bool c) {
	if (clr[cur] && clr[cur] != c + 1) { cout << "IMPOSSIBLE\n"; exit(0); }
	if (clr[cur]) return;
	clr[cur] = c + 1;
	for (int i : adj[cur]) dfs(i, c ^ 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!clr[i]) dfs(i, false);
	for (int i = 1; i <= n; i++) cout << clr[i] << ' ';
	cout << '\n';
	return 0;
}
