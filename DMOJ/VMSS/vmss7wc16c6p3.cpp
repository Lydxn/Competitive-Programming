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
bool vis[100001];
int cnt, a[100001], in[100001], low[100001], timer;

void dfs(int cur, int prev) {
	in[cur] = low[cur] = ++timer, vis[cur] = true;
	int child = 0;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		if (vis[i]) low[cur] = min(low[cur], in[i]);
		else {
			dfs(i, cur), low[cur] = min(low[cur], low[i]), ++child;
			if (low[i] >= in[cur] && !a[cur] && cur != 1) a[cur] = true, ++cnt;
		}
	}
	if (cur == 1 && child > 1) a[1] = true, ++child, ++cnt;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, x, y;
	cin >> N >> M;
	while (M--) {
		cin >> x >> y;
		adj[x].push_back(y), adj[y].push_back(x);
	}
	
	dfs(1, -1);
	cout << cnt << '\n';
	for (int i = 1; i <= N; i++)
		if (a[i]) cout << i << '\n';
	return 0;
}
