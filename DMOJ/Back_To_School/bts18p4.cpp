#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pair<int, int>, int> piii;

const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 1e9 + 7;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

ll y[100001];
bool vis[100001];
vector<int> adj[100001];

bool good(int x) {
	ll sq = sqrt(y[x]);
	return sq * sq + sq == y[x];
}

void dfs(int cur, int prev, int d, int &mxd, int &mxi) {
	if (d > mxd) mxd = d, mxi = cur;
	vis[cur] = true;

	for (int i : adj[cur])
		if (i != prev && good(i))
			dfs(i, cur, d + 1, mxd, mxi);
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, a, b;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> y[i];
	for (int i = 0; i < N - 1; i++) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (!vis[i] && good(i)) {
			int mxd = 0, mxi = -1;
			dfs(i, -1, 1, mxd, mxi);
			dfs(mxi, -1, 1, mxd = 0, mxi);
			ans = max(ans, mxd);
		}
	}
	cout << ans << '\n';
	return 0;
}
