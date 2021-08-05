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

vector<pii> adj[100001];
int dp[100001];

void dfs(int cur, int prev) {
	for (auto i : adj[cur])
		if (i.first != prev) dp[i.first] = dp[cur] + i.second, dfs(i.first, cur);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b, c, s = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		adj[a].emplace_back(b, c), adj[b].emplace_back(a, c), s += c;
	}
	dfs(0, 0);
	int mx = 0;
	for (int i = 1; i <= N; i++) mx = max(mx, dp[i]);
	cout << 2 * s - mx << '\n';
	return 0;
}
