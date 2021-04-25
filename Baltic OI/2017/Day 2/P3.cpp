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

vector<int> adj[200000];
int D, d[200000], dp[200000], tmp[200000];

void dfs(int cur) {
	if (!adj[cur].size()) { d[cur] = dp[cur] = 1; return; }
	for (int i : adj[cur]) dfs(i), dp[cur] += dp[i];

	int tidx = 0;
	for (int i : adj[cur]) tmp[tidx++] = d[i];
	sort(tmp, tmp + tidx, greater<int>());

	int md = tmp[0];
	for (int i = 1; i < tidx; i++) {
		if (tmp[i] + md < D) --dp[cur];
		else md = tmp[i];
	}

	if (md >= D) ++dp[cur], d[cur] = 1;
	else d[cur] = md + 1;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, x;
	cin >> N >> D;
	for (int i = 1; i < N; i++)
		cin >> x, adj[x].push_back(i);

	dfs(0);
	cout << dp[0] << '\n';
	return 0;
}
