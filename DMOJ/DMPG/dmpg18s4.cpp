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
bool A[200001];
ll dp[200001];

void dfs1(int v, int p) {
	dp[v] = A[v];
	for (int i : adj[v]) {
		if (i == p) continue;
		dfs1(i, v);
		if (A[i] ^ A[v]) dp[v] += dp[i];
	}
}

void dfs2(int v, int p) {
	for (int i : adj[v]) {
		if (i == p) continue;
		if (A[i] ^ A[v]) dp[i] = dp[v];
		dfs2(i, v);
	}
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b;
	cin >> N;
	for (int i = 1, x; i <= N; i++) cin >> x, A[i] = x & 1;
	for (int i = 0; i < N - 1; i++)
		cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	dfs1(1, -1), dfs2(1, -1);
	ll ans = 0;
	for (int i = 1; i <= N; i++) ans += dp[i];
	cout << ans << '\n';
	return 0;
}

/*
7
0 2 3 4 5 6 6
1 2
1 3
2 4
2 5
3 6
3 7
*/
