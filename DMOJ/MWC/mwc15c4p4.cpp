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

vector<int> adj[1001];
bool vis[1001];

void dfs(int cur) {
	if (vis[cur]) return;
	vis[cur] = true;
	for (int i : adj[cur]) dfs(i);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b;
	cin >> N;
	while (N--) cin >> a >> b, adj[a].push_back(b);
	cin >> a >> b; dfs(a);
	cout << (vis[b] ? "Tangled" : "Not Tangled") << '\n';
	return 0;
}
