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

vector<int> adj[100001], top;
int col[100001];

void dfs(int cur) {
	if (col[cur] == 1) { cout << "IMPOSSIBLE\n"; exit(0); }
	if (col[cur] == 2) return;
	col[cur] = 1;
	for (int i : adj[cur]) dfs(i);
	col[cur] = 2, top.push_back(cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) dfs(i);
	for (int i = n - 1; i >= 0; i--) cout << top[i] << ' ';
	cout << '\n';
	return 0;
}
