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
int dp[200001];

void dfs(int cur) {
	dp[cur] = 1;
	for (int i : adj[cur]) dfs(i), dp[cur] += dp[i];
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	cin >> n;
	for (int i = 2; i <= n; i++) cin >> x, adj[x].push_back(i);
	dfs(1);
	for (int i = 1; i <= n; i++) cout << dp[i] - 1 << ' ';
	cout << '\n';
	return 0;
}
