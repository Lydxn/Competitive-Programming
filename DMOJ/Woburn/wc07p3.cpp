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
const int MOD = 13371337;

template <class T, class C = less<T>>
using ordered_set = tree<T, null_type, C, rb_tree_tag, tree_order_statistics_node_update>;

int N, g[15][15], dp[15][1 << 15];

int dfs(int cur, int vis) {
	if (cur == N - 1) return 1;
	if (dp[cur][vis] != -1) return dp[cur][vis];
	int res = 0;
	for (int i = 0; i < N; i++)
		if (g[cur][i] && !(vis & 1 << i))
			res = (res + dfs(i, vis | 1 << i)) % MOD;
	return dp[cur][vis] = res;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> g[i][j];
		memset(dp, -1, sizeof(dp));
		cout << dfs(0, 1) << '\n';
	}
	return 0;
}
