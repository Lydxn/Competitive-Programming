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
int dp0[100001], dp1[100001];
bool vis[100001];

void dfs(int cur, int prev) {
	vis[cur] = true;
	int s = 0, mx = 0, mx2 = 0, cnt = 0;
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur), s += dp0[i], ++cnt;
		if (dp0[i] - dp1[i] > mx) mx2 = mx, mx = dp0[i] - dp1[i];
		else if (dp0[i] - dp1[i] > mx2) mx2 = dp0[i] - dp1[i];
	}
	dp0[cur] = s - mx - mx2 + 1, dp1[cur] = s - mx;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T, N, M, a, b;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		while (M--) {
			cin >> a >> b;
			adj[a].push_back(b), adj[b].push_back(a);
		}
		memset(vis, false, sizeof(vis));
		int ans = 0;
		for (int i = 1; i <= N; i++)
			if (!vis[i]) dfs(i, 0), ans += dp0[i];
		for (int i = 1; i <= N; i++) adj[i].clear();
		cout << N + ans - 1 << '\n';
	}
	return 0;
}
