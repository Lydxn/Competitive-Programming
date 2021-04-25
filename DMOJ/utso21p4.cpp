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

vector<pii> adj[200001];
bool vis[200001], ans[200001];
int deg[200001], gcnt, res;

void dfs(int cur) {
	vis[cur] = true;
	for (auto i : adj[cur]) {
		if (vis[i.first]) continue;
		dfs(i.first);
		if (deg[i.first] % 2 == 0) --deg[cur], --deg[i.first], ans[i.second] = true, ++gcnt;
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> a >> b;
		adj[a].emplace_back(b, i), adj[b].emplace_back(a, i);
	}

	for (int i = 1; i <= N; i++) deg[i] = adj[i].size();
	for (int i = 1; i <= N; i++) if (!vis[i]) dfs(i);
	for (int i = 1; i <= N; i++) res += deg[i] % 2;
	cout << res << '\n' << gcnt << '\n';
	for (int i = 1; i <= M; i++)
		if (ans[i]) cout << i << ' ';
	cout << '\n';
	return 0;
}
