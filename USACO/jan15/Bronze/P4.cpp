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

int N, M, A, B, C, D, adj1[17][17], adj2[17][17];
bool vis1[16001], vis2[16001];

void dfs(int v, int d, int adj[17][17], bool vis[16001]) {
	if (v == N) vis[d] = true;
	else {
		for (int i = 1; i <= N; i++)
			if (adj[v][i]) dfs(i, d + adj[v][i], adj, vis);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	freopen("meeting.in", "r", stdin);
	freopen("meeting.out", "w", stdout);

	cin >> N >> M;
	while (M--) {
		cin >> A >> B >> C >> D;
		adj1[A][B] = C, adj2[A][B] = D;
	}

	dfs(1, 0, adj1, vis1); dfs(1, 0, adj2, vis2);
	for (int i = 0; i <= 16000; i++)
		if (vis1[i] && vis2[i]) { cout << i << '\n'; return 0; }
	cout << "IMPOSSIBLE\n";
	return 0;
}
