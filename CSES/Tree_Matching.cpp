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
int dp1[200001], dp2[200001];

void dfs(int cur, int prev) {
	for (int i : adj[cur]) {
		if (i == prev) continue;
		dfs(i, cur);
		dp2[cur] += max(dp1[i], dp2[i]);
	}
	for (int i : adj[cur])
		if (i != prev)
			dp1[cur] = max(dp1[cur], dp2[cur] - max(dp1[i], dp2[i]) + dp2[i] + 1);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a);
	}

	dfs(1, -1);
	cout << max(dp1[1], dp2[1]) << '\n';
	return 0;
}
