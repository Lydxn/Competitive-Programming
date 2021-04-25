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

int c[300001];
ll dp[32][300001];
vector<int> adj[300001];

ll solve(int msk, int cur) {
	if (dp[msk][cur] != -1) return dp[msk][cur];
	ll res = 1;
	for (int i : adj[cur])
		if (!(msk & (1 << c[i]))) res += solve(msk | (1 << c[i]), i);
	return dp[msk][cur] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, a, b;
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) cin >> c[i], --c[i]  ;
	while (M--) cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);

	ll ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= N; i++) ans += solve(1 << c[i], i);
	cout << ans - N << '\n';
	return 0;
}
