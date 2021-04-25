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

int A[100000], B[100000], Z[100000], P[100000], X[100001], par[100000];
ll ans[100000], yay;
vector<pii> adj[100001];
vector<int> sz[100001];
unordered_map<int, int> cnt[100001];

void dfs(int cur, int prev, int x) {
	X[cur] = x;
	for (auto i : adj[cur])
		if (i.first != prev) dfs(i.first, cur, x ^ i.second);
}

int find(int v) { return v == par[v] ? v : par[v] = find(par[v]); }
void join(int u, int v) {
	u = find(u), v = find(v);
	if (sz[u].size() < sz[v].size()) swap(u, v);
	for (int i : sz[v]) yay += cnt[u][X[i]];
	for (int i : sz[v]) ++cnt[u][X[i]];
	sz[u].insert(sz[u].end(), sz[v].begin(), sz[v].end()), par[v] = u;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> A[i] >> B[i] >> Z[i];
		adj[A[i]].emplace_back(B[i], Z[i]), adj[B[i]].emplace_back(A[i], Z[i]);
	}
	dfs(1, -1, 0);
 	for (int i = 1; i <= N; i++) par[i] = i, sz[i].push_back(i), cnt[i][X[i]] = 1;
	for (int i = 0; i < N - 1; i++) cin >> P[i];
	for (int i = N - 2; i >= 0; i--)
		join(A[P[i]], B[P[i]]), ans[i] = yay;
	for (int i = 0; i < N; i++) cout << ans[i] << '\n';
	return 0;
}
