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

int adj[2][1000001], asz[1000001];
bool vis[1000001];
int nodes, edges;

void dfs(int cur, int prev) {
	vis[cur] = true, ++nodes;
	for (int i = 0; i < 2; i++) {
		int v = adj[i][cur];
		if (!v) continue;
		if (!vis[v]) dfs(v, cur);
		++edges;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, A, B, ans1 = 0, ans2 = 0;
	cin >> N >> M >> K;
	while (M--) {
		cin >> A >> B;
		adj[asz[A]++][A] = B, adj[asz[B]++][B] = A;
	}
	
	for (int i = 1; i <= N; i++) {
		if (!vis[i]) {
			nodes = edges = 0, dfs(i, -1), edges >>= 1;
			ans1 += nodes / K * K, ans2 += (nodes - 1) / K + (nodes > K && nodes == edges);
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}

