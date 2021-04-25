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
set<int> ss[200001];
int ans[200001];

void dfs(int cur, int prev) {
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur);
		if (ss[i].size() > ss[cur].size()) swap(ss[cur], ss[i]);
		ss[cur].insert(ss[i].begin(), ss[i].end());
	}
	ans[cur] = ss[cur].size();
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b, c;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c, ss[i].insert(c);
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << '\n';
	return 0;
}
