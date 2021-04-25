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

int a[200001];
bool vis1[200001], vis2[200001];
ll dp1[200001], dp2[200001];
vector<int> adj1[200001], adj2[200001];

void dfs1(int cur) {
	if (vis1[cur]) return;
	vis1[cur] = true;
	for (int i : adj1[cur])
		dfs1(i), dp1[cur] += dp1[i]; 
}

void dfs2(int cur) {
	if (vis2[cur]) return;
	vis2[cur] = true;
	for (int i : adj2[cur])
		dfs2(i), dp2[cur] += dp2[i]; 
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, u, v; ll ans = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i], dp1[i] = dp2[i] = a[i];
	for (int i = 0; i < N - 1; i++)
		cin >> u >> v, adj1[u].push_back(v), adj2[v].push_back(u);
	for (int i = 1; i <= N; i++) dfs1(i), dfs2(i);
	for (int i = 1; i <= N; i++)
		for (int j : adj1[i])
			ans = max(ans, (dp2[j] - dp2[i]) * (dp1[i] - dp1[j]));
	for (int i = 1; i <= N; i++)
		ans += a[i] * (dp1[i] - 1);
	cout << ans << '\n';
	return 0;
}
